#include"Renderer.h"
#include"VertexBuffer.h"

class VertexArray
{
private:
	unsigned int m_RendererID;
public:
	VertexArray();

	void LinkVBO(VertexBuffer& vbo, unsigned int vertexSize, unsigned int layout, float stride, void* pointer);
	void Bind();
	void UnBind();
	unsigned int GetID();
	void Delete();
};