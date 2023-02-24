#include "Surface.h"



Surface::Surface()
{
	
//	Vertex_Holder.push_back(Vertex{ 0.0,0.0,0.0, 1,0,0 });
//	Vertex_Holder.push_back(Vertex{ 0.5, 0.0, 0.0, 0, 1, 0 });
//	Vertex_Holder.push_back(Vertex{ 0.5,0.5,0.0, 0,0,1 });
//
//	Vertex_Holder.push_back(Vertex{ 0.0,0.0,0.0, 0,0,0 });
//	Vertex_Holder.push_back(Vertex{ 0.5,0.5,0.0, 0,0,0 });
//	Vertex_Holder.push_back(Vertex{ 0.0,0.5,0.0, 0,0,0 });

	construct();
}

Surface::~Surface()
{
	ClearMesh();
}

void Surface::draw()
{
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glDrawArrays(GL_TRIANGLES, 0, Vertex_Holder.size() );
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

void Surface::construct()
{

	float xmin = 0.0f, xmax = 10.0f, ymin = 0.0f, ymax = 10.0f, h =0.01f;
	for (auto x = xmin; x < xmax; x += h)
		for (auto y = ymin; y < ymax; y += h)
		{
			float z = sin(3.14159 * x) * sin(3.14159 * y);
			Vertex_Holder.push_back(Vertex{ x,y,z,x,y,z });
			z = sin(3.14159 * (x + h)) * sin(3.14159 * y);
			Vertex_Holder.push_back(Vertex{ x + h,y,z,x,y,z });
			z = sin(3.14159 * x) * sin(3.14159 * (y + h));
			Vertex_Holder.push_back(Vertex{ x,y + h,z,x,y,z });
			Vertex_Holder.push_back(Vertex{ x,y + h,z,x,y,z });
			z = sin(3.14159 * (x + h)) * sin(3.14159 * y);
			Vertex_Holder.push_back(Vertex{ x + h,y,z,x,y,z });
			z = sin(3.14159 * (x + h)) * sin(3.14159 * (y + h));
			Vertex_Holder.push_back(Vertex{ x + h,y + h,z,x,y,z });
		}
}
