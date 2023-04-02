
#include "Light.h"

Light::Light(GLfloat red, GLfloat green, GLfloat blue, GLfloat intensity)
{
	color = glm::vec3(red, green, blue);
	ambient_intens = intensity;
}

void Light::use_light(GLfloat ambient_intens_loc, GLfloat color_loc)
{
	glUniform3f(color_loc, color.x, color.y, color.z);
	glUniform1f(ambient_intens_loc, ambient_intens);

}

Light::~Light()
{
}
