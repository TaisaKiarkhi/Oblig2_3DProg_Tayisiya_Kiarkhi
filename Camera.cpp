#include "Camera.h"

Camera::Camera()
{
	view_direction = glm::vec3(0.0f, 0.0f, -1.0f);
	up = glm::vec3(0.0f, 1.0f, 0.0f);
	position = glm::vec3(0.0f, 0.0f, 1.0f);
}

Camera::~Camera()
{
}

glm::mat4 Camera::getWorldToViewMatrix() const
{
	return glm::lookAt(position, position + view_direction, up);
}
