#include "Shader.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h> 
Shader::Shader()
{
	Shader_Program = 0;
}

Shader::~Shader()
{
}

void Shader::Create_from_file(const char* vertex_code, const char* fragment_code)
{
	std::string vertex_string =  Read_Files(vertex_code);
	std::string fragment_string = Read_Files(fragment_code);

	const char* vertex_Code = vertex_string.c_str();
	const char* fragment_Code = fragment_string.c_str();

	Compile_Shaders(vertex_Code, fragment_Code);
}

void Shader::Compile_Shaders(const char* Vertex, const char* Fragment)
{
	Shader_Program = glCreateProgram();
	if (!Shader_Program) {
		std::cout << "Failed to create shader prog";
	}
	Add_Shader(Shader_Program, Vertex, GL_VERTEX_SHADER);
	Add_Shader(Shader_Program, Fragment, GL_FRAGMENT_SHADER);

	GLint result = 0;

	glLinkProgram(Shader_Program);
	glGetProgramiv(Shader_Program, GL_LINK_STATUS, &result);

	glValidateProgram(Shader_Program);
	glGetProgramiv(Shader_Program, GL_VALIDATE_STATUS, &result);



}

void Shader::Add_Shader(GLuint Shader_Prog, const char* shader_code, GLenum Type)
{
	GLuint Shader_ = glCreateShader(Type);
	const char* the_code[1];
	the_code[0] = shader_code;

	GLint code_length[1];
	code_length[0] = strlen(shader_code);

	glShaderSource(Shader_, 1, the_code, code_length);
	glCompileShader(Shader_);

	GLint result = 0;
	glGetShaderiv(Shader_, GL_COMPILE_STATUS, &result);
	glAttachShader(Shader_, Shader_);
}

std::string Shader::Read_Files(const char* file_name)
{
	std::string content;
	std::fstream inn_file(file_name, std::ios::in);

	std::string line = " ";
	while (!inn_file.eof()) {
		std::getline(inn_file, line);
		content.append(line + "\n");
	}
	inn_file.close();
	return content;
}

void Shader::Use_Shader()
{
	glUseProgram(Shader_Program);
}
