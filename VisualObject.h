#pragma once
#include <Vertex.h>
#include <glm/mat4x4.hpp>
class VisualObject

{
public:
	virtual void draw();
	virtual void init(); 

	GLuint VAO;
	GLuint VBO;
	
	std::vector<Vertex>Vertex_Holder; 
	
	
	
};

