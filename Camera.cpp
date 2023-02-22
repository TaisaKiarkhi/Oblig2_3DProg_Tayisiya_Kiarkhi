#include "Camera.h"

Camera::Camera(glm::vec3 start_position, glm::vec3 start_up, GLfloat start_yaw, GLfloat start_pitch, GLfloat start_move_speed, GLfloat start_turn_speed)
{
	position = start_position;
	WorldUp = start_up;
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

void Camera::Key_Controll(bool* keys, GLfloat delta)
{
	GLfloat velocity = move_speed * delta;
	if (keys[GLFW_KEY_W]) {
		position += front * velocity;

	}
	if (keys[GLFW_KEY_S]) {
		position -= front * velocity;

	}
	if (keys[GLFW_KEY_A]) {
		position -= right * velocity;

	}
	if (keys[GLFW_KEY_D]) {
		position += right * velocity;

	}
}

void Camera::Mouse_Controll(GLfloat x_move, GLfloat y_move)
{
	x_move *= turn_speed;
	y_move *= turn_speed;

	yaw += x_move;
	pitch += y_move;

	if (pitch > 89.0f) {
		pitch = 89.0f;
	}

	if (pitch < -89.0f) {
		pitch = -89.0f;
	}
}

glm::mat4 Camera::view_matrix_calc()
{
	return glm::lookAt(position, position + front, up);
	
}
