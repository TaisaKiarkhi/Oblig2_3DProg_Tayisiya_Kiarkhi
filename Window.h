#pragma once
#ifndef WINDOW
#define WINDOW
#include <VisualObject.h>
#include <Shader.h>
#include <vector>
class Window
{
public:
	Window();
	~Window();
	void Objects();
	void Adding_Shaders();

	GLint heigth = 1920, width = 1080;      //window size
	const char* window_title{ "Oblig2" };
	GLint buffer_w;
	GLint buffer_h;
	std::vector <VisualObject*> meshes;
	std::vector <Shader*> shader_list;

};

#endif WINDOW