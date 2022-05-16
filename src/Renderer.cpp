#include "Renderer.h"

void Renderer::Draw(VertexArray& vao, IndexBuffer& ibo)
{
	glClearColor(26.0f / 255.0f, 26.0f / 255.0f, 26.0f / 255.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_DEPTH_BUFFER_BIT);

	vao.Bind();
	ibo.Bind();

	glDrawElements(GL_TRIANGLES, ibo.GetCount(), GL_UNSIGNED_INT, nullptr);
}
