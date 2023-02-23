#include "Surface.h"



Surface::Surface()
{
	
	Vertex_Holder.push_back(Vertex{ 0.0,0.0,0.0, 1,0,0 });
	Vertex_Holder.push_back(Vertex{ 0.5, 0.0, 0.0, 0, 1, 0 });
	Vertex_Holder.push_back(Vertex{ 0.5,0.5,0.0, 0,0,1 });

	Vertex_Holder.push_back(Vertex{ 0.0,0.0,0.0, 0,0,0 });
	Vertex_Holder.push_back(Vertex{ 0.5,0.5,0.0, 0,0,0 });
	Vertex_Holder.push_back(Vertex{ 0.0,0.5,0.0, 0,0,0 });

	
}

Surface::~Surface()
{
	ClearMesh();
}

void Surface::draw()
{
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glDrawArrays(GL_TRIANGLES, 0, 6 );
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	
}

void Surface::init()

{
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * Vertex_Holder.size(), Vertex_Holder.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);

	glEnableVertexAttribArray(0);

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
