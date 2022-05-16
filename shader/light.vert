#version 330 core

layout(location=0) in vec3 _position;

uniform mat4 camMatrix;

void main()
{
	gl_Position = vec4(_position ,1.0f) ;
}