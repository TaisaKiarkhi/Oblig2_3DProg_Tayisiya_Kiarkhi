#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "XYZ.h"
#include <VisualObject.h>
#include <Vertex.h>
#include <glm/mat4x4.hpp>
#include <vector>

XYZ::XYZ()
{                                       //vert.            //rgb
//	Vertex_Holder.push_back(Vertex{0.0, 1.0, 0.0,   0.0, 1.0, 0.0});
//	Vertex_Holder.push_back(Vertex{1.0, 0.0, 0.0,   1.0, 0.0, 0.0});
//	Vertex_Holder.push_back(Vertex{0.0, -1.0, 0.0,  0.0, 1.0, 0.0});
//	Vertex_Holder.push_back(Vertex{-1.0, 0.0, 0.0,  1.0, 0.0, 0.0});
//	Vertex_Holder.push_back(Vertex{0.0, 0.0, 0.0,   0.0, 0.0, 0.0});


	  
		



	Vertex_Holder.push_back(Vertex{ 0.0, 0.0, 0.0,    1.0, 0.0, 0.0});
	Vertex_Holder.push_back(Vertex{0.5, 0.0,  0.0,    1.0, 0.0, 0.0});
	Vertex_Holder.push_back(Vertex{ 0.0, 0.0, 0.0,    0.0, 1.0, 0.0});
	Vertex_Holder.push_back(Vertex{0.0, 0.5,  0.0,    0.0, 1.0, 0.0});
	Vertex_Holder.push_back(Vertex{0.0, 0.0,  0.0,    0.0, 0.0, 1.0});
	Vertex_Holder.push_back(Vertex{ 0.0, 0.0, 0.5,    0.0, 0.0, 1.0});
	
}

void XYZ::draw()
{
	glViewport(0, 0, 300, 300);

	glEnableVertexAttribArray(0);

	glDrawArrays(GL_LINES, 0, Vertex_Holder.size());
	
}

void XYZ::init()
{
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, Vertex_Holder.size() * sizeof(Vertex), Vertex_Holder.data(), GL_STATIC_DRAW);
	
	glVertexAttribPointer(VBOs_Holder.size(), 3, GL_FLOAT, GL_FALSE, 0, NULL);
	VBOs_Holder.push_back(VBO);

	//glGenBuffers(1, &VBO2);
	//glBindBuffer(GL_ARRAY_BUFFER, VBO2);
	//glBufferData(GL_ARRAY_BUFFER, Vertex_Holder.size() * sizeof(Vertex), Vertex_Holder.data(), GL_STATIC_DRAW);
	//glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),  (GLvoid*)(3*sizeof(float)));
	//glEnableVertexAttribArray(1);
	//
	//glBindVertexArray(0);
}
