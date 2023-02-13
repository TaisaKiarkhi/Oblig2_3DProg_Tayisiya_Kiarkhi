#pragma once
#include <Vertex.h>
#include <glm/mat4x4.hpp>
class VisualObject

{
public:
	virtual void draw();
	virtual void init(); 

	GLuint VAOs;
	GLuint VBOs;
	GLuint VBO2;
	std::vector<Vertex>Vertex_Holder; 
	std::vector<GLuint> VBOs_Holder;
	glm::mat4x4 mMatrix;
};

