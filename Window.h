#pragma once
#ifndef WINDOW
#define WINDOW
#include <VisualObject.h>
#include <Shader.h>
#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <XYZ.h>
class Window
{
public:
	Window();
	~Window();
	void Objects();
	void Adding_Shaders();

	GLint heigth = 1920, width = 1080;      //window size
	const char* window_title{ "Oblig2" };
	int buffer_w, buffer_h;
	std::vector <VisualObject*> meshes;
	std::vector <Shader*> shader_list;
	XYZ* xyz = new XYZ();
};

#endif WINDOW