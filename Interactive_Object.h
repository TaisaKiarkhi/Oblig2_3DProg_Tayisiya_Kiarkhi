#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h> 
#include <VisualObject.h>
#include <glm/glm/glm.hpp>
#include <glm/glm/ext/matrix_transform.hpp>
#include <glm/glm/gtx/transform.hpp>
class Interactive_Object : public VisualObject
{
public:
	Interactive_Object();
	Interactive_Object(glm::vec3 startPosition, glm::vec3 startUp, GLfloat startYaw, GLfloat startPitch, GLfloat startMoveSpeed, GLfloat startTurnSpeed);
	~Interactive_Object();

	void draw() override;
	void init() override;



	void keyControl(bool* keys, GLfloat deltaTime);
	void mouseControl(GLfloat xChange);

	GLfloat yaw;
	GLfloat pitch;

	GLfloat moveSpeed;
	GLfloat turnSpeed;

	glm::vec3 position;
	glm::vec3 front;
	glm::vec3 up;
	glm::vec3 right;
	glm::vec3 worldUp;

	void update();

	void move(float m_x, float m_z);

	//float x_move, z_move;
};

