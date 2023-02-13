#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Window.h"
#include <iostream>
#include <XYZ.h>
using namespace std;

Window::Window()
{
	GLFWwindow* main_window;

	glfwInit();
	if (!glfwInit()) {
		std::cout << "GLFW Init failed!" << std::endl;
		glfwTerminate();
	}

	main_window = glfwCreateWindow(width, heigth, window_title, NULL, NULL);
	glfwMakeContextCurrent(main_window);

	glewInit();
	if (glewInit() != GLEW_OK) {
		std::cout << "GLEW Init failed!" << std::endl;
		glfwTerminate();
	}

	glfwWindowHint(GL_MAJOR_VERSION, 4);     //chose the major version of opengl
	glfwWindowHint(GL_MINOR_VERSION, 3);    //chose the minor version of opengl
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE); //

	glfwGetFramebufferSize(main_window, &buffer_w, &buffer_h);
	glewExperimental = GL_TRUE;

	XYZ* xyz = new XYZ();
	xyz->init();

	while (!glfwWindowShouldClose(main_window)) {
		
		glfwPollEvents();
		glClearColor(0.05f, 0.02f, 0.2067f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(main_window);
		xyz->draw();
	}


}

Window::~Window()
{
}
