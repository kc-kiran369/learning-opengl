#include"Renderer.h"
#include"VertexBuffer.h"
#include"VertexArray.h"
#include"IndexBuffer.h"
#include"ShaderUtils.h"
#include"Shader.h"
#include"Camera.h"

#include"glm/glm.hpp"
#include"glm/gtc/matrix_transform.hpp"
#include"glm/gtc/type_ptr.hpp"

#include<stb_image/stb_image.h>

float positions[] = {
	//positions			//colors			//texture coordinate
	-0.5f, 0.0f, 0.0f,	 0.0f, 0.0f, 1.0f,	0.0f,0.0f,
	-0.5f, 0.0f,-0.5f,	 1.0f, 0.0f, 0.0f,	5.0f,0.0f,
	 0.5f, 0.0f,-0.5f,	 1.0f, 0.0f, 0.0f,	0.0f,0.0f,
	 0.5f, 0.0f, 0.5f,	 1.0f, 0.0f, 0.0f,	5.0f,0.0f,
	 0.0f, 0.8f, 0.0f,   1.0f, 0.0f, 0.0f,	2.5f,5.0f
};

unsigned int indices[] = {
	0,1,2,
	0,2,3,
	0,1,4,
	1,2,4,
	2,3,4,
	3,0,4
};

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

int main()
{

	glfwInit();
	GLFWwindow* window = glfwCreateWindow(800, 800, "N A N I", NULL, NULL);
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	std::cout << "Version : " << glGetString(GL_VERSION) << std::endl;
	std::cout << "Manufacturer : " << glGetString(GL_RENDERER) << std::endl;

	glewInit();

	VertexBuffer shape(sizeof(float) * (sizeof(positions) / sizeof(float)), positions);
	VertexArray VAO;
	VAO.LinkVBO(shape, 3, 0, 8 * sizeof(float), nullptr);
	VAO.LinkVBO(shape, 3, 1, 8 * sizeof(float), (void*)(sizeof(float) * 3));
	VAO.LinkVBO(shape, 2, 2, 8 * sizeof(float), (void*)(sizeof(float) * 6));
	IndexBuffer IBO(sizeof(indices) / sizeof(unsigned int), indices);

	shape.UnBind();
	IBO.UnBind();

	Shader shader;
	Camera camera(800, 800, glm::vec3(0.0f, 0.0f, 5.0f));
	IBO.Bind();

	unsigned int texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	int width, height, channel;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data = stbi_load("resources\\steve.png", &width, &height, &channel, 0);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else {
		std::cout << "Image Not loaded" << std::endl;
	}
	stbi_image_free(data);
	glActiveTexture(GL_TEXTURE0);

	//glUniform1i(glGetUniformLocation(shader.ID, "texture01"), texture);

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(56.0f / 255.0f, 56.0f / 255.0f, 56.0f / 255.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		camera.Matrix(45.0f, 0.0f, 100.0f, shader, "camMatrix");
		camera.Input(window);
		glBindTexture(GL_TEXTURE_2D, texture);
		glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(unsigned int), GL_UNSIGNED_INT, nullptr);

		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	shader.Delete();
	glfwTerminate();
	return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}