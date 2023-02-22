#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h> 
class Surface
{
public: 
	Surface();
	~Surface();

	void draw();
	void init();
	void ClearMesh();

	GLuint VAOs, VBOs;
};

