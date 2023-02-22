#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h> 
class Tetragons
{
public:

	Tetragons();
	~Tetragons();
	void draw();
	void init();
	void ClearMesh();

	GLuint VAOs, VBOs;
};

