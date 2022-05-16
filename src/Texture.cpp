#include "Texture.h"

Texture::Texture(const char* path, unsigned int slot)
{
	glGenTextures(1, &m_RendererID);
	glBindTexture(GL_TEXTURE_2D, m_RendererID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	int width, height, channel;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data = stbi_load(path, &width, &height, &channel, 0);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	glActiveTexture(GL_TEXTURE0 + slot);
	glGenerateMipmap(GL_TEXTURE_2D);
	if (data)
		stbi_image_free(data);
	else
		std::cout << "Image Not loaded..." << std::endl;
	glBindTexture(GL_TEXTURE_2D, 0);
}

Texture::~Texture()
{
	glDeleteTextures(1, &m_RendererID);
}

void Texture::Bind()
{
	glBindTexture(GL_TEXTURE_2D, m_RendererID);
}

void Texture::UnBind()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

unsigned int Texture::GetRendererID()
{
	return m_RendererID;
}
