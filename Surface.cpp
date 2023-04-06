#include "Surface.h"



Surface::Surface()
{
	
			
	//bottom //put some gradient, it will look pretty
Vertex_Holder.push_back(Vertex{-30.5f, 0.0, -30.5,       1.0f, 0.412f, 0.706f,    0.0f, 0.0f,   0.0f, 0.0f, 0.0f  });
Vertex_Holder.push_back(Vertex{ 30.5,   0.0,-30.5,       1.0f, 0.412f, 0.706f,    0.0f, 0.0f,   0.0f, 0.0f, 0.0f });
Vertex_Holder.push_back(Vertex{ 30.5,   0.0, 30.5,       1.0f, 0.412f, 0.706f,    0.0f, 0.0f,   0.0f, 0.0f, 0.0f  });
Vertex_Holder.push_back(Vertex{ 30.5,   0.0, 30.5,       1.0f, 0.412f, 0.706f,    0.0f, 0.0f,   0.0f, 0.0f, 0.0f  });
Vertex_Holder.push_back(Vertex{-30.5,  0.0,  30.5,       1.0f, 0.412f, 0.706f,    0.0f, 0.0f,   0.0f, 0.0f, 0.0f });
Vertex_Holder.push_back(Vertex{-30.5,  0.0, -30.5,       1.0f, 0.412f, 0.706f,    0.0f, 0.0f,   0.0f, 0.0f, 0.0f  });

	//create_plane();

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

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(8 * sizeof(GLfloat)));
	glEnableVertexAttribArray(3);

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

	float xmin = 0.0f, xmax = 10.0f, ymin = 0.0f, ymax = 10.0f, h =0.25f;
	for (auto x = xmin; x < xmax; x += h)
		for (auto y = ymin; y < ymax; y += h)
		{
			float z = sin(3.14159 * x) * sin(3.14159 * y);
			Vertex_Holder.push_back(Vertex{ x,y,z,x,y,z, 0.0f, 0.0f,   0.0f, 0.0f, 0.0f});
			z = sin(3.14159 * (x + h)) * sin(3.14159 * y);
			Vertex_Holder.push_back(Vertex{ x + h,y,z,x,y,z,  0.0f, 0.0f, 0.0f, 0.0f, 0.0f });
			z = sin(3.14159 * x) * sin(3.14159 * (y + h));
			Vertex_Holder.push_back(Vertex{ x,y + h,z,x,y,z,  0.0f, 0.0f, 0.0f, 0.0f, 0.0f });
			Vertex_Holder.push_back(Vertex{ x,y + h,z,x,y,z,  0.0f, 0.0f, 0.0f, 0.0f, 0.0f });
			z = sin(3.14159 * (x + h)) * sin(3.14159 * y);
			Vertex_Holder.push_back(Vertex{ x + h,y,z,x,y,z,    0.0f, 0.0f, 0.0f, 0.0f, 0.0f });
			z = sin(3.14159 * (x + h)) * sin(3.14159 * (y + h));
			Vertex_Holder.push_back(Vertex{ x + h,y + h,z,x,y,z,   0.0f, 0.0f, 0.0f, 0.0f, 0.0f });
		}
}

void Surface::create_plane()
{
	int dimension = 10;

	int half = dimension / 2;

	for (int i = 0; i < dimension; i++) {
		for (int j = 0; j < dimension; j++) {
			float x = j - half;
			float y = 0.0f;
			float z = i - half;

			float r = 1.0f;
			float g = 0.0f;
			float b = 1.0f;

			Vertex_Holder.push_back(Vertex{ x,y ,z, r,g,b,  0.0f, 0.0f, 0.0f, 0.0f, 0.0f });

	}
	}
}
