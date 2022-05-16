#ifndef RENDERER_CLASS_H
#define RENDERER_CLASS_H

#include"VertexArray.h"
#include"IndexBuffer.h"

class Renderer
{
public:
	void Draw(VertexArray& vao,IndexBuffer& ibo);
};

#endif // !RENDERER_CLASS_H