#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Vertex.h"
#include <vector>

Vertex::Vertex(float x, float y, float z, float r, float g, float b)
{

	xyz_values.push_back(x);
	xyz_values.push_back(y);
	xyz_values.push_back(z);

	rgb_values.push_back(r);
	rgb_values.push_back(g);
	rgb_values.push_back(b);

}
