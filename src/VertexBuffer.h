#ifndef VERTEX_BUFFER_CLASS_H
#define VERTEX_BUFFER_CLASS_H

#include "glew/glew.h"

class VertexBuffer
{
private:
	unsigned int m_RendererID;
public:
	VertexBuffer(unsigned int size, void* data);
	~VertexBuffer();

	void Bind();
	void UnBind();
};
#endif