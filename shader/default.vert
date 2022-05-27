#version 330 core

layout(location=0) in vec3 _position;
layout(location=1) in vec2 _textureCoordinate;
layout(location=2) in vec3 _normal;

out vec3 vertexColors;
out vec2 textureCoordinate;
out vec3 normal;
//out vec3 FragPos;

uniform mat4 MVP;
uniform mat4 model;

void main()
{
	normal = _normal;
	textureCoordinate = _textureCoordinate;
	//FragPos = vec3(model * vec4(_position, 1.0));
	gl_Position = MVP * model * vec4(_position , 1.0f);
}