#include "Shader.h"

Shader::Shader(const char* vertexPath, const char* fragmentPath)
{
	string vShader, fShader;

	ifstream vShaderFile, fShaderFile;
	vShaderFile.exceptions(ifstream::badbit);
	fShaderFile.exceptions(ifstream::badbit);
	try
	{
		vShaderFile.open(vertexPath);
		fShaderFile.open(fragmentPath);

		stringstream vShaderStream, fShaderStream;
		vShaderStream << vShaderFile.rdbuf();
		fShaderStream << fShaderFile.rdbuf();

		vShaderFile.close();
		fShaderFile.close();

		vShader = vShaderStream.str();
		fShader = fShaderStream.str();
	}
	catch (ifstream::failure e)
	{
		cout << "Error, file not successfuly read " << e.what() << endl;
	}

	const GLchar* vShaderCode = vShader.c_str();
	const GLchar* fShaderCode = fShader.c_str();


	GLuint vertexShader, fragmentShader;
	
	//Create vertex shader
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vShaderCode, NULL);
	glCompileShader(vertexShader);
	checkCompileErrors(vertexShader, "VERTEX");
	
	//Create fragment shader
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glCompileShader(fragmentShader);
	checkCompileErrors(fragmentShader, "FRAGMENT");

	//Create shader programm
	ID = glCreateProgram();
	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);
	glLinkProgram(ID);
	checkCompileErrors(ID, "PROGRAMM");

	//Delete shaders
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

unsigned int Shader::getId()
{
	return ID;
}

void Shader::checkCompileErrors(unsigned int object, string type)
{
	GLint success;
	GLchar infolog[1024];
	if (type != "PROGRAMM")
	{
		glGetShaderiv(object, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(object, sizeof(infolog), NULL, infolog);
			cout << "Error! " << type << "shader compilation failed: " << infolog << endl;
		}
	}
	else
	{
		glGetProgramiv(object, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(object, sizeof(infolog), NULL, infolog);
			cout << "Error! " << type << " compilation failed: " << infolog << endl;
		}
	}
}

void Shader::Use()
{
	glUseProgram(ID);
}

void Shader::SetFloat(const char* name, float value, bool useShader)
{
	if (useShader)
		this->Use();
	glUniform1f(glGetUniformLocation(ID, name), value);
}

void Shader::SetInteger(const char* name, int value, bool useShader)
{
	if (useShader)
		this->Use();
	glUniform1i(glGetUniformLocation(ID, name), value);
}

void Shader::SetVector2f(const char* name, float x, float y, bool useShader)
{
	if (useShader)
		this->Use();
	glUniform2f(glGetUniformLocation(ID, name), x, y);
}

void Shader::SetVector2f(const char* name, const glm::vec2& value, bool useShader)
{
	if (useShader)
		this->Use();
	glUniform2f(glGetUniformLocation(ID, name), value.x, value.y);
}

void Shader::SetVector3f(const char* name, float x, float y, float z, bool useShader)
{
	if (useShader)
		this->Use();
	glUniform3f(glGetUniformLocation(ID, name), x, y, z);
}

void Shader::SetVector3f(const char* name, const glm::vec3& value, bool useShader)
{
	if (useShader)
		this->Use();
	glUniform3f(glGetUniformLocation(ID, name), value.x, value.y, value.z);
}

void Shader::SetVector4f(const char* name, float x, float y, float z, float w, bool useShader)
{
	if (useShader)
		this->Use();
	glUniform4f(glGetUniformLocation(ID, name), x, y, z, w);
}

void Shader::SetVector4f(const char* name, const glm::vec4& value, bool useShader)
{
	if (useShader)
		this->Use();
	glUniform4f(glGetUniformLocation(ID, name), value.x, value.y, value.z, value.w);
}

void Shader::SetMatrix(const char* name, const glm::mat4& value, bool useShader)
{
	if (useShader)
		this->Use();
	glUniformMatrix4fv(glGetUniformLocation(ID, name), 1, false, glm::value_ptr(value));
}