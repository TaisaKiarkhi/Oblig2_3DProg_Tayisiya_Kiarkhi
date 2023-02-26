#include "House.h"

House::House()
{
    //Vertex coordinates source: https://github.com/Lolinonusos/OpenGLTest_Men-for-skole-lol/blob/main/OpenGLTest/cube.cpp
//
Vertex_Holder.push_back(Vertex{ -0.5f, -0.5f, -0.5f,       0.965f, 0.764f, 0.141f });
Vertex_Holder.push_back(Vertex{ 0.5f, -0.5f, -0.5f,         0.965f, 0.764f, 0.141f });
Vertex_Holder.push_back(Vertex{ 0.5f,  0.5f, -0.5f,         0.965f, 0.764f, 0.141f });
Vertex_Holder.push_back(Vertex{ 0.5f,  0.5f, -0.5f,         0.965f, 0.764f, 0.141f });
Vertex_Holder.push_back(Vertex{ -0.5f,  0.5f, -0.5f,        0.965f, 0.764f, 0.141f});
Vertex_Holder.push_back(Vertex{ -0.5f, -0.5f, -0.5f,        0.965f, 0.764f, 0.141f});

Vertex_Holder.push_back(Vertex{ -0.5f, -0.5f,  0.5f,     0.965f, 0.764f, 0.201f });
Vertex_Holder.push_back(Vertex{ 0.5f, -0.5f,  0.5f,      0.965f, 0.764f, 0.201f });
Vertex_Holder.push_back(Vertex{ 0.5f,  0.5f,  0.5f,      0.965f, 0.764f, 0.201f  });
Vertex_Holder.push_back(Vertex{ 0.5f,  0.5f,  0.5f,      0.965f, 0.764f, 0.201f  });
Vertex_Holder.push_back(Vertex{ -0.5f,  0.5f,  0.5f,     0.965f, 0.764f, 0.201f });
Vertex_Holder.push_back(Vertex{ -0.5f, -0.5f,  0.5f,     0.965f, 0.764f, 0.201f  });
													 
Vertex_Holder.push_back(Vertex{ -0.5f,  0.5f,  0.5f,        0.965f, 0.80f, 0.141f});
Vertex_Holder.push_back(Vertex{ -0.5f,  0.5f, -0.5f,        0.965f, 0.80f, 0.141f });
Vertex_Holder.push_back(Vertex{ -0.5f, -0.5f, -0.5f,        0.965f, 0.80f, 0.141f });
Vertex_Holder.push_back(Vertex{ -0.5f, -0.5f, -0.5f,        0.965f, 0.80f, 0.141f });
Vertex_Holder.push_back(Vertex{ -0.5f, -0.5f,  0.5f,        0.965f, 0.80f, 0.141f });
Vertex_Holder.push_back(Vertex{ -0.5f,  0.5f,  0.5f,        0.965f, 0.80f, 0.141f });
													 	      
Vertex_Holder.push_back(Vertex{ 0.5f,  0.5f,  0.5f,       0.872f, 0.764f, 0.141f});
Vertex_Holder.push_back(Vertex{ 0.5f,  0.5f, -0.5f,       0.872f, 0.764f, 0.141f});
Vertex_Holder.push_back(Vertex{ 0.5f, -0.5f, -0.5f,       0.872f, 0.764f, 0.141f});
Vertex_Holder.push_back(Vertex{ 0.5f, -0.5f, -0.5f,       0.872f, 0.764f, 0.141f});
Vertex_Holder.push_back(Vertex{ 0.5f, -0.5f,  0.5f,       0.872f, 0.764f, 0.141f});
Vertex_Holder.push_back(Vertex{ 0.5f,  0.5f,  0.5f,       0.872f, 0.764f, 0.141f});
														      
Vertex_Holder.push_back(Vertex{ -0.5f, -0.5f, -0.5f,       0.9922f, 0.764f, 0.141f  });
Vertex_Holder.push_back(Vertex{ 0.5f, -0.5f, -0.5f,        0.9922f, 0.764f, 0.141f });
Vertex_Holder.push_back(Vertex{ 0.5f, -0.5f,  0.5f,        0.9922f, 0.764f, 0.141f });
Vertex_Holder.push_back(Vertex{ 0.5f, -0.5f,  0.5f,        0.9922f, 0.764f, 0.141f });
Vertex_Holder.push_back(Vertex{ -0.5f, -0.5f,  0.5f,       0.9922f, 0.764f, 0.141f });
Vertex_Holder.push_back(Vertex{ -0.5f, -0.5f, -0.5f,       0.9922f, 0.764f, 0.141f });

//top - bottom of the roof
Vertex_Holder.push_back(Vertex{ -0.5f,  0.5f, -0.5f,       0.965f, 0.674f, 0.183f });
Vertex_Holder.push_back(Vertex{ 0.5f,  0.5f, -0.5f,        0.965f, 0.674f, 0.183f});
Vertex_Holder.push_back(Vertex{ 0.5f,  0.5f,  0.5f,        0.965f, 0.674f, 0.183f});
Vertex_Holder.push_back(Vertex{ 0.5f,  0.5f,  0.5f,        0.965f, 0.674f, 0.183f});
Vertex_Holder.push_back(Vertex{ -0.5f,  0.5f,  0.5f,       0.965f, 0.674f, 0.183f});
Vertex_Holder.push_back(Vertex{ -0.5f,  0.5f, -0.5f,       0.965f, 0.674f, 0.183f});


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
