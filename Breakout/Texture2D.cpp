#include "Texture2D.h"

Texture2D::Texture2D(const char* path)
{
	data = stbi_load(path, &Width, &Height, &nrChannels, 0);

	glGenTextures(1, &ID);
	glBindTexture(GL_TEXTURE_2D, ID);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, Internal_Format, Width, Height, 0, Image_Format, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(ID);
	}
	else
	{
		cout << "Failde to load texture!" << endl;
	}

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, Wrap_S);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, Wrap_T);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, Filter_Min);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, Filter_Max);

	glBindTexture(GL_TEXTURE_2D, 0);

	stbi_image_free(data);
}

unsigned int Texture2D::getId()
{
	return ID;
}

void Texture2D::Bind() const
{
	glBindTexture(GL_TEXTURE_2D, ID);
}
