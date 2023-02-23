#include "Tetragons.h"

GLfloat vert[] = {
	-1.0f, -1.0f, 0.0f,
	1.0f, -1.0f, 0.0f,
	0.0f, 1.0f, 0.0f


};


Tetragons::Tetragons()
{
	Vertex_Holder.push_back(Vertex{ -1.0f, -1.0f, 0.0f,    0.0f, 0.0f, 0.0f });
	Vertex_Holder.push_back(Vertex{ 0.0f, -1.0f, 1.0f,     0.0f, 0.0f, 0.0f  });
	Vertex_Holder.push_back(Vertex{ 1.0f, -1.0f, 0.0f ,     0.0f, 0.0f, 0.0f });
	Vertex_Holder.push_back(Vertex{ 0.0f, 1.0f, 0.0f ,     0.0f, 0.0f, 0.0f });
	
}

Tetragons::~Tetragons()
{
}

void Tetragons::draw()
{
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glDrawArrays(GL_TRIANGLES, 0, Vertex_Holder.size());
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void Tetragons::init()
{
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex)* Vertex_Holder.size(), Vertex_Holder.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);

	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void Tetragons::ClearMesh()
{
}
