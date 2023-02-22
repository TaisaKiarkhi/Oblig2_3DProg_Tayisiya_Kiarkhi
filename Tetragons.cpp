#include "Tetragons.h"

GLfloat vert[] = {
	-1.0f, -1.0f, 0.0f,
	1.0f, -1.0f, 0.0f,
	0.0f, 1.0f, 0.0f
};


Tetragons::Tetragons()
{
	VAOs = 0;
	VBOs = 0;
}

Tetragons::~Tetragons()
{
}

void Tetragons::draw()
{
	glBindVertexArray(VAOs);
	glBindBuffer(GL_ARRAY_BUFFER, VBOs);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void Tetragons::init()
{
	glGenVertexArrays(1, &VAOs);
	glBindVertexArray(VAOs);
	glGenBuffers(1, &VBOs);
	glBindBuffer(GL_ARRAY_BUFFER, VBOs);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vert), &vert, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void Tetragons::ClearMesh()
{
}
