#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <Vertex.h>
#include <glm/glm/glm.hpp>

typedef GLfloat Matrix4x4[4][4];

class Quaternion
{
public: 
	Quaternion();
	~Quaternion();

	void matrix4x4SetIdentity(Matrix4x4 matIdent4x4); //identity matrix
	void translate3D(GLfloat tx, GLfloat ty, GLfloat tz); //translation matrix
	void matrix4X4PreMultiply(Matrix4x4 mat1_, Matrix4x4 mat2_);//concatenate matricies ( for example translation * rotation)
	void rotate3D_Quaternion(glm::vec3 vert1, glm::vec3 vert2, GLfloat radians_angle); //rotation with use of quaternion things


	Matrix4x4 Matrix_Rotation;
};

