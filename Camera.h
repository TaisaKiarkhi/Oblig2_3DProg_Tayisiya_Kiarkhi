#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm/glm.hpp>
#include <glm/glm/ext/matrix_transform.hpp>
#include <glm/glm/gtx/transform.hpp>
#include "Interactive_Object.h"
class Camera
{
public:
	Camera();
	Camera(glm::vec3 startPosition, glm::vec3 startUp, GLfloat startYaw, GLfloat startPitch, GLfloat startMoveSpeed, GLfloat startTurnSpeed, Interactive_Object i);

	void keyControl(bool* keys, GLfloat deltaTime);
	
	void key_h_contro(bool* key);

	void mouseControl(GLfloat xChange);

	glm::mat4 calculateViewMatrix();
	glm::mat4 calculateViewMatrix(glm::vec3 a);

	~Camera();

	Interactive_Object *inter;
	

public:
	glm::vec3 position;
	glm::vec3 front;
	glm::vec3 up;
	glm::vec3 right;
	glm::vec3 worldUp;
	glm::mat4 rotate_the_door;

	GLfloat yaw;
	GLfloat pitch;

	GLfloat moveSpeed;
	GLfloat turnSpeed;

	void update();

	bool inside = false;

	glm::vec3 current_pos;
	glm::vec3 temp;

};

