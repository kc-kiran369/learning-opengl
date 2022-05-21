#version 330 core

in vec2 textureCoordinate;
uniform sampler2D texture0;
uniform vec4 lightColor;

float textureScale = 1.0f;

void main()
{
	gl_FragColor = texture(texture0 , textureCoordinate * textureScale) * lightColor;
}