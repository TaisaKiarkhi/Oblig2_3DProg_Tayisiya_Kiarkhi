#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h> 
#include <VisualObject.h>
#include <Vertex.h>
class Surface: public VisualObject
{
public: 
	Surface();
	~Surface();

	void draw();
	void init();
	void ClearMesh();
	void construct();
	void create_plane();
	
};

