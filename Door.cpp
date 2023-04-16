#include "Door.h"
#include <array>
#include <vector>

Door::Door()
{//                                       x       y      z             r       g    b      u     v
	Vertex_Holder.push_back(Vertex{ 0.51f,  0.3f,  0.3f,       0.588f, 0.69f, 1.0f,  0.0f, 0.0f,   0.0f, 0.0f, 0.0f });
	Vertex_Holder.push_back(Vertex{ 0.51f,  0.3f, -0.3f,       0.588f, 0.69f, 1.0f,  0.0f, 0.0f,   0.0f, 0.0f, 0.0f });
	Vertex_Holder.push_back(Vertex{ 0.51f, -0.5f, -0.3f,       0.588f, 0.69f, 1.0f,  0.0f, 0.0f,   0.0f, 0.0f, 0.0f });
	Vertex_Holder.push_back(Vertex{ 0.51f, -0.5f, -0.3f,       0.588f, 0.69f, 1.0f,  0.0f, 0.0f,   0.0f, 0.0f, 0.0f });
	Vertex_Holder.push_back(Vertex{ 0.51f, -0.5f,  0.3f,       0.588f, 0.69f, 1.0f,  0.0f, 0.0f,   0.0f, 0.0f, 0.0f });
    Vertex_Holder.push_back(Vertex{ 0.51f,  0.3f,  0.3f,       0.588f, 0.69f, 1.0f,  0.0f, 0.0f,   0.0f, 0.0f, 0.0f });
	
	indices.insert(indices.end(), { 0,1,2,2,3,0 });
}

Door::~Door()
{
}




void Door::draw()
{
	glBindVertexArray(VAO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, VBO);
	//glBindBuffer(GL_ARRAY_BUFFER, IBO);



	glDrawArrays(GL_TRIANGLES, Vertex_Holder.size(),0);

	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void Door::init()
{
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * Vertex_Holder.size(), Vertex_Holder.data(), GL_STATIC_DRAW);
	//glGenBuffers(1, &IBO);
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size()*sizeof(GLuint), indices.data(), GL_STATIC_DRAW);
	
	


	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(8 * sizeof(GLfloat)));
	glEnableVertexAttribArray(3);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	
	glBindVertexArray(0);
}
