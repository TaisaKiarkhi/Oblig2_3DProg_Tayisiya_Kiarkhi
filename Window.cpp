#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Window.h"
#include <iostream>
#include <XYZ.h>
#include <VisualObject.h>
#include <Shader.h>
#include <vector>
#include <glm/glm/glm.hpp>
#include <glm/glm/ext/matrix_transform.hpp>
#include <glm/glm/mat4x4.hpp>
#include <glm/glm/gtc/type_ptr.hpp>
using namespace std;


static const char* VShader = "VertexShader.vert";

static const char* FShader = "FragmentShader.frag";


GLFWwindow* main_window;

Window::Window()
{
	for (size_t i = 0; i < 1024; i++) {
		keys[i] = 0;
	}
	
	if (!glfwInit()) {
		std::cout << "GLFW Init failed!" << std::endl;
		glfwTerminate();
		
	}

	
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Core Profile = No Backwards Compatibility
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// Allow Forward Compatbility
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
 main_window = glfwCreateWindow(width, heigth, window_title, NULL, NULL);
	if (!main_window) {
		std::cout << "failed window";
	}
	
	glfwGetFramebufferSize(main_window, &buffer_w, &buffer_h);
	glfwMakeContextCurrent(main_window);
	Call_Back(); //pressing keys

	glewExperimental = GL_TRUE;
	glewInit();

	if (glewInit() != GLEW_OK) {
		std::cout << "GLEW Init failed!" << std::endl;
		glfwTerminate();
	}

	

	glEnable(GL_DEPTH_TEST);
	glViewport(0, 0, buffer_w, buffer_h);

	glfwSetWindowUserPointer(main_window, this);
	
	Objects();
	Adding_Shaders();


	while (!glfwWindowShouldClose(main_window)) {
		
		glfwPollEvents();
		glClearColor(0.05f, 0.02f, 0.2067f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // GL_DEPTH_BUFFER_BIT 
		shader_list.at(0)->Use_Shader();
		xyz->draw();
		

		glUseProgram(0);
		glfwSwapBuffers(main_window);
		
	}
	shader_list.at(0)->~Shader();
	xyz->~XYZ();
}

Window::~Window()
{
	glfwDestroyWindow(main_window);
	glfwTerminate();
}

void Window::Objects()
{
	xyz->init();
	//meshes.push_back(xyz);

}

void Window::Adding_Shaders()
{
	Shader* first_shader = new Shader();
	first_shader->Create_from_file(VShader, FShader);
	shader_list.push_back(first_shader);
	
}

void Window::Call_Back()
{
	glfwSetKeyCallback(main_window, Handle_Key);
}

void Window::Handle_Key(GLFWwindow* window, int key, int code, int action, int mode) //the parameters should be as the function shows. Otherwise in will nnot recognize any action
{
	Window* the_window = static_cast<Window*>(glfwGetWindowUserPointer(window));
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, GL_TRUE);
	}

	if (key >=0 && key < 1024) {
		if (action == GLFW_PRESS) {
			the_window->keys[key] = true;
			std::cout << "The key is pressed: " << key<<std::endl;
		}

		else if (action == GLFW_RELEASE) {
			the_window->keys[key] = false;
			std::cout << "The kkey is released " << key << std::endl;
		}
	}
}

void Window::Handle_Mouse(GLFWwindow* window, float xPos, float yPos)
{
	Window* the_window = static_cast<Window*>(glfwGetWindowUserPointer(window));

	if (the_window->mouse_first_moved) {
		the_window->last_coord_x = xPos;
		the_window->last_coord_y = yPos;
		the_window->mouse_first_moved = false;
	}
	the_window->x_move = xPos - the_window->last_coord_x;
	the_window->y_move = the_window->last_coord_y-yPos;
}
