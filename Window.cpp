#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Window.h"
#include <iostream>
#include <XYZ.h>
#include <VisualObject.h>
#include <Shader.h>
#include <vector>
using namespace std;


static const char* VShader = "Oblig2_3DProg_Tayisiya_Kiarkhi/VertexShader.frag";

static const char* FShader = "Oblig2_3DProg_Tayisiya_Kiarkhi/FragmentShader.frag";

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


	glViewport(0, 0, buffer_w, buffer_h);
	glEnable(GL_DEPTH_TEST);
	glfwGetFramebufferSize(main_window, &buffer_w, &buffer_h);
	glewExperimental = GL_TRUE;

	Objects();
	Adding_Shaders();

	while (!glfwWindowShouldClose(main_window)) {
		
		glfwPollEvents();
		glClearColor(0.05f, 0.02f, 0.2067f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		shader_list.at(0)->Use_Shader();
		meshes.at(0)->draw();
		

		glUseProgram(0);
		glfwSwapBuffers(main_window);
		
	}


}

Window::~Window()
{
}

void Window::Objects()
{
	XYZ* xyz = new XYZ();
	xyz->init();
	meshes.push_back(xyz);

}

void Window::Adding_Shaders()
{
	Shader* first_shader = new Shader();
	first_shader->Create_from_file(VShader, FShader);
	shader_list.push_back(first_shader);
	
}
