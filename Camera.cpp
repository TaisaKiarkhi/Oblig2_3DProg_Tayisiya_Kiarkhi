#include "Camera.h"
#include "Interactive_Object.h"

Camera::Camera() {}

Camera::Camera(glm::vec3 startPosition, glm::vec3 startUp, GLfloat startYaw, GLfloat startPitch, GLfloat startMoveSpeed, GLfloat startTurnSpeed, Interactive_Object i)
{
	position = startPosition;
	worldUp = startUp;
	yaw = startYaw;
	pitch = startPitch;
	front = glm::vec3(0.0f, 0.0f, -1.0f);

	moveSpeed = startMoveSpeed;
	turnSpeed = startTurnSpeed;

	inter = &i;

	update();
}

void Camera::keyControl(bool* keys, GLfloat deltaTime)
{
	GLfloat velocity = moveSpeed * deltaTime;


	//ADD +1 TO POSITION.X AND ETC TO SEE THE INTEROBJECT


if (keys[GLFW_KEY_W])
{
	position += front * velocity;
	inter->model_transform_matrix = glm::translate(glm::mat4(1.0f), position); //position.x +1 etc
}

if (keys[GLFW_KEY_S])
{
	position -= front * velocity;
	inter->model_transform_matrix = glm::translate(glm::mat4(1.0f), position);
}

	if (keys[GLFW_KEY_A])
	{
		position -= right * velocity;
		inter->model_transform_matrix = glm::translate(glm::mat4(1.0f), position);
	}

	if (keys[GLFW_KEY_D])
	{
		position += right * velocity;
		inter->model_transform_matrix = glm::translate(glm::mat4(1.0f), position);
	}
}

void Camera::mouseControl(GLfloat xChange)
{
	xChange *= turnSpeed;
	

	yaw += xChange;
	

	if (pitch > 180.0f)
	{
		pitch = 180.0f;
	}

	if (pitch < -180.0f)
	{
		pitch = -180.0f;
	}

	update();
}

glm::mat4 Camera::calculateViewMatrix()
{
	return glm::lookAt(position, position + front, up);
}

void Camera::update()
{
	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	front.y = sin(glm::radians(pitch));
	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	front = glm::normalize(front);

	right = glm::normalize(glm::cross(front, worldUp));
	up = glm::normalize(glm::cross(right, front));
}


Camera::~Camera()
{
}
