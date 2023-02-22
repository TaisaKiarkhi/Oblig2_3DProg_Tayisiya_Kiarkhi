#include "Camera.h"

Camera::Camera(glm::vec3 start_position, glm::vec3 start_up, GLfloat start_yaw, GLfloat start_pitch, GLfloat start_move_speed, GLfloat start_turn_speed)
{
	position = start_position;
	up = start_up;
	yaw = start_yaw;
	pitch = start_pitch;
	front = glm::vec3(0.0f, 0.0f, -1.0f);

	move_speed = start_move_speed;
	turn_speed = start_turn_speed;
}

Camera::~Camera()
{

}

void Camera::update()
{
	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	front.y = sin(glm::radians(pitch));
	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	front = glm::normalize(front);

	right = glm::normalize(glm::cross(front, WorldUp));
	up= glm::normalize(glm::cross(right, front));
}
