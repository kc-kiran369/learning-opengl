#ifndef SHADER_CLASS_H
#define SHADER_CLASS_H

#include<string>

class Shader
{
public:
	unsigned int ID;
	std::string VertexShader;
	std::string FragmentShader;
	Shader();

	void Activate();
	void Delete();
};

#endif