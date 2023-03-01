#include "NPC.h"
#include <iostream>
NPC::NPC()
{
	Vertex_Holder.push_back(Vertex{ -0.5f, -0.5f, -0.5f,        0.1f, 0.764f, 0.99f });
	Vertex_Holder.push_back(Vertex{ 0.5f, -0.5f, -0.5f,         0.1f, 0.764f, 0.99f });
	Vertex_Holder.push_back(Vertex{ 0.5f,  0.5f, -0.5f,         0.1f, 0.764f, 0.99f });
	Vertex_Holder.push_back(Vertex{ 0.5f,  0.5f, -0.5f,         0.1f, 0.764f, 0.99f });
	Vertex_Holder.push_back(Vertex{ -0.5f,  0.5f, -0.5f,        0.1f, 0.764f, 0.99f });
	Vertex_Holder.push_back(Vertex{ -0.5f, -0.5f, -0.5f,        0.1f, 0.764f, 0.99f });

	Vertex_Holder.push_back(Vertex{ -0.5f, -0.5f,  0.5f,     0.1f, 0.764f, 0.99f });
	Vertex_Holder.push_back(Vertex{ 0.5f, -0.5f,  0.5f,      0.1f, 0.764f, 0.99f });
	Vertex_Holder.push_back(Vertex{ 0.5f,  0.5f,  0.5f,      0.1f, 0.764f, 0.99f });
	Vertex_Holder.push_back(Vertex{ 0.5f,  0.5f,  0.5f,      0.1f, 0.764f, 0.99f });
	Vertex_Holder.push_back(Vertex{ -0.5f,  0.5f,  0.5f,     0.1f, 0.764f, 0.99f });
	Vertex_Holder.push_back(Vertex{ -0.5f, -0.5f,  0.5f,     0.1f, 0.764f, 0.99f });

	Vertex_Holder.push_back(Vertex{ -0.5f,  0.5f,  0.5f,        0.1f, 0.80f, 0.99f });
	Vertex_Holder.push_back(Vertex{ -0.5f,  0.5f, -0.5f,        0.1f, 0.80f, 0.99f });
	Vertex_Holder.push_back(Vertex{ -0.5f, -0.5f, -0.5f,        0.1f, 0.80f, 0.99f });
	Vertex_Holder.push_back(Vertex{ -0.5f, -0.5f, -0.5f,        0.1f, 0.80f, 0.99f });
	Vertex_Holder.push_back(Vertex{ -0.5f, -0.5f,  0.5f,        0.1f, 0.80f, 0.99f });
	Vertex_Holder.push_back(Vertex{ -0.5f,  0.5f,  0.5f,        0.1f, 0.80f, 0.99f });

	Vertex_Holder.push_back(Vertex{ 0.5f,  0.5f,  0.5f,         0.1f, 0.764f, 0.99f });
	Vertex_Holder.push_back(Vertex{ 0.5f,  0.5f, -0.5f,         0.1f, 0.764f, 0.99f });
	Vertex_Holder.push_back(Vertex{ 0.5f, -0.5f, -0.5f,         0.1f, 0.764f, 0.99f });
	Vertex_Holder.push_back(Vertex{ 0.5f, -0.5f, -0.5f,         0.1f, 0.764f, 0.99f });
	Vertex_Holder.push_back(Vertex{ 0.5f, -0.5f,  0.5f,         0.1f, 0.764f, 0.99f });
	Vertex_Holder.push_back(Vertex{ 0.5f,  0.5f,  0.5f,         0.1f, 0.764f, 0.99f });

	Vertex_Holder.push_back(Vertex{ -0.5f, -0.5f, -0.5f,        0.1f, 0.764f, 0.141f });
	Vertex_Holder.push_back(Vertex{ 0.5f, -0.5f, -0.5f,         0.1f, 0.764f, 0.141f });
	Vertex_Holder.push_back(Vertex{ 0.5f, -0.5f,  0.5f,         0.1f, 0.764f, 0.141f });
	Vertex_Holder.push_back(Vertex{ 0.5f, -0.5f,  0.5f,         0.1f, 0.764f, 0.141f });
	Vertex_Holder.push_back(Vertex{ -0.5f, -0.5f,  0.5f,        0.1f, 0.764f, 0.141f });
	Vertex_Holder.push_back(Vertex{ -0.5f, -0.5f, -0.5f,        0.1f, 0.764f, 0.141f });
																	  
	Vertex_Holder.push_back(Vertex{ -0.5f,  0.5f, -0.5f,        0.1f, 0.674f, 0.99f });
	Vertex_Holder.push_back(Vertex{ 0.5f,  0.5f, -0.5f,         0.1f, 0.674f, 0.99f });
	Vertex_Holder.push_back(Vertex{ 0.5f,  0.5f,  0.5f,         0.1f, 0.674f, 0.99f });
	Vertex_Holder.push_back(Vertex{ 0.5f,  0.5f,  0.5f,         0.1f, 0.674f, 0.99f });
	Vertex_Holder.push_back(Vertex{ -0.5f,  0.5f,  0.5f,        0.1f, 0.674f, 0.99f });
	Vertex_Holder.push_back(Vertex{ -0.5f,  0.5f, -0.5f,        0.1f, 0.674f, 0.99f });
}

NPC::~NPC()
{
}

void NPC::draw()
{
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);


	glDrawArrays(GL_TRIANGLES, 0, Vertex_Holder.size());
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void NPC::init()
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

void NPC::press_key_to_change_function(bool* key)
{
	
	if (key[GLFW_KEY_P]) {
		Function_y();
		std::cout << "this fucntion works P";
	}

	else  {
		Function_y_v_2();
		std::cout << "this fucntion works else";
	}
}

void NPC::Function_y()
{

x_change += 0.01;
y_change = (0.292 * pow(x_change, 2)) + (-0.52 * x_change) - 1.82;

if (x_change > 10) {
	x_change = -10;
}
if (x_change < -10) {
	x_change = 10;
}

}

void NPC::Function_y_v_2()
{
	x_change += 0.01;
	y_change = -0.515 * pow(x_change, 3) + 1.92 * pow(x_change, 2) - 0.655 * x_change - 3.38;

	if (x_change > 5) {
	x_change = -5;
}
if (x_change < -5) {
	x_change = 5;
}
}
