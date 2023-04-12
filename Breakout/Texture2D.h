#pragma once

#include <iostream>
#include <glad/glad.h>
#include <stb_image.h>

using namespace std;

class Texture2D
{
	unsigned int ID;

	unsigned char* data;
	
	//Size of texteure
	int Width, Height, nrChannels;
	
	//Textures format
	int Internal_Format = GL_RGB;
	int Image_Format = GL_RGB;

	//Texture configurations
	int Wrap_S = GL_REPEAT;
	int Wrap_T = GL_REPEAT;
	int Filter_Min = GL_LINEAR;
	int Filter_Max = GL_LINEAR;

public:
	Texture2D(const char* path);

	unsigned int getId();

	void Bind() const;
};

