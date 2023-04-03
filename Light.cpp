
#include "Light.h"

Light::Light(GLfloat red, GLfloat green, GLfloat blue, GLfloat intensity, GLfloat x_dir, GLfloat y_dir
	, GLfloat z_dir, GLfloat d_intensity)
{
	color = glm::vec3(red, green, blue);
	ambient_intens = intensity;

	direction = glm::vec3(x_dir, y_dir, z_dir);
	diffuse_intens = d_intensity;
}

void Light::use_light(GLfloat ambient_intens_loc, GLfloat color_loc, GLfloat d_intensity_loc, GLfloat direction_loc)
{
	glUniform3f(color_loc, color.x, color.y, color.z);
	glUniform1f(ambient_intens_loc, ambient_intens);
	glUniform3f(direction_loc, direction.x, direction.y, direction.z);
	glUniform1f(d_intensity_loc, diffuse_intens);

}

Light::~Light()
{
}
