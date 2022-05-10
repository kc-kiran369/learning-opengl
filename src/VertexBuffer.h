#pragma once
#include"Renderer.h"

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