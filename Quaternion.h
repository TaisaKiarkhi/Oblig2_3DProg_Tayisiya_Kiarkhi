#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

typedef GLfloat Matrix4x4[4][4];

class Quaternion
{
public: 
	Quaternion(); 
	~Quaternion();

	void matrix4x4SetIdentity(Matrix4x4 matIdent4x4); //identity matrix
	void translate3D(GLfloat tx, GLfloat ty, GLfloat tz); //translation matrix

	GLfloat x, y, z;
};

