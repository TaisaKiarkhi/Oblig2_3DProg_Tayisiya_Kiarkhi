#include "Heightmap.h"
#include <stb_image.h>
Heightmap::Heightmap()
{
	load_from_file();
	float y_scale = 64.0f / 256.0f, y_shift = 16.0f;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			unsigned char* texel = data + (j + width * i) * bitDepth;
			unsigned char  y = texel[0];
			Vertex_Holder.push_back(Vertex{ -height/2.0f+i, (int)y*y_scale-y_shift, -width/50.0f+j,        0.5f, 0.9f, 1.0f,   0.0f, 0.0f,  0.0f, 0.0f, 0.0f });
		}
	}
}

Heightmap::~Heightmap()
{
}

void Heightmap::load_from_file()
{
	 data = stbi_load(file, &width, &height, &bitDepth, 0);
}

void Heightmap::draw()
{
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	
		glDrawArrays(GL_TRIANGLE_FAN, 0, Vertex_Holder.size());
	
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void Heightmap::init()
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

	stbi_image_free(data);
}
