#include"Camera.h"

Camera::Camera(int _width, int _height, glm::vec3 _position)
{
	Camera::width = _width;
	Camera::height = _height;
	Position = _position;
}

void Camera::Matrix(float _FOVdeg, float _nearPlane, float _farPlane, Shader& _shader, const char* _uniform)
{
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 projection = glm::mat4(1.0f);

	view = glm::lookAt(Position, Position + Orientation, Up);
	projection = glm::perspective(glm::radians(_FOVdeg), (float)(width / height), _nearPlane, _farPlane);

	glUniformMatrix4fv(glGetUniformLocation(_shader.ID, _uniform), 1, GL_FALSE, glm::value_ptr(projection * view));
}

void Camera::Input(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		Position += speed * Orientation;
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		Position += speed * speed * -glm::normalize(glm::cross(Orientation, Up));
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		Position += speed * -Orientation;
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		Position += speed * glm::normalize(glm::cross(Orientation, Up));
	}
}
