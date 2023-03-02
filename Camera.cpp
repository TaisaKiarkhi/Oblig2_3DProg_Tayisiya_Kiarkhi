#include "Camera.h"
#include "Interactive_Object.h"
#include "Door.h"




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

	temp = position;
	if (keys[GLFW_KEY_W])
	{
		position += front * velocity;
		//inter->model_transform_matrix = glm::translate(glm::mat4(1.0f), glm::vec3(position.x+1, position.y + 1, position.z + 1) ); //position.x +1 etc
		temp = position;
	}

	if (keys[GLFW_KEY_S])
	{
		position -= front * velocity;
		//inter->model_transform_matrix = glm::translate(glm::mat4(1.0f), glm::vec3(position.x + 1, position.y + 1, position.z + 1));
		temp = position;
	}

	if (keys[GLFW_KEY_A])
	{
		position -= right * velocity;
		//inter->model_transform_matrix = glm::translate(glm::mat4(1.0f), glm::vec3(position.x + 1, position.y + 1, position.z + 1));
		temp = position;
	}

	if (keys[GLFW_KEY_D])
	{
		position += right * velocity;
		//inter->model_transform_matrix = glm::translate(glm::mat4(1.0f), glm::vec3(position.x + 1, position.y + 1, position.z + 1));
		temp = position;
	}




//if (keys[GLFW_KEY_H]) {
//	//	
//	//	//-14 1  -14
//	if (inside == false) {
//		current_pos.x = -14.0f;
//		current_pos.y = 1.0f;
//		current_pos.z = -14.0f;
//		position = current_pos;
//		current_pos = temp;
//		inside = true;
//	}
//	//
//	else if (inside == true) {
//		position = current_pos;
//		inside = false;
//	}
//}
}


void Camera::key_h_contro(bool* key) {
	if (key[GLFW_KEY_H]) {
		//	
		//	//-14 1  -14

		if (inside == false) {
			current_pos.x = -14.0f;
			current_pos.y = 1.0f;
			current_pos.z = -14.0f;
			position = current_pos;
			current_pos = temp;
			inside = true;
		}

		else if ( inside == true) {

			position = current_pos;
			inside = false;


		}
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
	return glm::lookAt(position, (position + front), up);
}

glm::mat4 Camera::calculateViewMatrix(glm::vec3 a)
{
	return glm::lookAt(a, (a+ front), up);
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
