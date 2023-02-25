#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm/glm.hpp>
#include <glm/glm/ext/matrix_transform.hpp>
#include <glm/glm/gtx/transform.hpp>
class Camera
{
public:
	Camera();
	~Camera();

	glm::vec3 position;
	glm::vec3 view_direction;
	 glm::vec3 up;

	glm::mat4 getWorldToViewMatrix() const;




};

