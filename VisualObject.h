#pragma once
#include <Vertex.h>
#include <glm/mat4x4.hpp>
#include <GL/glew.h>
#include <GLFW/glfw3.h> 
class VisualObject

{
public:
	virtual void draw();
	virtual void init(); 

	GLuint VAO{0};
	GLuint VBO{0};
	
	std::vector<Vertex>Vertex_Holder; 
	
	
	
};

