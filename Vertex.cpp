#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Vertex.h"
#include <vector>

Vertex::Vertex(float x, float y, float z, float r, float g, float b, float u, float v)
{

	xyz_values= glm::vec3 ( x, y, z);
	rgb_values= glm::vec3(r, g, b);
	uv_values = glm::vec2(u, v);

}
