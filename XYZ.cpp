#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "XYZ.h"
#include <VisualObject.h>
#include <Vertex.h>
#include <glm/mat4x4.hpp>
#include <vector>


GLfloat vertices[] = {
  0.0f,0.0f,0.0f ,
  1.0f,0.0f,0.0f ,
  0.0f,0.0f,0.0f ,
  0.0f,1.0f,0.0f ,
  0.0f,0.0f,0.0f ,
  0.0f,1.0f,0.0f ,
  0.0f,0.0f,0.0f ,
  -1.0f ,0.0f,0.0f,
  0.0f  ,0.0f,0.0f ,
  0.0f ,-1.0f,0.0f,
  0.0f  ,0.0f,0.0f ,
  0.0f  ,-1.0f,0.0f ,
};


XYZ::XYZ()
{                                       //vert.            //rgb
//	Vertex_Holder.push_back(Vertex{0.0, 1.0, 0.0,   0.0, 1.0, 0.0});
//	Vertex_Holder.push_back(Vertex{1.0, 0.0, 0.0,   1.0, 0.0, 0.0});
//	Vertex_Holder.push_back(Vertex{0.0, -1.0, 0.0,  0.0, 1.0, 0.0});
//	Vertex_Holder.push_back(Vertex{-1.0, 0.0, 0.0,  1.0, 0.0, 0.0});
//	Vertex_Holder.push_back(Vertex{0.0, 0.0, 0.0,   0.0, 0.0, 0.0});
//
//Vertex_Holder.push_back(Vertex{ 0.0, 0.0, 0.0,    1.0, 0.0, 0.0});
//Vertex_Holder.push_back(Vertex{0.5, 0.0,  0.0,    1.0, 0.0, 0.0});
//Vertex_Holder.push_back(Vertex{ 0.0, 0.0, 0.0,    0.0, 1.0, 0.0});
//Vertex_Holder.push_back(Vertex{0.0, 0.5,  0.0,    0.0, 1.0, 0.0});
//Vertex_Holder.push_back(Vertex{0.0, 0.0,  0.0,    0.0, 0.0, 1.0});
//Vertex_Holder.push_back(Vertex{ 0.0, 0.0, 0.5,    0.0, 0.0, 1.0});
//
Vertex_Holder.push_back(Vertex{ 0,0,0,   0,0,0 });
Vertex_Holder.push_back(Vertex{ 1,0,0,   0,0,0 });
Vertex_Holder.push_back(Vertex{ 0,0,0,   0,0,0 });
Vertex_Holder.push_back(Vertex{ 0,1,0,   0,0,0 });
Vertex_Holder.push_back(Vertex{ 0,0,0,   0,0,0 });
Vertex_Holder.push_back(Vertex{ 0,0,1,   0,0,0 });

Vertex_Holder.push_back(Vertex{ 0,0,0 ,     0,0,0 });
Vertex_Holder.push_back(Vertex{ -1,0,0,     0,0,0});
Vertex_Holder.push_back(Vertex{ 0,0,0,    0,0,0 });
Vertex_Holder.push_back(Vertex{ 0,-1,0,      0,0,0});
Vertex_Holder.push_back(Vertex{ 0,0,0,        0,0,0});
Vertex_Holder.push_back(Vertex{ 0,0,-1,        0,0,0});

	

	VAOs = 0;
	VBOs = 0;

	

	
	
}

XYZ::~XYZ()
{
	ClearMesh();
}

void XYZ::draw()
{
	glBindVertexArray(VAOs);
	glBindBuffer(GL_ARRAY_BUFFER, VBOs);
	glDrawArrays(GL_LINES, 0,12);
	glBindBuffer(GL_ARRAY_BUFFER,0);
	glBindVertexArray(0);
	
}

void XYZ::init()
{
	
	glGenVertexArrays(1, &VAOs);
	glBindVertexArray(VAOs);
    glGenBuffers(1, &VBOs);
	glBindBuffer(GL_ARRAY_BUFFER, VBOs);
	
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void XYZ::ClearMesh()
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
