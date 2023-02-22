#include "Surface.h"

GLfloat verts[] = {

	  -1.0f, -1.0f, 0.0f,
	1.0f, -1.0f, 0.0f,
	0.0f, 1.0f, 0.0f
};

Surface::Surface()
{
	


	VAOs = 0;
	VBOs = 0;
}

Surface::~Surface()
{
	ClearMesh();
}

void Surface::draw()
{

	glGenVertexArrays(1, &VAOs);
	glBindVertexArray(VAOs);
	glGenBuffers(1, &VBOs);
	glBindBuffer(GL_ARRAY_BUFFER, VBOs);

	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), &verts, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void Surface::init()
{
	glBindVertexArray(VAOs);
	glBindBuffer(GL_ARRAY_BUFFER, VBOs);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void Surface::ClearMesh()
{


	if (VBOs != 0) {
		glDeleteBuffers(1, &VBOs);
		VBOs = 0;
	}


	if (VAOs != 0) {
		glDeleteVertexArrays(1, &VAOs);
		VAOs = 0;
	}
}
