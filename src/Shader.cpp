#include"Shader.h"
#include"Renderer.h"
#include"ShaderUtils.h"

Shader::Shader()
{
	VertexShader = ParseShader("shader\\vertex_shader.vert");
	FragmentShader = ParseShader("shader\\fragment_shader.frag");
	ID = CreateShader(VertexShader, FragmentShader);
	glUseProgram(ID);
}

void Shader::Activate()
{
	glUseProgram(ID);
}

void Shader::Delete()
{
	glDeleteProgram(ID);
}
