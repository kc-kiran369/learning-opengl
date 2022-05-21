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
	-0.5f, -0.5f,  0.5f,		0.0f,   0.0f,
	-0.5f, -0.5f, -0.5f,		1.0f,   0.0f,
	 0.5f, -0.5f, -0.5f,		0.0f,   0.0f,
	 0.5f, -0.5f,  0.5f,		1.0f,   0.0f,
	 0.0f,  0.8f,  0.0f,		0.5f,   1.0f
};

unsigned int pyramidIndices[] = {
	0,1,2,
	0,2,3,
	0,1,4,
	1,2,4,
	2,3,4,
	3,0,4
};

GLfloat lightVertices[] =
{
	-0.05f, -0.05f,  0.05f,
	-0.05f, -0.05f, -0.05f,
	 0.05f, -0.05f, -0.05f,
	 0.05f, -0.05f,  0.05f,
	-0.05f,  0.05f,  0.05f,
	-0.05f,  0.05f, -0.05f,
	 0.05f,  0.05f, -0.05f,
	 0.05f,  0.05f,  0.05f
};

GLuint lightIndices[] =
{
	0, 1, 2,
	0, 2, 3,
	0, 4, 7,
	0, 7, 3,
	3, 7, 6,
	3, 6, 2,
	2, 6, 5,
	2, 5, 1,
	1, 5, 4,
	1, 4, 0,
	4, 5, 6,
	4, 6, 7
};

int width = 600, height = 600;
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

int main(int argc, char* argv[])
{
	glfwInit();
	GLFWwindow* window = glfwCreateWindow(width, height, glfwGetVersionString(), NULL, NULL);
	std::cout << argv[0] << std::endl;
	if (!window)
	{
		std::cout << "Window not created.." << std::endl;
		return 1;
	}
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	std::cout << "Version : " << glGetString(GL_VERSION) << std::endl;
	std::cout << "Manufacturer : " << glGetString(GL_RENDERER) << std::endl;

	glewInit();

	Shader defaultShader("shader/default.vert", "shader/default.frag");
	VertexArray VAO;
	VertexBuffer VBO(sizeof(float) * (sizeof(pyramid) / sizeof(float)), pyramid);
	IndexBuffer IBO(sizeof(pyramidIndices) / sizeof(unsigned int), pyramidIndices);
	VAO.LinkAttrib(VBO, 3, 0, 5 * sizeof(float), nullptr);
	VAO.LinkAttrib(VBO, 2, 1, 5 * sizeof(float), (void*)(sizeof(float) * 3));
	VBO.UnBind();
	IBO.UnBind();
	VAO.UnBind();

	Shader lightShader("shader/light.vert", "shader/light.frag");
	VertexArray lightVAO;
	lightVAO.Bind();
	VertexBuffer lightVBO(sizeof(lightVertices), lightVertices);
	IndexBuffer lightEBO(sizeof(lightIndices) / sizeof(unsigned int), lightIndices);
	lightVAO.LinkAttrib(lightVBO, 3, 0, sizeof(float) * 3, nullptr);
	lightVAO.UnBind();
	lightVBO.UnBind();
	lightEBO.UnBind();

	Camera camera(width, height, glm::vec3(0.0f, 0.0f, 2.0f));
	Renderer renderer;

	defaultShader.Activate();
	Texture brickTexture("resources/Brick/Brick_Color.png", 0);
	glUniform1i(glGetUniformLocation(defaultShader.ID, "texture0"), 0);

	glEnable(GL_DEPTH_TEST);

	glm::mat4 model = glm::mat4(1.0f);
	glm::vec4 lightColor = glm::vec4(1.0f, 0.5f, 0.25f, 1.0f);

	while (!glfwWindowShouldClose(window))
	{
		renderer.Clear();

		camera.Input(window);
		camera.UpdateMatrix(60.0f, 0.1f, 100.0f);

		brickTexture.Bind();
		defaultShader.Activate();
		camera.Matrix(defaultShader, "MVP", &model[0][0], lightColor);
		VAO.Bind();
		renderer.Draw(VAO, IBO);

		lightShader.Activate();
		camera.Matrix(lightShader, "MVP", &model[0][0], lightColor);
		lightVAO.Bind();
		renderer.Draw(lightVAO, lightEBO);

		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	defaultShader.Delete();
	lightShader.Delete();
	VAO.Delete();
	lightVAO.Delete();
	glfwTerminate();
	return 0;

}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}