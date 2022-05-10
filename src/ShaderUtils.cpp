#include"ShaderUtils.h"
#include"Renderer.h"

#pragma once

unsigned int CompileShader(unsigned int type, std::string& src)
{
	unsigned int id = glCreateShader(type);
	const char* shaderSrc = src.c_str();
	glShaderSource(id, 1, &shaderSrc, NULL);
	glCompileShader(id);
	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE)
	{
		std::cout << "Error at " << (type == GL_VERTEX_SHADER ? "vertex shader" : "fragment shader") << std::endl;
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* data = (char*)malloc(sizeof(char) * length);
		glGetShaderInfoLog(id, length, &length, data);
		std::cout << data << std::endl;
	}
	return id;
}

unsigned int CreateShader(std::string& vertexSrc, std::string& fragmentSrc)
{
	unsigned int program = glCreateProgram();
	unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexSrc);
	unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentSrc);
	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glValidateProgram(program);
	glDeleteShader(vs);
	glDeleteShader(fs);
	return program;
}

std::string ParseShader(const char* path)
{
	std::ifstream inp(path);
	if (!inp.is_open())
		std::cout << "File didn't open" << std::endl;
	std::string line;
	std::stringstream ss;
	while (getline(inp, line))
	{
		ss << line << '\n';
	}
	inp.close();
	return ss.str();
}

