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

	void Call_Back();
	static void Handle_Key(GLFWwindow* window, int key, int code, int action, int mode);
	static void Handle_Mouse(GLFWwindow* window, float xPos, float yPos);

	GLint heigth = 1920, width = 1080;      //window size
	const char* window_title{ "Oblig2" };
	int buffer_w, buffer_h;
	std::vector <VisualObject*> meshes;
	std::vector <Shader*> shader_list;
	XYZ* xyz = new XYZ();

	GLfloat last_coord_x;
	GLfloat last_coord_y;

	GLfloat y_move;
	GLfloat x_move;
	bool mouse_first_moved;

	bool keys[1024]; //keys as a ASCII code numbers
};

#endif WINDOW