#pragma once
#ifndef WINDOW
#define WINDOW
#include <VisualObject.h>
#include <Shader.h>
#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <XYZ.h>
#include <Camera.h>
#include <Surface.h>
#include "Tetragons.h"
class Window
{
public:
	Window();
	~Window();
	void Objects();
	void Adding_Shaders();

	void Call_Back();
	static void Handle_Key(GLFWwindow* window, int key, int code, int action, int mode);
	static void Handle_Mouse(GLFWwindow* window, double xPos, double yPos);
	void create_uniform(GLuint shader, float m_x, float m_y, float m_z, float angle, 
		          float r_x, float r_y, float r_z, float perspective, float near, float far);

	GLint _model_location;
	GLint _projection_location;
	GLint _rotation_location;

	GLint heigth = 1920, width = 1080;      //window size
	const char* window_title{ "Oblig2" };
	int buffer_w, buffer_h;
	std::vector <VisualObject*> meshes;
	std::vector <Shader*> shader_list;
	

	GLfloat last_coord_x;
	GLfloat last_coord_y;

	GLfloat y_move;
	GLfloat x_move;
	bool mouse_first_moved;

	GLfloat get_x_change();
	GLfloat get_y_change();
	GLfloat deltaTime = 0.0f;
	GLfloat lastTime = 0.0f;
	bool* get_keys() { return keys; }

	bool keys[1024]; //keys as a ASCII code numbers
};

#endif WINDOW