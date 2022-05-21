#include"IndexBuffer.h"

IndexBuffer::IndexBuffer(unsigned int count, void* data)
{
	glGenBuffers(1, &m_RendererID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW);
	m_Count = count;
}

IndexBuffer::~IndexBuffer()
{
	glDeleteBuffers(GL_ELEMENT_ARRAY_BUFFER, &m_RendererID);
}

void IndexBuffer::Bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
}

void IndexBuffer::UnBind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

unsigned int IndexBuffer::GetRendererID()
{
	return m_RendererID;
}

unsigned int IndexBuffer::GetCount()
{
	return m_Count;
}
