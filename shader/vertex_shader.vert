#version 330 core

layout(location=0) in vec3 _position;
layout(location=1) in vec3 _vertexColors;
layout(location=2) in vec2 _textureCoordinate;

out vec3 vertexColors;
out vec2 textureCoordinate;

uniform mat4 camMatrix;

void main()
{
	vertexColors = _vertexColors;
	gl_Position = vec4(_position ,1.0f) * camMatrix;
}