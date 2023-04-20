#include "Interactive_Object.h"
#include <Camera.h>

Interactive_Object::Interactive_Object()
{
	Vertex_Holder.push_back(Vertex{ 0.0f, 1.0f, 0.0f,      1.0f, 0.843f, 0.0f,     0.0f, 0.0f,   0.0f, 0.0f, 0.0f });
	Vertex_Holder.push_back(Vertex{ 1.0f, -1.0f, 1.0f,     1.0f, 0.843f, 0.0f,     0.0f, 0.0f,   0.0f, 0.0f, 0.0f });
	Vertex_Holder.push_back(Vertex{ -1.0f, -1.0f, 1.0f,    1.0f, 0.843f, 0.0f,     0.0f, 0.0f,   0.0f, 0.0f, 0.0f });
																			 
																			 
	Vertex_Holder.push_back(Vertex{ 0.0f, 1.0f, 0.0f,      1.0f, 0.843f, 0.0f,    0.0f,0.0f,   0.0f, 0.0f, 0.0f });
	Vertex_Holder.push_back(Vertex{ 0.0f, -1.0f, -1.0f,    1.0f, 0.843f, 0.0f,    0.0f,0.0f,   0.0f, 0.0f, 0.0f });
	Vertex_Holder.push_back(Vertex{ 1.0f, -1.0f, 1.0f,     1.0f, 0.843f, 0.0f,    0.0f,0.0f,   0.0f, 0.0f, 0.0f });
																				  	   
																				  	   
	Vertex_Holder.push_back(Vertex{ 0.0f, 1.0f, 0.0f,      1.0f, 0.843f, 0.0f,    0.0f,0.0f,  0.0f,0.0f,0.0f });
	Vertex_Holder.push_back(Vertex{ -1.0f, -1.0f, 1.0f,    1.0f, 0.843f, 0.0f,    0.0f,0.0f,  0.0f,0.0f,0.0f });
	Vertex_Holder.push_back(Vertex{ 0.0f, -1.0f, -1.0f,    1.0f, 0.843f, 0.0f,    0.0f,0.0f,  0.0f,0.0f,0.0f });
																					   
	Vertex_Holder.push_back(Vertex{ -1.5f, -0.9f, -1.5f,      0.55f, 0.92f, 0.196f,   0.0f, 0.0f,  0.0f, 0.0f, 0.0f });
	Vertex_Holder.push_back(Vertex{  1.5f, -0.9f, -1.5f,      0.55f, 0.92f, 0.196f,   0.0f, 0.0f,  0.0f, 0.0f, 0.0f });
	Vertex_Holder.push_back(Vertex{  1.5f, -0.9f,  1.5f,      0.55f, 0.92f, 0.196f,   0.0f, 0.0f,  0.0f, 0.0f, 0.0f });
	Vertex_Holder.push_back(Vertex{  1.5f, -0.9f,  1.5f,      0.55f, 0.92f, 0.196f,   0.0f, 0.0f,  0.0f, 0.0f, 0.0f });
	Vertex_Holder.push_back(Vertex{ -1.5f, -0.9f,  1.5f,      0.55f, 0.92f, 0.196f,   0.0f, 0.0f,  0.0f, 0.0f, 0.0f });
	Vertex_Holder.push_back(Vertex{ -1.5f, -0.9f, -1.5f,      0.55f, 0.92f, 0.196f,   0.0f, 0.0f,  0.0f, 0.0f, 0.0f });
	
	position_holder_x[0] = Vertex_Holder.at(8).xyz_values.x;
	position_holder_x[1] = Vertex_Holder.at(9).xyz_values.x;
	position_holder_x[2] = Vertex_Holder.at(10).xyz_values.x;
	position_holder_x[3] = Vertex_Holder.at(12).xyz_values.x;

	position_holder_y[0] = Vertex_Holder.at(8).xyz_values.y;
	position_holder_y[1] = Vertex_Holder.at(9).xyz_values.y;
	position_holder_y[2] = Vertex_Holder.at(10).xyz_values.y;
	position_holder_y[3] = Vertex_Holder.at(12).xyz_values.y;
}

Interactive_Object::~Interactive_Object()
{
}

void Interactive_Object::draw()
{
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);


	glDrawArrays(GL_TRIANGLES, 0, Vertex_Holder.size());
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void Interactive_Object::init()
{
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * Vertex_Holder.size(), Vertex_Holder.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(8 * sizeof(GLfloat)));
	glEnableVertexAttribArray(3);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}


