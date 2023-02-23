#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h> 
#include <VisualObject.h>
#include <vector>


class XYZ : public VisualObject
{
public:
	XYZ();
	~XYZ();
//	void draw() override;
//	void init() override;

	void draw();
	void init();
	void ClearMesh();

	

	
	

};

