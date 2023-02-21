#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Window.h"
#include <iostream>
#include <XYZ.h>
#include <VisualObject.h>
#include <Shader.h>
#include <vector>
using namespace std;


static const char* VShader = "VertexShader.vert";

static const char* FShader = "FragmentShader.frag";


GLFWwindow* main_window;

Window::Window()
{

	
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


	glewExperimental = GL_TRUE;
	glewInit();

	if (glewInit() != GLEW_OK) {
		std::cout << "GLEW Init failed!" << std::endl;
		glfwTerminate();
	}

	

	//glEnable(GL_DEPTH_TEST);
	glViewport(0, 0, buffer_w, buffer_h);
	
	Objects();
	Adding_Shaders();


	while (!glfwWindowShouldClose(main_window)) {
		
		glfwPollEvents();
		glClearColor(0.05f, 0.02f, 0.2067f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT); // GL_DEPTH_BUFFER_BIT 
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
