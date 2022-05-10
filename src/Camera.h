#ifndef CAMERA_CLASS_H
#define CAMERA_CLASS_H

#include"Renderer.h"
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

	int width, height;

	float speed = 0.1f;
	float sensitivity = 100.0f;

	Camera(int _width, int _height, glm::vec3 _position);

	void Matrix(float _FOVdeg, float _nearPlane, float _farPlane, Shader& _shader, const char* _uniform);
	void Input(GLFWwindow* window);
};
#endif