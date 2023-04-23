#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h> 
#include <VisualObject.h>
#include <Vertex.h>
class Tetragons : public VisualObject
{
public:

	Tetragons();
	~Tetragons();
	void draw();
	void init();
	void ClearMesh();
	glm::vec3 pos;
	GLuint Offset_Buffer;
};

