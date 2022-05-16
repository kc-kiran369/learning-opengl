#version 330 core

in vec2 textureCoordinate;
uniform sampler2D texture0;

void main()
{
	gl_FragColor = texture(texture0,textureCoordinate);
}