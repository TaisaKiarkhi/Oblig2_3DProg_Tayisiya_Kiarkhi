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

	VAO = 0;
	VBO = 0;
	
}

void XYZ::draw()
{
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, Vertex_Holder.size());
	glBindVertexArray(0);
	
}

void XYZ::init()
{
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
    glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * Vertex_Holder.size(), &Vertex_Holder, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);

	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}
