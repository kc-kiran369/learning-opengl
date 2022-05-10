#version 330 core

in vec3 vertexColors;
in vec2 textureCoordinate;

uniform sampler2D texture01;

void main()
{
	//FragColor = vec4(vertexColors,1.0f);
	gl_FragColor = texture(texture01,textureCoordinate);
}