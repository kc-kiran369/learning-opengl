#version 330 core

layout(location=0) in vec3 _position;

uniform mat4 model;
uniform mat4 MVP;

void main()
{
	gl_Position = MVP*model*vec4(_position +vec3(1.0f,0.7f,0.0f),1.0f) ;
}