/*
 * HeadsUpBatteryInfo.cpp
 *
 *  Created on: Jan 13, 2017
 *      Author: erin
 */
#include <lrand/lrand.h>

// From helper functions
extern std::string exec(const char*);

//extern std::atomic<bool> dev_is_connected;
extern std::atomic<bool> EXIT_THREADS;

#ifdef MODERN_OPENGL
	extern Shader REDshader;
	extern Shader YELLOWshader;
	extern Shader GREENshader;

	extern Shader interfaceLowlight;
	extern Shader interfaceColour;
	extern Shader interfaceShader;
#endif
// Temp variables
std::string pinf;

Battery HeadsUpBatteryInfo::computer_bat = Battery();
Battery HeadsUpBatteryInfo::device_bat	 = Battery();


void getPCBatteryInformation() {
#if  defined(_WIN32) || defined(__WIN32__)
    SYSTEM_POWER_STATUS status;
    GetSystemPowerStatus( &status );
    HeadsUpBatteryInfo::computer_bat.charge = status.BatteryLifePercent;

#elif defined(OS_GNU_LINUX)
	try {
		pinf = exec("upower -i `upower -e | grep 'BAT'` | grep 'percentage\\|state' | tr -d ' '");
	} catch(std::runtime_error *e){
		std::fprintf(stderr,"Error executing upower command (fatal)");
	}

	try {
		HeadsUpBatteryInfo::computer_bat.state	= pinf.substr(pinf.find(":"));
		HeadsUpBatteryInfo::computer_bat.charge = atof(pinf.substr(pinf.find('%') - 3).c_str());
	} catch(std::out_of_range *e){
		std::fprintf(stderr,"Error parsing upower strings");
	}

	if (HeadsUpBatteryInfo::computer_bat.state == "discharging")
		HeadsUpBatteryInfo::computer_bat.charging = false;
	else if (HeadsUpBatteryInfo::computer_bat.state == "charging")
		HeadsUpBatteryInfo::computer_bat.charging = true;

	if (HeadsUpBatteryInfo::computer_bat.state == "discharging")
		HeadsUpBatteryInfo::computer_bat.charging = false;
	else if (HeadsUpBatteryInfo::computer_bat.state == "charging")
		HeadsUpBatteryInfo::computer_bat.charging = true;
#else

#endif
}

void computerGetBatteryInformation() {
	int i = 0;
	while (!EXIT_THREADS) {
		if (i > 10){
			getPCBatteryInformation();
			i = 0;
		} else {
			i++;
		}
	}
	puts("Computer Battery Information Thread Exited Successfully");
}

HeadsUpBatteryInfo::HeadsUpBatteryInfo() {
	getPCBatteryInformation();
	comp_text.setColour(text_colour);
	dev_text.setColour(text_colour);
}

/*@method:	render(void);
 *		Processes all the information necessary to update the module.
 */
int HeadsUpBatteryInfo::render(){
	comp_text.setText(std::to_string(HeadsUpBatteryInfo::computer_bat.charge).erase(5));
	dev_text.setText(std::to_string(HeadsUpBatteryInfo::device_bat.charge).erase(5));
	return 0;
}

/*@method:	draw(void);
 *		Draws the module to the window using OpenGL.
 */
void HeadsUpBatteryInfo::draw() {


	// Computer Battery Monitor
#ifdef MODERN_OPENGL
	interfaceColour.Use();
#else
	colour.bind();
#endif
	glViewport(width - (MAP_WIDTH + BAT_WIDTH + RIGHT_MARGIN*2), height - TOP_MARGIN - BAT_HEIGHT, BAT_WIDTH,
	BAT_HEIGHT);

		glBegin(GL_POLYGON); //We want to draw a map, i.e. shape with four bevel sides
		glVertex2f(-1.0, -1.0);
		glVertex2f(-1.0, 1.0);
		glVertex2f(0.8, 1.0);
		glVertex2f(0.8, 0.4);
		glVertex2f(1.0, 0.4);
		glVertex2f(1.0, -0.4);
		glVertex2f(0.8, -0.4);
		glVertex2f(0.8, -1.0);
		glEnd();

#ifdef MODERN_OPENGL
		if (battery_life <= 10.0)
			REDshader.Use();
		else if (battery_life <= 20.0)
			YELLOWshader.Use();
		else
			GREENshader.Use();
#else
		if (HeadsUpBatteryInfo::computer_bat.charge <= 10.0)
			LRAND::Colour::RED.bind();
		else if (HeadsUpBatteryInfo::computer_bat.charge <= 20.0)
			LRAND::Colour::YELLOW.bind();
		else
			LRAND::Colour::GREEN.bind();

#endif
		glBegin(GL_POLYGON); //We want to draw a map, i.e. shape with four bevel sides
		glVertex2f(-0.9, -0.8);
		glVertex2f(-0.9, 0.8);
		glVertex2f(((HeadsUpBatteryInfo::computer_bat.charge / 125.0) * 2.0 - 0.9), 0.8);
		glVertex2f(((HeadsUpBatteryInfo::computer_bat.charge / 125.0) * 2.0 - 0.9), -0.8);
		glEnd();

	comp_text.ldraw(width - (MAP_WIDTH + BAT_WIDTH + RIGHT_MARGIN*2) + (BAT_WIDTH / 6),
			height - TOP_MARGIN - BAT_HEIGHT * 0.8, 0, BAT_FONT_SIZE);

#ifdef MODERN_OPENGL
	interfaceColour.Use();
#else
	colour.bind();
#endif
	glViewport(width - (MAP_WIDTH + BAT_WIDTH + RIGHT_MARGIN*2), height - TOP_MARGIN - BAT_HEIGHT * 2 - height / 70,
	BAT_WIDTH, BAT_HEIGHT);

		glBegin(GL_POLYGON); //We want to draw a map, i.e. shape with four bevel sides
		glVertex2f(-1.0, -1.0);
		glVertex2f(-1.0, 1.0);
		glVertex2f(0.8, 1.0);
		glVertex2f(0.8, 0.4);
		glVertex2f(1.0, 0.4);
		glVertex2f(1.0, -0.4);
		glVertex2f(0.8, -0.4);
		glVertex2f(0.8, -1.0);
		glEnd();

#ifdef MODERN_OPENGL
		if (battery_life <= 10.0)
			REDshader.Use();
		else if (battery_life <= 20.0)
			YELLOWshader.Use();
		else
			GREENshader.Use();
#else
		if (HeadsUpBatteryInfo::device_bat.charge <= 10.0)
			LRAND::Colour::RED.bind();
		else if (HeadsUpBatteryInfo::device_bat.charge <= 20.0)
			LRAND::Colour::YELLOW.bind();
		else
			LRAND::Colour::GREEN.bind();

#endif
		glBegin(GL_POLYGON); //We want to draw a map, i.e. shape with four bevel sides
		glVertex2f(-0.9, -0.8);
		glVertex2f(-0.9, 0.8);
		glVertex2f(((HeadsUpBatteryInfo::device_bat.charge / 125.0) * 2.0 - 0.9), 0.8);
		glVertex2f(((HeadsUpBatteryInfo::device_bat.charge / 125.0) * 2.0 - 0.9), -0.8);
		glEnd();


	dev_text.ldraw(width - (MAP_WIDTH + BAT_WIDTH + RIGHT_MARGIN*2) + (BAT_WIDTH / 6),
			height - TOP_MARGIN - BAT_HEIGHT * 2 - height / 70
					+ (BAT_HEIGHT * 0.2), 0, BAT_FONT_SIZE);

#ifdef MODERN_OPENGL
	interfaceColour.Use();
#else
	colour.bind();
#endif
	// Computer icon
	glViewport(width - (MAP_WIDTH + BAT_WIDTH + RIGHT_MARGIN*2) - RIGHT_MARGIN - 10, height - TOP_MARGIN - BAT_HEIGHT,
			BAT_HEIGHT, BAT_HEIGHT);

		glBegin(GL_POLYGON); //We want to draw a map, i.e. shape with four bevel sides
		glVertex2f(-0.7, 0.7);
		glVertex2f(-0.7, 0.0);
		glVertex2f(0.7, 0.0);
		glVertex2f(0.7, 0.7);
		glEnd();

#ifdef MODERN_OPENGL
	interfaceLowlight.Use();
#else
	colour.bind();
#endif
		glBegin(GL_POLYGON); //We want to draw a map, i.e. shape with four bevel sides
		glVertex2f(-0.6, 0.6);
		glVertex2f(-0.6, 0.1);
		glVertex2f(0.6, 0.1);
		glVertex2f(0.6, 0.6);
		glEnd();

#ifdef MODERN_OPENGL
	interfaceColour.Use();
#else
	colour.bind();
#endif
	glBegin(GL_POLYGON); //We want to draw a map, i.e. shape with four bevel sides
		glVertex2f(-0.8, -0.35);
		glVertex2f(-0.7, 0.0);
		glVertex2f(0.7, 0.0);
		glVertex2f(0.8, -0.35);
		glEnd();

	if (HeadsUpBatteryInfo::computer_bat.charging) {
#ifdef MODERN_OPENGL
		YELLOWshader.Use();
#else
		LRAND::Colour::YELLOW.bind();
#endif
		glBegin(GL_POLYGON); //We want to draw a map, i.e. shape with four bevel sides
		glVertex2f(0.0, 0.4);
		glVertex2f(0.0, 0.9);
		glVertex2f(-0.2, 0.2);
		glVertex2f(0.0, 0.2);
		glVertex2f(0.0, -0.2);
		glVertex2f(0.2, 0.4);
		glEnd();
	}
	// Device Icon

	glViewport(width - (MAP_WIDTH + BAT_WIDTH + RIGHT_MARGIN*2) - RIGHT_MARGIN - 10,
			height - TOP_MARGIN - BAT_HEIGHT * 2 - height / 70, BAT_HEIGHT, BAT_HEIGHT);

#ifdef MODERN_OPENGL
	interfaceColour.Use();
	uint verts = 3;
	GLuint VBO, VAO, EBO;

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	// Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

	if (HeadsUpBatteryInfo::device_bat.charging) {
		GLfloat VS[] = {-0.8f, -0.8f,0.0f,0.0f, 0.67f, 1.0f, 0.9f,
						-0.2f, 0.8f,0.0f,0.0f, 0.67f, 1.0f, 0.9f,
						 0.0f, 0.6f,0.0f,0.0f, 0.67f, 1.0f, 0.9f,
						 0.8f, -0.8f,0.0f,0.0f, 0.67f, 1.0f, 0.9f,
						 0.2f, 0.8f,0.0f,0.0f, 0.67f, 1.0f, 0.9f,
						0.0f, 0.0f,0.0f,LRAND::yellow.R,LRAND::yellow.G,LRAND::yellow.B,LRAND::yellow.A,
						0.0, 0.5,0.0f,LRAND::yellow.R,LRAND::yellow.G,LRAND::yellow.B,LRAND::yellow.A,
						-0.2, -0.2,0.0f,LRAND::yellow.R,LRAND::yellow.G,LRAND::yellow.B,LRAND::yellow.A,
						0.0, -0.2,0.0f,LRAND::yellow.R,LRAND::yellow.G,LRAND::yellow.B,LRAND::yellow.A,
						0.0, -0.6,0.0f,LRAND::yellow.R,LRAND::yellow.G,LRAND::yellow.B,LRAND::yellow.A,
						0.2, 0.0,0.0f,LRAND::yellow.R,LRAND::yellow.G,LRAND::yellow.B,LRAND::yellow.A};
		GLuint IS[]	=  {0,1,2,
						3,4,2,
						5,6,7,
						8,9,10};
		glBufferData(GL_ARRAY_BUFFER, sizeof(VS), VS, GL_STATIC_DRAW); 	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(IS), IS, GL_STATIC_DRAW);	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(GLfloat), (GLvoid*)0); glEnableVertexAttribArray(0); glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 7 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat))); glEnableVertexAttribArray(1); verts = sizeof(IS);
	} else {
		GLfloat VS[] = {-0.8f, -0.8f,0.0f,0.0f, 0.67f, 1.0f, 0.9f,
						-0.2f, 0.8f,0.0f,0.0f, 0.67f, 1.0f, 0.9f,
						 0.0f, 0.6f,0.0f,0.0f, 0.67f, 1.0f, 0.9f,
						 0.8f, -0.8f,0.0f,0.0f, 0.67f, 1.0f, 0.9f,
						 0.2f, 0.8f,0.0f,0.0f, 0.67f, 1.0f, 0.9f };

		GLuint IS[]	=  {0,1,2,
						3,4,2};
		glBufferData(GL_ARRAY_BUFFER, sizeof(VS), VS, GL_STATIC_DRAW); 	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(IS), IS, GL_STATIC_DRAW);	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(GLfloat), (GLvoid*)0); glEnableVertexAttribArray(0); glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 7 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat))); glEnableVertexAttribArray(1); verts = sizeof(IS);
	}

	glBindVertexArray(0); // Unbind VAO
	interfaceShader.Use();
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, verts, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
#endif

}
