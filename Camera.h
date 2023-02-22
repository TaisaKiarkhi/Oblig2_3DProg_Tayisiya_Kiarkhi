#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm/glm.hpp>
#include <glm/glm/ext/matrix_transform.hpp>
class Camera
{
public:
	Camera(glm::vec3 start_position, glm::vec3 start_up, GLfloat start_yaw, GLfloat start_pitch, GLfloat start_move_speed, GLfloat start_turn_speed);
	~Camera();

	glm::vec3 up;
	glm::vec3 front;
	glm::vec3 position;
	glm::vec3 right;

	glm::vec3 WorldUp;

	GLfloat yaw;
	GLfloat pitch;
	GLfloat move_speed; 
	GLfloat turn_speed; //mouse thing

	void update();

};

