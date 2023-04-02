#pragma once
#include <GL/glew.h>
#include <glm/glm/glm.hpp>
class Light
{
public:
	Light(GLfloat red, GLfloat green, GLfloat blue, GLfloat intensity);
	void use_light (GLfloat ambient_intens_loc, GLfloat color_loc);
	~Light();

private:
	glm::vec3 color;
	GLfloat ambient_intens;

};

