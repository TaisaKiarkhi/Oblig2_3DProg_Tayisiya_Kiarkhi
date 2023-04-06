#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "XYZ.h"
#include <VisualObject.h>
#include <Vertex.h>
#include <glm/glm/mat4x4.hpp>
#include <vector>


GLfloat vertices[] = {
  0.0f,0.0f,0.0f ,
  1000.0f,0.0f,0.0f ,
  0.0f,0.0f,0.0f ,
  0.0f,1000.0f,0.0f ,
  0.0f,0.0f,0.0f ,
  0.0f,0.0f,1000.0f ,
  0.0f,0.0f,0.0f ,

  0.0f,1000.0f,0.0f ,
  0.0f,0.0f,0.0f ,
  -1000.0f ,0.0f,0.0f,
  0.0f  ,0.0f,0.0f ,
  0.0f ,-1000.0f,0.0f,
  0.0f  ,0.0f,0.0f ,
  0.0f  ,-1000.0f,0.0f ,
  0.0f,0.0f,0.0f ,
  0.0f,0.0f,-1000.0f ,
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

Vertex_Holder.push_back(Vertex{ 0.0f ,0.0f ,0.0f,         1.0f,  0.0f,  0.0f,   0.0f, 0.0f,   0.0f, 0.0f, 0.0f });
Vertex_Holder.push_back(Vertex{ 1000.0f ,0.0f ,0.0f,      1.0f,  0.0f,  0.0f,   0.0f, 0.0f,   0.0f, 0.0f, 0.0f });
Vertex_Holder.push_back(Vertex{ 0.0f ,0.0f ,0.0f,         0.0f,  1.0f,  0.0f,   0.0f, 0.0f,   0.0f, 0.0f, 0.0f });
Vertex_Holder.push_back(Vertex{ 0.0f ,1000.0f ,0.0f,      0.0f,  1.0f,  0.0f,   0.0f, 0.0f,   0.0f, 0.0f, 0.0f });
Vertex_Holder.push_back(Vertex{ 0.0f ,0.0f ,0.0f,         0.0f,  0.0f,  1.0f,   0.0f, 0.0f,   0.0f, 0.0f, 0.0f });
Vertex_Holder.push_back(Vertex{ 0.0f ,0.0f ,1000.0f,      0.0f,  0.0f,  1.0f,   0.0f, 0.0f,   0.0f, 0.0f, 0.0f });
Vertex_Holder.push_back(Vertex{ 0.0f ,0.0f ,0.0f,         1.0f,  0.0f,  0.0f,   0.0f, 0.0f,   0.0f, 0.0f, 0.0f });
														      				
												 		      				
Vertex_Holder.push_back(Vertex{ 0.0f ,1000.0f ,0.0f,      0.0f,  1.0f,  0.0f, 0.0f, 0.0f,   0.0f, 0.0f, 0.0f });
Vertex_Holder.push_back(Vertex{ 0.0f ,0.0f ,0.0f,         1.0f,  0.0f,  0.0f, 0.0f, 0.0f,   0.0f, 0.0f, 0.0f });
Vertex_Holder.push_back(Vertex{-1000.0f ,0.0f,0.0f,       1.0f  ,0.0f  ,0.0f, 0.0f, 0.0f,   0.0f, 0.0f, 0.0f  });
Vertex_Holder.push_back(Vertex{ 0.0f  ,0.0f  ,0.0f,       0.0f  ,1.0f  ,0.0f, 0.0f, 0.0f,   0.0f, 0.0f, 0.0f  });
Vertex_Holder.push_back(Vertex{ 0.0f ,-1000.0f ,0.0f,     0.0f  ,1.0f  ,0.0f, 0.0f, 0.0f,   0.0f, 0.0f, 0.0f  });
Vertex_Holder.push_back(Vertex{ 0.0f  ,0.0f  ,0.0f,       0.0f  ,0.0f  ,1.0f, 0.0f, 0.0f,   0.0f, 0.0f, 0.0f  });
Vertex_Holder.push_back(Vertex{ 0.0f  ,0.0f ,-1000.0f,    0.0f  ,0.0f  ,1.0f, 0.0f, 0.0f,   0.0f, 0.0f, 0.0f  });


}

XYZ::~XYZ()
{
	ClearMesh();
}

void XYZ::draw()
{
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glDrawArrays(GL_LINES, 0,16);
	glBindBuffer(GL_ARRAY_BUFFER,0);
	glBindVertexArray(0);
	
}

void XYZ::init()
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

void XYZ::ClearMesh()
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
