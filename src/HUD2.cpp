/*
 ============================================================================
 Name        : HUD.cpp
 Author      : Erin Lee
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C++,
 ============================================================================
 */



#include "header.h"
#include "HeadsUpBatteryInfo.h"
#include "HeadsUpCheckBox.h"
#include "HeadsUpDigitalClock.h"
#include "TileBuilder.h"
#include "HeadsUpMap.h"
#include "HeadsUpObjective.h"
#include "HeadsUpTask.h"
#include "Timer.hpp"

enum MODE
{
	MODE_CPU = 0,
	MODE_GPU
};

#include "HeadsUpInterface.h"



int width, height;
Display *Xdisplay;
GC gc;
Window Xroot, window_handle;
cv::VideoCapture   m_cap;
int Xscreen;
int mkk;
Atom del_atom;
Colormap cmap;
XVisualInfo *visual;
XRenderPictFormat *pict_format;
GLXFBConfig *fbconfigs, fbconfig;
int numfbconfigs;
GLXContext render_context;
GLXWindow glX_window_handle;
cv::Mat            m_frame_bgr;
cv::Mat            m_frame_rgba;
cv::String         m_oclDevName;

HeadsUpInterface interface;

//Task Management Subsystem
std::list<HeadsUpTask> tasks;
std::list<HeadsUpObjective> current_objectives;
extern void	computerGetLocalTime();


//Power Management Subsystem
std::string battery_state;
std::atomic<double> battery_life;
std::atomic<double> dev_battery_life;
std::atomic<bool> is_charging;
std::atomic<bool> dev_is_charging;
std::atomic<bool> dev_is_connected;
extern void computerGetBatteryInformation();


//Map Subsystem
std::atomic<double> m_latitude;
std::atomic<double> m_longitude;
std::pair<double,double> coords;




static int VisData[] = {
		GLX_RENDER_TYPE, GLX_RGBA_BIT,
		GLX_DRAWABLE_TYPE, GLX_WINDOW_BIT,
		GLX_DOUBLEBUFFER, True,
		GLX_RED_SIZE, 8,
		GLX_GREEN_SIZE, 8,
		GLX_BLUE_SIZE, 8,
		GLX_ALPHA_SIZE, 8,
		GLX_DEPTH_SIZE, 16,
		None
};

static void fatalError(const char *why)
{
	fprintf(stderr, "%s", why);
	exit(0x666);
}



static int isExtensionSupported(const char *extList, const char *extension)
{

	const char *start;
	const char *where, *terminator;

	/* Extension names should not have spaces. */
	where = strchr(extension, ' ');
	if ( where || *extension == '\0' )
		return 0;

	/* It takes a bit of care to be fool-proof about parsing the
     OpenGL extensions string. Don't be fooled by sub-strings,
     etc. */
	for ( start = extList; ; ) {
		where = strstr( start, extension );

		if ( !where )
			break;

		terminator = where + strlen( extension );

		if ( where == start || *(where - 1) == ' ' )
			if ( *terminator == ' ' || *terminator == '\0' )
				return 1;

		start = terminator;
	}
	return 0;
}



static Bool WaitForMapNotify(Display *d, XEvent *e, char *arg)
{
	return d && e && arg && (e->type == MapNotify) && (e->xmap.window == *(Window*)arg);
}


static void describe_fbconfig(GLXFBConfig fbconfig)
{
	int doublebuffer;
	int red_bits, green_bits, blue_bits, alpha_bits, depth_bits;

	glXGetFBConfigAttrib(Xdisplay, fbconfig, GLX_DOUBLEBUFFER, &doublebuffer);
	glXGetFBConfigAttrib(Xdisplay, fbconfig, GLX_RED_SIZE, &red_bits);
	glXGetFBConfigAttrib(Xdisplay, fbconfig, GLX_GREEN_SIZE, &green_bits);
	glXGetFBConfigAttrib(Xdisplay, fbconfig, GLX_BLUE_SIZE, &blue_bits);
	glXGetFBConfigAttrib(Xdisplay, fbconfig, GLX_ALPHA_SIZE, &alpha_bits);
	glXGetFBConfigAttrib(Xdisplay, fbconfig, GLX_DEPTH_SIZE, &depth_bits);

	fprintf(stderr, "FBConfig selected:\n"
			"Doublebuffer: %s\n"
			"Red Bits: %d, Green Bits: %d, Blue Bits: %d, Alpha Bits: %d, Depth Bits: %d\n",
			doublebuffer == True ? "Yes" : "No",
					red_bits, green_bits, blue_bits, alpha_bits, depth_bits);
}

static void createTheWindow()
{
	int x,y, attr_mask;
	XSizeHints hints;
	XWMHints *startup_state;
	XTextProperty textprop;
	XSetWindowAttributes attr = {0,};

	Xdisplay = XOpenDisplay(NULL);
	if (!Xdisplay) {
		fatalError("Couldn't connect to X server\n");
	}
	Xscreen = DefaultScreen(Xdisplay);
	Xroot = RootWindow(Xdisplay, Xscreen);

	fbconfigs = glXChooseFBConfig(Xdisplay, Xscreen, VisData, &numfbconfigs);
	fbconfig = 0;
	for(int i = 0; i<numfbconfigs; i++) {
		visual = (XVisualInfo*) glXGetVisualFromFBConfig(Xdisplay, fbconfigs[i]);
		if(!visual)
			continue;

		pict_format = XRenderFindVisualFormat(Xdisplay, visual->visual);
		if(!pict_format)
			continue;

		fbconfig = fbconfigs[i];
		if(pict_format->direct.alphaMask > 0) {
			break;
		}
	}

	if(!fbconfig) {
		fatalError("No matching FB config found");
	}

	describe_fbconfig(fbconfig);

	/* Create a colormap - only needed on some X clients, eg. IRIX */
	cmap = XCreateColormap(Xdisplay, Xroot, visual->visual, AllocNone);

	attr.colormap = cmap;
	attr.background_pixmap = None;
	attr.border_pixmap = None;
	attr.border_pixel = 0;
	attr.event_mask =
			StructureNotifyMask |
			EnterWindowMask |
			LeaveWindowMask |
			ExposureMask |
			ButtonPressMask |
			ButtonReleaseMask |
			OwnerGrabButtonMask |
			KeyPressMask |
			KeyReleaseMask;

	attr_mask =
			CWBackPixmap|
			CWColormap|
			CWBorderPixel|
			CWEventMask;

	width = DisplayWidth(Xdisplay, DefaultScreen(Xdisplay));
	height = DisplayHeight(Xdisplay, DefaultScreen(Xdisplay));
	x=width, y=height;

	window_handle = XCreateWindow(  Xdisplay,
			Xroot,
			x, y, width, height,
			0,
			visual->depth,
			InputOutput,
			visual->visual,
			attr_mask, &attr);

	if( !window_handle ) {
		fatalError("Couldn't create the window\n");
	}

#if USE_GLX_CREATE_WINDOW
	int glXattr[] = { None };
	glX_window_handle = glXCreateWindow(Xdisplay, fbconfig, window_handle, glXattr);
	if( !glX_window_handle ) {
		fatalError("Couldn't create the GLX window\n");
	}
#else
	glX_window_handle = window_handle;
#endif

	textprop.value = (unsigned char*)"";
	textprop.encoding = XA_STRING;
	textprop.format = 8;
	textprop.nitems = 0;

	hints.x = x;
	hints.y = y;
	hints.width = width;
	hints.height = height;
	hints.flags = USPosition|USSize;

	startup_state = XAllocWMHints();
	startup_state->initial_state = NormalState;
	startup_state->flags = StateHint;

	XSetWMProperties(Xdisplay, window_handle,&textprop, &textprop,
			NULL, 0,
			&hints,
			startup_state,
			NULL);

	XFree(startup_state);

	XMapWindow(Xdisplay, window_handle);
	//XIfEvent(Xdisplay, &event, WaitForMapNotify, (char*)&window_handle);

	if ((del_atom = XInternAtom(Xdisplay, "WM_DELETE_WINDOW", 0)) != None) {
		XSetWMProtocols(Xdisplay, window_handle, &del_atom, 1);
	}
}

static int ctxErrorHandler( Display *dpy, XErrorEvent *ev )
{
	fputs("Error at context creation", stderr);
	return 0;
}



static void createTheRenderContext()
{
	int dummy;
	if (!glXQueryExtension(Xdisplay, &dummy, &dummy)) {
		fatalError("OpenGL not supported by X server\n");
	}

#if USE_GLX_CREATE_CONTEXT_ATTRIB
#define GLX_CONTEXT_MAJOR_VERSION_ARB       0x2091
#define GLX_CONTEXT_MINOR_VERSION_ARB       0x2092
	render_context = NULL;
	if( isExtensionSupported( glXQueryExtensionsString(Xdisplay, DefaultScreen(Xdisplay)), "GLX_ARB_create_context" ) ) {
		typedef GLXContext (*glXCreateContextAttribsARBProc)(Display*, GLXFBConfig, GLXContext, Bool, const int*);
		glXCreateContextAttribsARBProc glXCreateContextAttribsARB = (glXCreateContextAttribsARBProc)glXGetProcAddressARB( (const GLubyte *) "glXCreateContextAttribsARB" );
		if( glXCreateContextAttribsARB ) {
			int context_attribs[] =
			{
					GLX_CONTEXT_MAJOR_VERSION_ARB, 3,
					GLX_CONTEXT_MINOR_VERSION_ARB, 0,
					//GLX_CONTEXT_FLAGS_ARB        , GLX_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB,
					None
			};

			int (*oldHandler)(Display*, XErrorEvent*) = XSetErrorHandler(&ctxErrorHandler);

			render_context = glXCreateContextAttribsARB( Xdisplay, fbconfig, 0, True, context_attribs );

			XSync( Xdisplay, False );
			XSetErrorHandler( oldHandler );

			fputs("glXCreateContextAttribsARB failed", stderr);
		} else {
			fputs("glXCreateContextAttribsARB could not be retrieved", stderr);
		}
	} else {
		fputs("glXCreateContextAttribsARB not supported", stderr);
	}

	if(!render_context)
	{
#else
		{
#endif
			render_context = glXCreateNewContext(Xdisplay, fbconfig, GLX_RGBA_TYPE, 0, True);
			if (!render_context) {
				fatalError("Failed to create a GL context\n");
			}
		}

		if (!glXMakeContextCurrent(Xdisplay, glX_window_handle, glX_window_handle, render_context)) {
			fatalError("glXMakeCurrent failed for window\n");
		}
	}

static int updateTheMessageQueue()
{
	while( XPending(Xdisplay)>0){
		XEvent   event ;
		XNextEvent( Xdisplay, &event) ;

		switch(event.type)
		{  // see 'man XAnyEvent' for a list of available events
		case ClientMessage:
			// check if the client message was send by window manager to indicate user wants to close the window
			if (  event.xclient.message_type  == XInternAtom( Xdisplay, "WM_PROTOCOLS", 1)
					&& event.xclient.data.l[0]  == (unsigned int)XInternAtom( Xdisplay, "WM_DELETE_WINDOW", 1)
			)
			{
				return 0 ;
			}
			break;
		case KeyPress:
			if (XLookupKeysym(&event.xkey, 0) == XK_Escape)
			{
				return 0 ;
			}
			if (XLookupKeysym(&event.xkey, 0) == XK_Right)
			{
				interface.makeActiveTask(tasks.back());
			}
			if (XLookupKeysym(&event.xkey, 0) == XK_Left)
			{
				tasks.front().objectives.at(0).toggle();
			}

			break ;
		case Expose:
			return 1;
			break ;
		default:
			// do nothing
			break ;
		}
	}
	//return 0;
}

static void redrawTheWindow()
{
	std::thread _bat_th(computerGetBatteryInformation);
	std::thread _clk_th(computerGetLocalTime);

	XWindowAttributes window_attributes;
	XGetWindowAttributes(Xdisplay, window_handle, &window_attributes);
	glViewport(0, 0, window_attributes.width, window_attributes.height);


	interface.updateGL();

	if(_clk_th.joinable())
		_clk_th.join();
	if(_bat_th.joinable())
		_bat_th.join();

	glXSwapBuffers(Xdisplay, glX_window_handle);
}

	int main(int argc, char *argv[])
	{


		interface = HeadsUpInterface();
		HeadsUpTask task1 = HeadsUpTask("Make Some Good Plans");
		task1.addObjective(HeadsUpObjective("Implement changeText method",0));
		task1.addObjective(HeadsUpObjective("Implement changeColour method",0));
		task1.addObjective(HeadsUpObjective("Go on an adventure",1));
		HeadsUpTask task2 = HeadsUpTask("The Less Good Plans");
		task1.addObjective(HeadsUpObjective("11AA1A",2));
		task1.addObjective(HeadsUpObjective("11AA1A",2));
		task2.addObjective(HeadsUpObjective("Cats And Dogs; pet them!",0));
		task2.addObjective(HeadsUpObjective("Fly away for good?",0));
		task2.addObjective(HeadsUpObjective("GO, THEN LEAVE",1));
		interface.addTask(task1);
		interface.addTask(task2);

		createTheWindow();
		createTheRenderContext();
		cv::VideoCapture cap;
		cap.open(0);

		if (!cap.isOpened())
		{
			printf("can not open camera or video file\n");
			return -1;
		}
		m_cap = cap;

		while (updateTheMessageQueue()) {
			redrawTheWindow();
		}

		return 0;
	}
