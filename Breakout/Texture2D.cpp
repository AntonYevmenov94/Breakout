#include "Texture2D.h"

Texture2D::Texture2D()
{
	Width = 0;
	Height = 0;
	Internal_Format = GL_RGB;
	Image_Format = GL_RGB;
	Wrap_S = GL_REPEAT;
	Wrap_T = GL_REPEAT;
	Filter_Min = GL_LINEAR;
	Filter_Max = GL_LINEAR;

	glGenTextures(1, &this->ID);
}

unsigned int Texture2D::getId()
{
	return ID;
}

void Texture2D::Generate(int width, int height, unsigned char* data)
{
	this->Width = width;
	this->Height = height;

	//Create texture
	glGenTextures(1, &ID);
	glBindTexture(GL_TEXTURE_2D, this->ID);
	glTexImage2D(GL_TEXTURE_2D, 0, this->Internal_Format, width, height, 0, this->Image_Format, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(ID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, Wrap_S);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, Wrap_T);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, Filter_Min);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, Filter_Max);

	glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture2D::Bind() const
{
	glBindTexture(GL_TEXTURE_2D, ID);
}
