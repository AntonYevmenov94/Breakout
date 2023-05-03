#pragma once

#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

#include <glad/glad.h>

#include "Texture2D.h"
#include "Shader.h"

#include <stb_image.h>

using namespace std;

class ResourceManager
{
public:

	//Resourse storage
	static map<string, Shader> Shaders;
	static map<string, Texture2D> Textures;

	//Load shader programm
	static Shader LoadShader(const char* vShaderFile, const char* fShaderFile, string name);

	//Get saved shader
	static Shader GetShader(string name);

	//Load and generate texture from file
	static Texture2D LoadTexture(const char* file, bool alpha, string name);

	//Get saved texture
	static Texture2D GetTexture(string name);

	//Clear memory for all downloaded files
	static void Clear();
private:

	ResourceManager() {}

	//Download and generate shader from file
	static Shader LoadShaderFromFile(const char* vShaderFile, const char* fShaderFile);

	//Download texture from file
	static Texture2D LoadTextureFromFile(const char* file, bool alpha);
};

