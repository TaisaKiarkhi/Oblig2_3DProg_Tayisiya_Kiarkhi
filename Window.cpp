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
#include <Tetragons.h>
using namespace std;


static const char* VShader = "VertexShader.vert";

static const char* FShader = "FragmentShader.frag";


GLFWwindow* main_window;
Camera* camera;

Window::Window()
{
	x_move = 0.0f;
	y_move = 0.0f;
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

	//glm::mat4 model (1.0f);
	glm::mat4 projection = glm::perspective(45.0f, (GLfloat)buffer_w/(GLfloat)buffer_h, 0.1f, 100.0f );

	camera = new Camera(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), 45.0f, 0.0f, 5.0f, 1.0f);

	GLuint uniformProjection=0, uniformView=0, uniformModel = 0;

	while (!glfwWindowShouldClose(main_window)) {
		GLfloat current_time = glfwGetTime();
		deltaTime = current_time - lastTime;
		lastTime = current_time;

		glfwPollEvents();


		camera->Key_Controll(this->get_keys(), deltaTime);
		camera->Mouse_Controll(this->get_x_change(), this->get_y_change());


		glClearColor(0.05f, 0.02f, 0.2067f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // GL_DEPTH_BUFFER_BIT 
		shader_list.at(0)->Use_Shader();
		uniformProjection = shader_list.at(0)->GetProjectionLocation();
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		uniformView = shader_list.at(0)->GetViewLocation();
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera->view_matrix_calc()));
		xyz->draw();

		shader_list.at(1)->Use_Shader();
	//	model = glm::scale(model, glm::vec3(0.4f, 0.4f, 0.0f));
	//	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		uniformProjection = shader_list.at(1)->GetProjectionLocation();
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		uniformView = shader_list.at(1)->GetViewLocation();
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera->view_matrix_calc()));
       // surf->draw();
		tetra->draw();

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
	surf->init();
	tetra->init();
	//meshes.push_back(xyz);

}

void Window::Adding_Shaders()
{
	Shader* first_shader = new Shader();
	first_shader->Create_from_file(VShader, FShader);
	shader_list.push_back(first_shader);

	Shader* second_shader = new Shader();
	second_shader->Create_from_file(VShader, FShader);
	shader_list.push_back(second_shader);
	
}

void Window::Call_Back()
{
	glfwSetKeyCallback(main_window, Handle_Key);
	glfwSetCursorPosCallback(main_window, Handle_Mouse); //func for handle mouse should have double parameters for x and y
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

void Window::Handle_Mouse(GLFWwindow* window, double xPos, double yPos)
{
	Window* the_window = static_cast<Window*>(glfwGetWindowUserPointer(window));

	if (the_window->mouse_first_moved) {
		the_window->last_coord_x = static_cast<float>(xPos);
		the_window->last_coord_y = static_cast<float>(xPos);
		the_window->mouse_first_moved = false;
	}
	the_window->x_move = xPos - the_window->last_coord_x;
	the_window->y_move = the_window->last_coord_y-yPos;

	the_window->last_coord_x = xPos;
	the_window->last_coord_y = yPos;

	std::cout << "X change " << the_window->x_move << " Y change " << the_window->y_move << std::endl;
}

GLfloat Window::get_x_change()
{
	GLfloat theChange = x_move;
	x_move = 0.0f;
	return theChange;
}

GLfloat Window::get_y_change()
{
	GLfloat theChange = y_move;
	y_move = 0.0f;
	return theChange;
}
