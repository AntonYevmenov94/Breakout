#pragma once

#include <iostream>
#include <glad/glad.h>
#include <stb_image.h>

using namespace std;

class Texture2D
{
public:

	unsigned int ID;

	//Size of texteure
	int Width, Height;
	
	//Textures format
	unsigned int Internal_Format;
	unsigned int Image_Format;
	
	//Textures configuration
	int Wrap_S;
	int Wrap_T;
	int Filter_Min;
	int Filter_Max;

	Texture2D();

	void Generate(int width, int height, unsigned char* data);

	unsigned int getId();

	void Bind() const;
};

