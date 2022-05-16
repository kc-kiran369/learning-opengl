#include <GLEW/glew.h>
#include <GLFW/glfw3.h>
#include <sstream>
#include"Renderer.h"
#include"VertexBuffer.h"
#include"VertexArray.h"
#include"IndexBuffer.h"
#include"ShaderUtils.h"
#include"Shader.h"
#include"Camera.h"
#include "Texture.h"

#include"glm/glm.hpp"
#include"glm/gtc/matrix_transform.hpp"
#include"glm/gtc/type_ptr.hpp"

#include<stb_image/stb_image.h>

float pyramid[] = {
	//positions					Texture coordinate
	-0.5f, -0.5f,  0.5f,		0.0f,0.0f,
	-0.5f, -0.5f, -0.5f,		1.0f,0.0f,
	 0.5f, -0.5f, -0.5f,		0.0f,0.0f,
	 0.5f, -0.5f,  0.5f,		1.0f,0.0f,
	 0.0f,  0.8f,  0.0f,		0.5f,1.0f
};

unsigned int pyramidIndices[] = {
	0,1,2,
	0,2,3,
	0,1,4,
	1,2,4,
	2,3,4,
	3,0,4
};

int width = 600, height = 600;
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

int main(int argc, char** args)
{
	glfwInit();
	GLFWwindow* window = glfwCreateWindow(width, height, "", NULL, NULL);
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	std::cout << "Version : " << glGetString(GL_VERSION) << std::endl;
	std::cout << "Manufacturer : " << glGetString(GL_RENDERER) << std::endl;

	glewInit();

	VertexBuffer pyramidShape(sizeof(float) * (sizeof(pyramid) / sizeof(float)), pyramid);
	VertexArray VAO;
	VAO.LinkAttrib(pyramidShape, 3, 0, 5 * sizeof(float), nullptr);
	VAO.LinkAttrib(pyramidShape, 2, 1, 5 * sizeof(float), (void*)(sizeof(float) * 3));
	pyramidShape.UnBind();
	IndexBuffer IBO(sizeof(pyramidIndices) / sizeof(unsigned int), pyramidIndices);
	IBO.UnBind();

	Camera camera(width, height, glm::vec3(0.0f, 0.0f, 2.0f));
	Shader shader("shader/default.vert", "shader/default.frag");
	Renderer renderer;

	Texture brickTexture("resources/Brick/Brick_Color.png", 0);
	glUniform1i(glGetUniformLocation(shader.ID, "texture0"), 0);

	glEnable(GL_DEPTH_TEST);

	glm::mat4 model = glm::mat4(1.0f);

	while (!glfwWindowShouldClose(window))
	{
		IBO.Bind();
		brickTexture.Bind();

		camera.Matrix(45.0f, 0.1f, 100.0f, shader, "camMatrix");
		camera.Input(window);

		//model = glm::rotate(model, glm::radians(1.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(glGetUniformLocation(shader.ID, "rot"), 1, GL_FALSE, &model[0][0]);

		renderer.Draw(VAO, IBO);
		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	shader.Delete();
	VAO.Delete();
	glfwTerminate();
	return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}