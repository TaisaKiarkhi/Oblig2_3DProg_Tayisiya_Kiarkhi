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
	~Interactive_Object();

	void draw() override;
	void init() override;

	glm::mat4 model_transform_matrix = glm::translate(glm::mat4(1.0f), glm::vec3(x_change, 0.0, y_change));

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

