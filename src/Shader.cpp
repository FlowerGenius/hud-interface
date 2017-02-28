/*
 * Shader.cpp
 *
 *  Created on: Feb 16, 2017
 *      Author: erin
 */

#include <lrand/lrand.h>

Shader REDshader;
Shader YELLOWshader;
Shader GREENshader;

Shader interfaceHighlight;
Shader interfaceLowlight;
Shader interfaceColour;
Shader interfaceShader;

const GLchar* Shader::defaultVertexShaderPath 	= "";
const GLchar* Shader::defaultFragmentShaderPath = "";


void Shader::loadStaticShaders(){
		REDshader = Shader("/home/erin/workspace/HUD2/lrand/shaders/interface.vs", "/home/erin/workspace/HUD2/lrand/shaders/mattered.frag");

		YELLOWshader = Shader("/home/erin/workspace/HUD2/lrand/shaders/interface.vs", "/home/erin/workspace/HUD2/lrand/shaders/matteyellow.frag");
		GREENshader = Shader("/home/erin/workspace/HUD2/lrand/shaders/interface.vs", "/home/erin/workspace/HUD2/lrand/shaders/mattegreen.frag");

		interfaceHighlight = Shader("/home/erin/workspace/HUD2/lrand/shaders/interface.vs", "/home/erin/workspace/HUD2/lrand/shaders/interfacehigh.frag");
		interfaceLowlight = Shader("/home/erin/workspace/HUD2/lrand/shaders/interface.vs", "/home/erin/workspace/HUD2/lrand/shaders/interfacelow.frag");
		interfaceColour = Shader("/home/erin/workspace/HUD2/lrand/shaders/interface.vs", "/home/erin/workspace/HUD2/lrand/shaders/interface.frag");

		interfaceShader = Shader("/home/erin/workspace/HUD2/lrand/shaders/mattecolour.vs", "/home/erin/workspace/HUD2/lrand/shaders/mattecolour.frag");

}

void Shader::setColour(LRAND::GlColour c){

}

void Shader::setColour(LRAND::Colour c){

}

Shader::~Shader() {
	// TODO Auto-generated destructor stub
}

