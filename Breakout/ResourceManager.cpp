#include "ResourceManager.h"

map<string, Texture2D> ResourceManager::Textures;
map<string, Shader> ResourceManager::Shaders;

Shader ResourceManager::LoadShader(const char* vShaderFile, const char* fShaderFile, string name)
{
	Shaders[name] = LoadShaderFromFile(vShaderFile, fShaderFile);
	return Shaders[name];
}

Shader ResourceManager::GetShader(string name)
{
	return Shaders[name];
}

Texture2D ResourceManager::LoadTexture(const char* file, bool alpha, string name)
{
	Textures[name] = LoadTextureFromFile(file, alpha);
	return Textures[name];
}

Texture2D ResourceManager::GetTexture(string name)
{
	return Textures[name];
}

void ResourceManager::Clear()
{
	//Delete all shaders
	for (auto iter : Shaders)
	{
		glDeleteProgram(iter.second.ID);
	}

	//Delete all textures
	for (auto iter : Textures)
	{
		glDeleteTextures(1, &iter.second.ID);
	}
}

Shader ResourceManager::LoadShaderFromFile(const char* vShaderFile, const char* fShaderFile)
{
	//Getting source code of vertex and fragment shaders
	string vertexCode;
	string fragmentCode;

	try
	{
		//Open files
		ifstream vertexShaderFile(vShaderFile);
		ifstream fragmentShaderFile(fShaderFile);
		stringstream vShaderStream, fShaderStream;

		//Reading content of buffer
		vShaderStream << vertexShaderFile.rdbuf();
		fShaderStream << fragmentShaderFile.rdbuf();

		//Close files
		vertexShaderFile.close();
		fragmentShaderFile.close();

		//Converting stream to string
		vertexCode = vShaderStream.str();
		fragmentCode = fShaderStream.str();
	}
	catch (exception e)
	{
		cout << "ERROR::SHADER: Failed to read shader files" << endl;
	}

	const char* vShaderCode = vertexCode.c_str();
	const char* fShaderCode = fragmentCode.c_str();

	//Create object of shader from source code
	Shader shader;
	shader.Compile(vShaderCode, fShaderCode);

	return shader;
}

Texture2D ResourceManager::LoadTextureFromFile(const char* file, bool alpha)
{
	//Create object of texture
	Texture2D texture;

	if (alpha)
	{
		texture.Internal_Format = GL_RGBA;
		texture.Image_Format = GL_RGBA;
	}

	//Load image
	int width, height, nrChannels;
	unsigned char* data = stbi_load(file, &width, &height, &nrChannels, 0);

	//Generate texture
	if (data)
	{
		texture.Generate(width, height, data);
	}
	else
	{
		cout << "Failde to load texture!" << endl;
	}

	stbi_image_free(data);
	return texture;
}
