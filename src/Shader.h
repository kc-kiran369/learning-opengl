#ifndef SHADER_CLASS_H
#define SHADER_CLASS_H

#include<string>
#include"GLEW/glew.h"

class Shader
{
public:
	unsigned int ID;
	std::string VertexShader;
	std::string FragmentShader;
	Shader(const char* vert_path, const char* frag_path);

	void Activate();
	void DeActivate();
	void Delete();
};

#endif