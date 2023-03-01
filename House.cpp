#include "House.h"

House::House()
{
    //Vertex coordinates source: https://github.com/Lolinonusos/OpenGLTest_Men-for-skole-lol/blob/main/OpenGLTest/cube.cpp
//
Vertex_Holder.push_back(Vertex{ -0.5f, -0.5f, -0.5f,        0.878f, 0.69f, 1.0f });
Vertex_Holder.push_back(Vertex{ 0.5f, -0.5f, -0.5f,         0.878f, 0.69f, 1.0f });
Vertex_Holder.push_back(Vertex{ 0.5f,  0.5f, -0.5f,         0.878f, 0.69f, 1.0f });
Vertex_Holder.push_back(Vertex{ 0.5f,  0.5f, -0.5f,         0.878f, 0.69f, 1.0f });
Vertex_Holder.push_back(Vertex{ -0.5f,  0.5f, -0.5f,        0.878f, 0.69f, 1.0f});
Vertex_Holder.push_back(Vertex{ -0.5f, -0.5f, -0.5f,        0.878f, 0.69f, 1.0f});
															  		  	   
Vertex_Holder.push_back(Vertex{ -0.5f, -0.5f,  0.5f,        0.878f, 0.69f, 1.0f });
Vertex_Holder.push_back(Vertex{ 0.5f, -0.5f,  0.5f,         0.878f, 0.69f, 1.0f });
Vertex_Holder.push_back(Vertex{ 0.5f,  0.5f,  0.5f,         0.878f, 0.69f, 1.0f  });
Vertex_Holder.push_back(Vertex{ 0.5f,  0.5f,  0.5f,         0.878f, 0.69f, 1.0f  });
Vertex_Holder.push_back(Vertex{ -0.5f,  0.5f,  0.5f,        0.878f, 0.69f, 1.0f });
Vertex_Holder.push_back(Vertex{ -0.5f, -0.5f,  0.5f,        0.878f, 0.69f, 1.0f  });
													 		  
Vertex_Holder.push_back(Vertex{ -0.5f,  0.5f,  0.5f,        0.878f, 0.69f, 1.0f});
Vertex_Holder.push_back(Vertex{ -0.5f,  0.5f, -0.5f,        0.878f, 0.69f, 1.0f });
Vertex_Holder.push_back(Vertex{ -0.5f, -0.5f, -0.5f,        0.878f, 0.69f, 1.0f });
Vertex_Holder.push_back(Vertex{ -0.5f, -0.5f, -0.5f,        0.878f, 0.69f, 1.0f });
Vertex_Holder.push_back(Vertex{ -0.5f, -0.5f,  0.5f,        0.878f, 0.69f, 1.0f });
Vertex_Holder.push_back(Vertex{ -0.5f,  0.5f,  0.5f,        0.878f, 0.69f, 1.0f });
			

//here will be a door
Vertex_Holder.push_back(Vertex{ 0.5f,  0.5f,  0.5f,         0.878f, 0.69f, 1.0f});
Vertex_Holder.push_back(Vertex{ 0.5f,  0.5f, -0.5f,         0.878f, 0.69f, 1.0f});
Vertex_Holder.push_back(Vertex{ 0.5f, -0.5f, -0.5f,         0.878f, 0.69f, 1.0f});
Vertex_Holder.push_back(Vertex{ 0.5f, -0.5f, -0.5f,         0.878f, 0.69f, 1.0f});
Vertex_Holder.push_back(Vertex{ 0.5f, -0.5f,  0.5f,         0.878f, 0.69f, 1.0f});
Vertex_Holder.push_back(Vertex{ 0.5f,  0.5f,  0.5f,         0.878f, 0.69f, 1.0f});


//door i guess??
Vertex_Holder.push_back(Vertex{ 0.51f,  0.3f,  0.3f,       0.588f, 0.69f, 1.0f });
Vertex_Holder.push_back(Vertex{ 0.51f,  0.3f, -0.3f,       0.588f, 0.69f, 1.0f });
Vertex_Holder.push_back(Vertex{ 0.51f, -0.5f, -0.3f,       0.588f, 0.69f, 1.0f });
Vertex_Holder.push_back(Vertex{ 0.51f, -0.5f, -0.3f,       0.588f, 0.69f, 1.0f });
Vertex_Holder.push_back(Vertex{ 0.51f, -0.5f,  0.3f,       0.588f, 0.69f, 1.0f });
Vertex_Holder.push_back(Vertex{ 0.51f,  0.3f,  0.3f,       0.588f, 0.69f, 1.0f });
																		  
														      			  
Vertex_Holder.push_back(Vertex{ -0.5f, -0.5f, -0.5f,       1.0f, 0.412f, 0.0f  });
Vertex_Holder.push_back(Vertex{ 0.5f, -0.5f, -0.5f,        1.0f, 0.412f, 0.0f });
Vertex_Holder.push_back(Vertex{ 0.5f, -0.5f,  0.5f,        1.0f, 0.412f, 0.0f });
Vertex_Holder.push_back(Vertex{ 0.5f, -0.5f,  0.5f,        1.0f, 0.412f, 0.0f });
Vertex_Holder.push_back(Vertex{ -0.5f, -0.5f,  0.5f,       1.0f, 0.412f, 0.0f });
Vertex_Holder.push_back(Vertex{ -0.5f, -0.5f, -0.5f,       1.0f, 0.412f, 0.0f });
															 			  
//top - bottom of the roof									 878		  1
Vertex_Holder.push_back(Vertex{ -0.5f,  0.5f, -0.5f,       0.878f, 0.69f, 1.0f });
Vertex_Holder.push_back(Vertex{ 0.5f,  0.5f, -0.5f,        0.878f, 0.69f, 1.0f});
Vertex_Holder.push_back(Vertex{ 0.5f,  0.5f,  0.5f,        0.878f, 0.69f, 1.0f});
Vertex_Holder.push_back(Vertex{ 0.5f,  0.5f,  0.5f,        0.878f, 0.69f, 1.0f});
Vertex_Holder.push_back(Vertex{ -0.5f,  0.5f,  0.5f,       0.878f, 0.69f, 1.0f});
Vertex_Holder.push_back(Vertex{ -0.5f,  0.5f, -0.5f,       0.878f, 0.69f, 1.0f});


}

House::~House()
{
}

void House::draw()
{

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);


	glDrawArrays(GL_TRIANGLES, 0, Vertex_Holder.size());
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void House::init()
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

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);


}
