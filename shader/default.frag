#version 330 core

in vec2 textureCoordinate;
in vec3 normal;
//in vec3 FragPos;

uniform sampler2D texture0;
uniform vec4 lightColor;
//uniform vec3 lightPos;

float textureScale = 1.0;
vec4 ambientColor = vec4(1.0f,0.9f,0.8f,1.0f);

void main()
{
	//ec3 norm = normalize(normal);
	//vec3 lightDir = normalize(lightPos - FragPos);
	//float diff = max(dot(norm, lightDir), 0.0);
	gl_FragColor = texture(texture0 , textureCoordinate * textureScale) * lightColor * ambientColor;
} 