/*
 * HeadsUpMap.cpp
 *
 *  Created on: Jan 13, 2017
 *      Author: erin
 */

#include "header.h"
#include "HeadsUpMap.h"
#include "png.h"

#define LONGITUDE	-79.397432
#define LATITUDE	43.662313
std::string dsource = "http://a.tile.openstreetmap.org";
GLuint tex;

int long2tilex(double lon, int z)
{
	return (int)(floor((lon + 180.0) / 360.0 * pow(2.0, z)));
}

int lat2tiley(double lat, int z)
{
	return (int)(floor((1.0 - log( tan(lat * M_PI/180.0) + 1.0 / cos(lat * M_PI/180.0)) / M_PI) / 2.0 * pow(2.0, z)));
}

double tilex2long(int x, int z)
{
	return x / pow(2.0, z) * 360.0 - 180;
}

double tiley2lat(int y, int z)
{
	double n = M_PI - 2.0 * M_PI * y / pow(2.0, z);
	return 180.0 / M_PI * atan(0.5 * (exp(n) - exp(-n)));
}

GLuint png_texture_load(const char * file_name, int * wth, int * heht)
{
    png_byte header[8];

    FILE *fp = fopen(file_name, "rb");
    if (fp == 0)
    {
        perror(file_name);
        return 0;
    }

    // read the header
    fread(header, 1, 8, fp);

    if (png_sig_cmp(header, 0, 8))
    {
        fprintf(stderr, "error: %s is not a PNG.\n", file_name);
        fclose(fp);
        return 0;
    }

    png_structp png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (!png_ptr)
    {
        fprintf(stderr, "error: png_create_read_struct returned 0.\n");
        fclose(fp);
        return 0;
    }

    // create png info struct
    png_infop info_ptr = png_create_info_struct(png_ptr);
    if (!info_ptr)
    {
        fprintf(stderr, "error: png_create_info_struct returned 0.\n");
        png_destroy_read_struct(&png_ptr, (png_infopp)NULL, (png_infopp)NULL);
        fclose(fp);
        return 0;
    }

    // create png info struct
    png_infop end_info = png_create_info_struct(png_ptr);
    if (!end_info)
    {
        fprintf(stderr, "error: png_create_info_struct returned 0.\n");
        png_destroy_read_struct(&png_ptr, &info_ptr, (png_infopp) NULL);
        fclose(fp);
        return 0;
    }

    // the code in this if statement gets called if libpng encounters an error
    if (setjmp(png_jmpbuf(png_ptr))) {
        fprintf(stderr, "error from libpng\n");
        png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
        fclose(fp);
        return 0;
    }

    // init png reading
    png_init_io(png_ptr, fp);

    // let libpng know you already read the first 8 bytes
    png_set_sig_bytes(png_ptr, 8);

    // read all the info up to the image data
    png_read_info(png_ptr, info_ptr);

    // variables to pass to get info
    int bit_depth, color_type;
    png_uint_32 temp_width, temp_height;

    // get info about png
    png_get_IHDR(png_ptr, info_ptr, &temp_width, &temp_height, &bit_depth, &color_type,
        NULL, NULL, NULL);

    if (wth){ *wth = temp_width; }
    if (heht){ *heht = temp_height; }

    // Update the png info struct.
    png_read_update_info(png_ptr, info_ptr);

    // Row size in bytes.
    int rowbytes = png_get_rowbytes(png_ptr, info_ptr);

    // glTexImage2d requires rows to be 4-byte aligned
    rowbytes += 3 - ((rowbytes-1) % 4);

    // Allocate the image_data as a big block, to be given to opengl
    png_byte * image_data;

    image_data = (png_byte*)malloc(rowbytes * temp_height * sizeof(png_byte)+15);
    if (image_data == NULL)
    {
        fprintf(stderr, "error: could not allocate memory for PNG image data\n");
        png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
        fclose(fp);
        return 0;
    }

    // row_pointers is for pointing to image_data for reading the png with libpng
    png_bytep * row_pointers = (png_bytep*)malloc(temp_height * sizeof(png_bytep));
    if (row_pointers == NULL)
    {
        fprintf(stderr, "error: could not allocate memory for PNG row pointers\n");
        png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
        free(image_data);
        fclose(fp);
        return 0;
    }

    // set the individual row_pointers to point at the correct offsets of image_data
    int i;
    for (i = 0; i < temp_height; i++)
    {
        row_pointers[temp_height - 1 - i] = image_data + i * rowbytes;
    }

    // read the png into image_data through row_pointers
    png_read_image(png_ptr, row_pointers);

    // Generate the OpenGL texture object
    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, temp_width, temp_height, 0, GL_RGB, GL_UNSIGNED_BYTE, image_data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    // clean up
    png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
    free(image_data);
    free(row_pointers);
    fclose(fp);
    return texture;
}

std::string getTileUrl(std::string datasource, double longitude, double latitude, int z){
	std::string str = datasource;
	std::string z_str =std::to_string(z);

	std::string x_str = std::to_string(long2tilex(longitude,z));
	std::string y_str  = std::to_string(lat2tiley(latitude,z));

	str+="/"+z_str+"/"+x_str+"/"+y_str+".png";

	return str;
}


HeadsUpMap::HeadsUpMap(){
		h = MAP_HEIGHT;
		w = MAP_HEIGHT*1.3;
		x = width-w-RIGHT_MARGIN;
		y = TOP_MARGIN;

	}

	void HeadsUpMap::transform(int new_height, int new_width, int new_x, int new_y){
		h = new_height;
		w = new_width;
		x = new_x;
		y = new_y;
	}

	void HeadsUpMap::draw(){
		glViewport(width-w-RIGHT_MARGIN-MAP_HEIGHT*1.3, height-MAP_HEIGHT-TOP_MARGIN,  MAP_HEIGHT*1.3, MAP_HEIGHT);

		glPushMatrix();  //Make sure our transformations don't affect any other transformations in other code
		//glTranslateF(pRect->x, pRect->y);  //Translate rectangle to its assigned x and y position
		//Put other transformations here
		glBegin(GL_POLYGON);   //We want to draw a quad, i.e. shape with four sides
		glColor4f(0.0, 0.6, 0.6, 0.9);
		glVertex2f(-1, 0.8);
		glVertex2f(-0.8, 1);
		glVertex2f(1, 1);
		glVertex2f(1, -0.8);
		glVertex2f(0.8, -1);
		glVertex2f(-1, -1);
		glEnd();

		float bw = 0.03;


		std::string str = getTileUrl(dsource,LONGITUDE,LATITUDE,17);

		int hh = MAP_HEIGHT;
		int ww = MAP_HEIGHT*1.3;
		tex = png_texture_load("/home/erin/Downloads/47830.png",&hh,&ww);

		glEnable(GL_TEXTURE_2D);
		glBindTexture (GL_TEXTURE_2D, tex);
		glBegin(GL_QUADS);
		glTexCoord2f (0.0, 0.0);
		glVertex3f (-1.0, -1.0, 0.0);
		glTexCoord2f (1.0, 0.0);
		glVertex3f (1.0, -1.0, 0.0);
		glTexCoord2f (1.0, 1.0);
		glVertex3f (1.0, 1.0, 0.0);
		glTexCoord2f (0.0, 1.0);
		glVertex3f (-1.0, 1.0, 0.0);
		glEnd();

		glDisable(GL_TEXTURE_2D);

		glPopMatrix();





		//fprintf(stderr,"%s",str.c_str());



	}


