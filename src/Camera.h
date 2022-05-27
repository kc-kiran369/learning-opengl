#ifndef CAMERA_CLASS_H
#define CAMERA_CLASS_H

#include"GLEW/glew.h"
#include"GLFW/glfw3.h"
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include<glm/gtx/rotate_vector.hpp>
#include<glm/gtx/vector_angle.hpp>
#include"Shader.h"

class Camera
{
public:
	glm::vec3 Position;
	glm::vec3 Orientation = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 Up = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::mat4 cameraMatrix = glm::mat4(1.0f);

	bool firstClick = true;

	int width, height;

	float speed = 0.05f;
	float sensitivity = 30.0f;

	Camera(int _width, int _height, glm::vec3 _position);

	void UpdateMatrix(float _FOVdeg, float _nearPlane, float _farPlane);
	void Matrix(Shader& shader, const char* uniform, const float* modelMat, glm::vec4 lightColor);
	void Input(GLFWwindow* window);
};
#endif