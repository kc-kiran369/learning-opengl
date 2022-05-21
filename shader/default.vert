#version 330 core

layout(location=0) in vec3 _position;
layout(location=1) in vec2 _textureCoordinate;

out vec3 vertexColors;
out vec2 textureCoordinate;

uniform mat4 MVP;
uniform mat4 model;

void main()
{
	textureCoordinate = _textureCoordinate;
	gl_Position = MVP * model * vec4(_position , 1.0f) ;
}