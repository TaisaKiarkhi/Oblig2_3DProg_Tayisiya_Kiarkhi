#include "House_Object.h"

House_Object::House_Object()
{
	Vertex_Holder.push_back(Vertex{ -0.5f, -0.5f, -0.5f,     0.35294f, 0.3098f, 0.81176f,  0.0f, 0.0f,   0.0f, 0.0f, 0.0f });
	Vertex_Holder.push_back(Vertex{ 0.5f, -0.5f, -0.5f,      0.35294f, 0.3098f, 0.81176f,  0.0f, 0.0f,   0.0f, 0.0f, 0.0f });
	Vertex_Holder.push_back(Vertex{ 0.5f,  0.5f, -0.5f,      0.35294f, 0.3098f, 0.81176f,  0.0f, 0.0f,   0.0f, 0.0f, 0.0f });
	Vertex_Holder.push_back(Vertex{ 0.5f,  0.5f, -0.5f,      0.35294f, 0.3098f, 0.81176f,  0.0f, 0.0f,   0.0f, 0.0f, 0.0f });
	Vertex_Holder.push_back(Vertex{ -0.5f,  0.5f, -0.5f,     0.35294f, 0.3098f, 0.81176f,  0.0f, 0.0f,   0.0f, 0.0f, 0.0f });
	Vertex_Holder.push_back(Vertex{ -0.5f, -0.5f, -0.5f,     0.35294f, 0.3098f, 0.81176f,  0.0f, 0.0f,   0.0f, 0.0f, 0.0f });

	Vertex_Holder.push_back(Vertex{ -0.5f, -0.5f,  0.5f,     0.8745f, 1.0f, 0.0f,   0.0f, 0.0f,  0.0f, 0.0f,0.0f });
	Vertex_Holder.push_back(Vertex{ 0.5f, -0.5f,  0.5f,      0.8745f, 1.0f, 0.0f,   0.0f, 0.0f,  0.0f, 0.0f,0.0f });
	Vertex_Holder.push_back(Vertex{ 0.5f,  0.5f,  0.5f,      0.8745f, 1.0f, 0.0f,   0.0f, 0.0f,  0.0f, 0.0f,0.0f });
	Vertex_Holder.push_back(Vertex{ 0.5f,  0.5f,  0.5f,      0.8745f, 1.0f, 0.0f,   0.0f, 0.0f,  0.0f, 0.0f,0.0f });
	Vertex_Holder.push_back(Vertex{ -0.5f,  0.5f,  0.5f,     0.8745f, 1.0f, 0.0f,   0.0f, 0.0f,  0.0f, 0.0f,0.0f });
	Vertex_Holder.push_back(Vertex{ -0.5f, -0.5f,  0.5f,     0.8745f, 1.0f, 0.0f,   0.0f, 0.0f,  0.0f, 0.0f,0.0f });

	Vertex_Holder.push_back(Vertex{ -0.5f,  0.5f,  0.5f,     0.35294f, 0.3098f, 0.81176f,   0.0f, 0.0f,   0.0f, 0.0f, 0.0f });
	Vertex_Holder.push_back(Vertex{ -0.5f,  0.5f, -0.5f,     0.35294f, 0.3098f, 0.81176f,   0.0f, 0.0f,   0.0f, 0.0f, 0.0f });
	Vertex_Holder.push_back(Vertex{ -0.5f, -0.5f, -0.5f,     0.35294f, 0.3098f, 0.81176f,   0.0f, 0.0f,   0.0f, 0.0f, 0.0f });
	Vertex_Holder.push_back(Vertex{ -0.5f, -0.5f, -0.5f,     0.35294f, 0.3098f, 0.81176f,   0.0f, 0.0f,   0.0f, 0.0f, 0.0f });
	Vertex_Holder.push_back(Vertex{ -0.5f, -0.5f,  0.5f,     0.35294f, 0.3098f, 0.81176f,   0.0f, 0.0f,   0.0f, 0.0f, 0.0f });
	Vertex_Holder.push_back(Vertex{ -0.5f,  0.5f,  0.5f,     0.35294f, 0.3098f, 0.81176f,   0.0f, 0.0f,   0.0f, 0.0f, 0.0f });

	Vertex_Holder.push_back(Vertex{ 0.5f,  0.5f,  0.5f,      0.8745f, 1.0f, 0.0f,    0.0f, 0.0f,   0.0f, 0.0f, 0.0f});
	Vertex_Holder.push_back(Vertex{ 0.5f,  0.5f, -0.5f,      0.8745f, 1.0f, 0.0f,    0.0f, 0.0f,   0.0f, 0.0f, 0.0f});
	Vertex_Holder.push_back(Vertex{ 0.5f, -0.5f, -0.5f,      0.8745f, 1.0f, 0.0f,    0.0f, 0.0f,   0.0f, 0.0f, 0.0f});
	Vertex_Holder.push_back(Vertex{ 0.5f, -0.5f, -0.5f,      0.8745f, 1.0f, 0.0f,    0.0f, 0.0f,   0.0f, 0.0f, 0.0f});
	Vertex_Holder.push_back(Vertex{ 0.5f, -0.5f,  0.5f,      0.8745f, 1.0f, 0.0f,    0.0f, 0.0f,   0.0f, 0.0f, 0.0f});
	Vertex_Holder.push_back(Vertex{ 0.5f,  0.5f,  0.5f,      0.8745f, 1.0f, 0.0f,    0.0f, 0.0f,   0.0f, 0.0f, 0.0f});

	Vertex_Holder.push_back(Vertex{ -0.5f, -0.5f, -0.5f,     0.35294f, 0.3098f, 0.81176f ,   0.0f, 0.0f,   0.0f, 0.0f, 0.0f});
	Vertex_Holder.push_back(Vertex{ 0.5f, -0.5f, -0.5f,      0.35294f, 0.3098f, 0.81176f ,   0.0f, 0.0f,   0.0f, 0.0f, 0.0f});
	Vertex_Holder.push_back(Vertex{ 0.5f, -0.5f,  0.5f,      0.35294f, 0.3098f, 0.81176f ,   0.0f, 0.0f,   0.0f, 0.0f, 0.0f});
	Vertex_Holder.push_back(Vertex{ 0.5f, -0.5f,  0.5f,      0.35294f, 0.3098f, 0.81176f ,   0.0f, 0.0f,   0.0f, 0.0f, 0.0f});
	Vertex_Holder.push_back(Vertex{ -0.5f, -0.5f,  0.5f,     0.35294f, 0.3098f, 0.81176f ,   0.0f, 0.0f,   0.0f, 0.0f, 0.0f});
	Vertex_Holder.push_back(Vertex{ -0.5f, -0.5f, -0.5f,     0.35294f, 0.3098f, 0.81176f ,   0.0f, 0.0f,   0.0f, 0.0f, 0.0f});

	//top - bottom of the roof
	Vertex_Holder.push_back(Vertex{ -0.5f,  0.5f, -0.5f,     0.8745f, 1.0f, 0.0f,   0.0f, 0.0f,   0.0f, 0.0f, 0.0f });
	Vertex_Holder.push_back(Vertex{ 0.5f,  0.5f, -0.5f,      0.8745f, 1.0f, 0.0f,   0.0f, 0.0f,   0.0f, 0.0f, 0.0f });
	Vertex_Holder.push_back(Vertex{ 0.5f,  0.5f,  0.5f,      0.8745f, 1.0f, 0.0f,   0.0f, 0.0f,   0.0f, 0.0f, 0.0f });
	Vertex_Holder.push_back(Vertex{ 0.5f,  0.5f,  0.5f,      0.8745f, 1.0f, 0.0f,   0.0f, 0.0f,   0.0f, 0.0f, 0.0f });
	Vertex_Holder.push_back(Vertex{ -0.5f,  0.5f,  0.5f,     0.8745f, 1.0f, 0.0f,   0.0f, 0.0f,   0.0f, 0.0f, 0.0f });
	Vertex_Holder.push_back(Vertex{ -0.5f,  0.5f, -0.5f,     0.8745f, 1.0f, 0.0f,   0.0f, 0.0f,   0.0f, 0.0f, 0.0f });
}

House_Object::~House_Object()
{
}

void House_Object::draw()
{

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);


	glDrawArrays(GL_TRIANGLES, 0, Vertex_Holder.size());
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void House_Object::init()
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