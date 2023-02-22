#pragma once
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <fstream>
#include <string>
class Shader
{
public:
	Shader();
	~Shader();

	void Create_from_file(const char* vertex_code, const char* fragment_code);
	void Compile_Shaders(const char*Vertex, const char* Fragment);
	void Add_Shader(GLuint Shader_Prog, const char* shader_code, GLenum Type);
	std::string Read_Files(const char* file_name);
	void Use_Shader();
	GLuint GetViewLocation();
	GLuint GetProjectionLocation();
	GLuint Shader_Program, uniformView, uniformProjection;
};

