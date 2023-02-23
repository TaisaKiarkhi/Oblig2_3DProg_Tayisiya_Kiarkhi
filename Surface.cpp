#include "Surface.h"



Surface::Surface()
{
	

	Vertex_Holder.push_back(Vertex{ -1.0f, -1.0f, 0.0f,    0.0f, 0.0f, 0.0f });
	Vertex_Holder.push_back(Vertex{ 1.0f, -1.0f, 0.0f,     0.0f, 0.0f, 0.0f });
	Vertex_Holder.push_back(Vertex{ 0.0f, 1.0f, 0.0f ,     0.0f, 0.0f, 0.0f });

	
}

Surface::~Surface()
{
	ClearMesh();
}

void Surface::draw()
{

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), &verts, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void Surface::init()
{
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void Surface::ClearMesh()
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
