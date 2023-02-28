#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "VisualObject.h"
#include <vector>
#include <Vertex.h>
#include <glm/glm/mat4x4.hpp>

VisualObject::VisualObject()
{
}

VisualObject::~VisualObject()
{
	if (VBO != 0) {
		glDeleteBuffers(1, &VBO);
		VBO = 0;
	}


	if (VAO != 0) {
		glDeleteVertexArrays(1, &VAO);
		VAO = 0;
	}
}

void VisualObject::draw()
{
}

void VisualObject::init()
{

}
