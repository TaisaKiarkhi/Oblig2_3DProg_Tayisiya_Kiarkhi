#include "Interactive_Object.h"
#include <Camera.h>

Interactive_Object::Interactive_Object(glm::vec3 startPosition, glm::vec3 startUp, GLfloat startYaw, GLfloat startPitch, GLfloat startMoveSpeed, GLfloat startTurnSpeed)
{
	Vertex_Holder.push_back(Vertex{ 0.0f, 1.0f, 0.0f,      1.0f, 1.0f, 1.0f });
	Vertex_Holder.push_back(Vertex{ 1.0f, -1.0f, 1.0f,     1.0f, 1.0f, 1.0f });
	Vertex_Holder.push_back(Vertex{ -1.0f, -1.0f, 1.0f,    1.0f, 1.0f, 1.0f });


	Vertex_Holder.push_back(Vertex{ 0.0f, 1.0f, 0.0f,      1.0f, 1.0f, 1.0f });
	Vertex_Holder.push_back(Vertex{ 0.0f, -1.0f, -1.0f,    1.0f, 1.0f, 1.0f });
	Vertex_Holder.push_back(Vertex{ 1.0f, -1.0f, 1.0f,     1.0f, 1.0f, 1.0f });


	Vertex_Holder.push_back(Vertex{ 0.0f, 1.0f, 0.0f,      1.0f, 1.0f, 1.0f });
	Vertex_Holder.push_back(Vertex{ -1.0f, -1.0f, 1.0f,    1.0f, 1.0f, 1.0f });
	Vertex_Holder.push_back(Vertex{ 0.0f, -1.0f, -1.0f,    1.0f, 1.0f, 1.0f });


	position = startPosition;
	worldUp = startUp;
	yaw = startYaw;
	pitch = startPitch;
	front = glm::vec3(0.0f, 0.0f, -1.0f);

	moveSpeed = startMoveSpeed;
	turnSpeed = startTurnSpeed;
	
	update();
}

Interactive_Object::~Interactive_Object()
{
}

void Interactive_Object::draw()
{
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);


	glDrawArrays(GL_TRIANGLES, 0, Vertex_Holder.size());
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void Interactive_Object::init()
{
glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * Vertex_Holder.size(), Vertex_Holder.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void Interactive_Object::keyControl(bool* keys, GLfloat deltaTime)
{
	GLfloat velocity = moveSpeed * deltaTime;

	if (keys[GLFW_KEY_W])
	{
		position += front * velocity;
	}

	if (keys[GLFW_KEY_S])
	{
		position -= front * velocity;
	}

	if (keys[GLFW_KEY_A])
	{
		position -= right * velocity;
	}

	if (keys[GLFW_KEY_D])
	{
		position += right * velocity;
	}
}


void Interactive_Object::update()
{
	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	front.y = sin(glm::radians(pitch));
	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	front = glm::normalize(front);

	right = glm::normalize(glm::cross(front, worldUp));
	up = glm::normalize(glm::cross(right, front));
}


void Interactive_Object ::mouseControl(GLfloat xChange)
{
	xChange *= turnSpeed;
	//yChange *= turnSpeed;

	yaw += xChange;
	//pitch += yChange;

	if (yaw > 180.0f)
	{
		yaw = 180.0f;
	}

	if (yaw < -180.0f)
	{
		yaw = -180.0f;
	}

	update();
}
