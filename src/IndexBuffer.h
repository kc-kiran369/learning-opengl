#include"Renderer.h"

class IndexBuffer
{
private:
	unsigned int m_RendererID;
public:
	IndexBuffer(unsigned int count, void* data);
	~IndexBuffer();

	void Bind();
	void UnBind();

	unsigned int GetRendererID();
};