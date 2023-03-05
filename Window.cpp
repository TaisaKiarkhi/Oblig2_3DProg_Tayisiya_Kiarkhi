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
#include <House.h>
#include <Camera.h>
#include <House_Object.h>
#include "NPC.h"
#include <Door.h>
#include <Quaternion.h>
using namespace std;

typedef GLfloat Matrix4x4[4][4]; //for testing reasons only
void matrix4x4SetIdentity(Matrix4x4 matIdent4x4);
void translate3D(GLfloat tx, GLfloat ty, GLfloat tz);

static const char* VShader = "VertexShader.vert";
static const char* FShader = "FragmentShader.frag";

GLFWwindow* main_window;
Camera* camera;
Interactive_Object* inter = new Interactive_Object();
NPC* npc = new NPC();
bool inside = false;

Window::Window()
{
	x_move = 0.0f,
	y_move = 0.0f;

	for (size_t i = 0; i < 1024; i++)
	{
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
	glfwSetInputMode(main_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);



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

	cam= Camera(glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), -90.0f, 0.0f, 5.0f, 0.5f, *inter);
	Camera * camera_h = new Camera(glm::vec3(-14.0f, 1.0f, -14.0f), glm::vec3(0.0f, 1.0f, 0.0f), -90.0f, 0.0f, 5.0f, 0.5f, *inter);
	
	npc->init();
	meshes.push_back(npc);
	

	inter->init();
	
	Matrix4x4 some_matrix;
	//just testing
  	translate3D(3.4f, 1.5f, 2.9f);

	//MATRICES 

	while (!glfwWindowShouldClose(main_window)) {
		GLfloat current_time = glfwGetTime();
		deltaTime = current_time - lastTime;
		lastTime = current_time;

		glfwPollEvents();

		
		//npc->press_key_to_change_function();
		cam.keyControl(this->get_keys(), deltaTime);
		cam.mouseControl(this->get_x_change());
		cam.key_h_contro(this->get_keys());
		npc->press_key_to_change_function(this->get_keys());
		
		//inter->keyControl(this->get_keys(), deltaTime);
		//inter->mouseControl(this->get_x_change());


		glClearColor(0.537f, 0.812f, 0.941f, 0.50f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // GL_DEPTH_BUFFER_BIT 

		//try to initialize every mesh inside the loop, not separate



		//poor playable character
		shader_list.at(10)->Use_Shader();


	
		//glm::mat4 model_transform_matrix = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f ,0.0f, -5.0f));
		glm::mat4 model_transform_matrix = glm::translate(glm::mat4(1.0f), glm::vec3(cam.position.x+1.0f, cam.position.y, cam.position.z-5.0f));
		glm::mat4 rotation_matrix = glm::rotate(glm::mat4(1.0f), 0.0f, glm::vec3(cam.front.x, cam.front.y, cam.front.z));
		glm::mat4 projection_matrix = glm::perspective(glm::radians(90.0f), (GLfloat)buffer_w / (GLfloat)buffer_h, 0.1f, 100.0f);
		glm::mat4 view = cam.calculateViewMatrix();
		glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f));

		
		
		

		float x_o = 0.0f;
		float y_o = 0.0f;
		float z_o = 0.0f;

		_model_location = glGetUniformLocation(shader_list.at(10)->Shader_Program, "model");
		_projection_location = glGetUniformLocation(shader_list.at(10)->Shader_Program, "projection");
		_rotation_location = glGetUniformLocation(shader_list.at(10)->Shader_Program, "rotation");
		_view_location = glGetUniformLocation(shader_list.at(10)->Shader_Program, "view");
		_scale_location = glGetUniformLocation(shader_list.at(10)->Shader_Program, "scale");





		x_off_loc = glGetUniformLocation(shader_list.at(10)->Shader_Program, "x_offset");
		y_off_loc = glGetUniformLocation(shader_list.at(10)->Shader_Program, "y_offset");
		z_off_loc = glGetUniformLocation(shader_list.at(10)->Shader_Program, "z_offset");

		glUniformMatrix4fv(_model_location, 1, GL_FALSE, glm::value_ptr(model_transform_matrix));
		glUniformMatrix4fv(_projection_location, 1, GL_FALSE, glm::value_ptr(projection_matrix));
		glUniformMatrix4fv(_rotation_location, 1, GL_FALSE, glm::value_ptr(rotation_matrix));
		glUniformMatrix4fv(_view_location, 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(_scale_location, 1, GL_FALSE, glm::value_ptr(scale));

		glUniform1f(x_off_loc, x_o);
		glUniform1f(y_off_loc, y_o);
		glUniform1f(z_off_loc, z_o);

		inter->pos = glm::vec3(cam.position.x + 1.0f, cam.position.y, cam.position.z - 5.0f);
		inter->draw();






		//XYZ
        shader_list.at(0)->Use_Shader();
        create_uniform(shader_list.at(0)->Shader_Program, 0.0f, 0.0f, -5.0f, 0.0f, 0.0f, -4.0f, 1.0f, 90.0f, 0.1f, 100.0f , 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f);
		
        meshes.at(0)->draw();
        
		//SURFACE
        shader_list.at(1)->Use_Shader();
        create_uniform(shader_list.at(1)->Shader_Program, 0.0f, 0.0f, -5.0f, 0.0f, 0.0f, -4.0f, 1.0f, 90.0f, 0.1f, 100.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f);
		
		meshes.at(1)->draw();

		//HOUSE
        shader_list.at(2)->Use_Shader();
        create_uniform(shader_list.at(2)->Shader_Program, -15.0f, 1.7f, -15.0f, 0.0f, 0.0f, 0.0f, 1.0f, 90.0f, 0.1f, 100.0f, 3.0f, 3.0f, 3.0f, 0.0f, 0.0f, 0.0f);
		
        meshes.at(2)->draw();
        

		shader_list.at(2)->Use_Shader();
		create_uniform(shader_list.at(2)->Shader_Program, -15.0f, 1.7f, -15.0f, 0.0f, 0.0f, 0.0f, 1.0f, 90.0f, 0.1f, 100.0f, 3.0f, 3.0f, 3.0f, 0.0f, 0.0f, 0.0f);

		meshes.at(2)->draw();


		//Random TETRAGONS
        float c = 2.0;
		
		

   for (int i = 3; i < 9; i++) {

	   shader_list.at(i)->Use_Shader();
	   create_uniform(shader_list.at(i)->Shader_Program, 5.0f + c, 0.4f, 5.0f + c, 0.0f, 0.0f, 0.0f, 1.0f, 90.0f, 0.1f, 100.0f, 0.4f, 0.4f, 0.4f, 0.0f, 0.0f, 0.0f);
	   meshes.at(i)->pos = glm::vec3(5.0f + c, 0.4f, 5.0f + c);

	   if (meshes.at(i)->collided != true) {
		   meshes.at(i)->draw();
	   }

	   if (Collision_Detection(inter, meshes.at(i)) == true) {
		   meshes.at(i)->collided = true;
		   meshes.at(i)->VAO = 0;
		   meshes.at(i)->VBO = 0;
	   }


	   c += 10.0f + i;
	   c *= -1.2f;
    }


		//object inside the house
		shader_list.at(9)->Use_Shader();
		create_uniform(shader_list.at(9)->Shader_Program, -15.0f, .5f, -15.0f, 0.0f, 0.0f, 0.0f, 1.0f, 90.0f, 0.1f, 100.0f, 0.2f, 0.2f, 0.2f, 0.0f, 0.0f, 0.0f);
		meshes.at(9)->draw();

		//npc
		shader_list.at(12)->Use_Shader();
		
		create_uniform(shader_list.at(12)->Shader_Program, 12.0f, .5f, 9.0f, 0.0f, 0.0f, 0.0f, 1.0f, 90.0f, 0.1f, 100.0f, 0.2f, 0.2f, 0.2f, npc->x_change,npc->y_change, 0.0f);
		npc->draw();


		//door
	shader_list.at(11)->Use_Shader();
	//create_uniform(shader_list.at(11)->Shader_Program, -15.0f, 1.7f, -15.0f, 90.0f, 0.0f, 0.0f, 1.0f, 90.0f, 0.1f, 100.0f, 3.0f, 3.0f, 3.0f, 0.0f, 0.0f, 0.0f);
	




		//glm::mat4 model_transform_matrix = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f ,0.0f, -5.0f));
		glm::mat4 model_transform_matrix_d = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));
		glm::mat4 rotation_matrix_d = glm::rotate(glm::mat4(1.0f), -90.0f, glm::vec3(0.0f, 1.7f, 0.0f));
		model_transform_matrix_d = glm::translate(glm::mat4(1.0f), glm::vec3(-15.0f, 1.7f, -15.0f));
		glm::mat4 projection_matrix_d= glm::perspective(glm::radians(90.0f), (GLfloat)buffer_w / (GLfloat)buffer_h, 0.1f, 100.0f);
		glm::mat4 view_d = cam.calculateViewMatrix();
		glm::mat4 scale_d = glm::scale(glm::mat4(1.0f), glm::vec3(3.0f, 3.0f, 3.0f));





		float x__d_o = 0.0f;
		float y__d_o = 0.0f;
		float z__d_o = 0.0f;

		_model_location = glGetUniformLocation(shader_list.at(10)->Shader_Program, "model");
		_projection_location = glGetUniformLocation(shader_list.at(10)->Shader_Program, "projection");
		_rotation_location = glGetUniformLocation(shader_list.at(10)->Shader_Program, "rotation");
		_view_location = glGetUniformLocation(shader_list.at(10)->Shader_Program, "view");
		_scale_location = glGetUniformLocation(shader_list.at(10)->Shader_Program, "scale");





		x_off_loc = glGetUniformLocation(shader_list.at(10)->Shader_Program, "x_offset");
		y_off_loc = glGetUniformLocation(shader_list.at(10)->Shader_Program, "y_offset");
		z_off_loc = glGetUniformLocation(shader_list.at(10)->Shader_Program, "z_offset");

		glUniformMatrix4fv(_model_location, 1, GL_FALSE, glm::value_ptr(model_transform_matrix_d));
		glUniformMatrix4fv(_projection_location, 1, GL_FALSE, glm::value_ptr(projection_matrix_d));
		glUniformMatrix4fv(_rotation_location, 1, GL_FALSE, glm::value_ptr    (rotation_matrix_d));
		glUniformMatrix4fv(_view_location, 1, GL_FALSE, glm::value_ptr                 (view_d));
		glUniformMatrix4fv(_scale_location, 1, GL_FALSE, glm::value_ptr                (scale_d));

		glUniform1f(x_off_loc, x__d_o);
		glUniform1f(y_off_loc, y__d_o);
		glUniform1f(z_off_loc, z__d_o);

		meshes.at(11)->draw();






		//TESTING QUATERNION
		shader_list.at(12)->Use_Shader();
		quaternion_test = new Quaternion(-15.0f, 5.0f, -15.0f);
		quaternion_test->matrix4x4SetIdentity(quaternion_test->Matrix_Rotation);
		glm::mat4 rotation_results = quaternion_test->rotate3D_Quaternion();



		glUseProgram(0);
		glfwSwapBuffers(main_window);
		
	}

	//destroy objects
	for (int i = 0; i < 6; i++) {
		shader_list.at(i)->~Shader();
		meshes.at(i)->~VisualObject();
	}

	cout << meshes.size();
}

Window::~Window()
{
	glfwDestroyWindow(main_window);
	glfwTerminate();
}

void Window::Objects()
{
	XYZ* xyz = new XYZ();
	Surface* surf = new Surface();
	Tetragons* tetra = new Tetragons();
	House* house = new House();
	

    xyz->init();
    surf->init();
    house->init();
	
    
    meshes.push_back(xyz);
    meshes.push_back(surf);
    meshes.push_back(house);
    
    for (int i = 0; i < 6; i++) {
    Tetragons* tet = new Tetragons();
    tet->init();
    meshes.push_back(tet);
    }

	House_Object* object_inside = new House_Object();
	object_inside->init();
	meshes.push_back(object_inside);
	meshes.push_back(inter);

	Door* door = new Door();
	door->init();
	meshes.push_back(door);
	

	//TESTING QUATERNION
	House_Object* quat = new House_Object();
	quat->init();
	meshes.push_back(quat);



    }

void Window::Adding_Shaders()
{
	Shader* first_shader = new Shader();
	first_shader->Create_from_file(VShader, FShader);
	shader_list.push_back(first_shader);

	Shader* second_shader = new Shader();
	second_shader->Create_from_file(VShader, FShader);
	shader_list.push_back(second_shader);

	Shader* t_shader = new Shader();
	t_shader->Create_from_file(VShader, FShader);
	shader_list.push_back(t_shader);

	for (int i = 0; i < 6; i++) {
		Shader* t = new Shader();
		t->Create_from_file(VShader, FShader);
		shader_list.push_back(t);
	}
	

	Shader* ob_s = new Shader();
	ob_s->Create_from_file(VShader, FShader);
	shader_list.push_back(ob_s);

	Shader* i = new Shader();
	i->Create_from_file(VShader, FShader);
	shader_list.push_back(i);

	Shader* npc_s = new Shader();
	npc_s->Create_from_file(VShader, FShader);
	shader_list.push_back(npc_s);

	Shader* door_s = new Shader();
	door_s->Create_from_file(VShader, FShader);
	shader_list.push_back(door_s);

	//TESTING QUTERNION
	Shader* quat = new Shader();
	quat->Create_from_file(VShader, FShader);
	shader_list.push_back(quat);

}

//Matrices, model, view, projection
void Window::create_uniform(GLuint shader, float m_x, float m_y, float m_z, float angle,
	float r_x, float r_y, float r_z, float perspective, float near, float far, float scale_x, float scale_y, float scale_z,
	float x_off, float y_off, float z_off)
{
	glm::mat4 model_transform_matrix = glm::translate(glm::mat4(1.0f), glm::vec3(m_x, m_y, m_z));
	glm::mat4 rotation_matrix = glm::rotate(glm::mat4(1.0f), angle, glm::vec3(r_x, r_y, r_z));
	glm::mat4 projection_matrix = glm::perspective(glm::radians(perspective), (GLfloat)buffer_w / (GLfloat)buffer_h,near, far);
	glm::mat4 view = cam.calculateViewMatrix();
	glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(scale_x, scale_y, scale_z));


	float x_o = x_off;
	float y_o = y_off;
	float z_o = z_off;

	_model_location = 	   glGetUniformLocation(shader, "model");
	_projection_location = glGetUniformLocation(shader, "projection");
	_rotation_location =   glGetUniformLocation(shader, "rotation");
	_view_location = glGetUniformLocation(shader, "view");
	_scale_location = glGetUniformLocation(shader, "scale");

	 x_off_loc = glGetUniformLocation(shader, "x_offset");
	 y_off_loc = glGetUniformLocation(shader, "y_offset");
	 z_off_loc = glGetUniformLocation(shader, "z_offset");

	glUniformMatrix4fv(_model_location, 1, GL_FALSE, glm::value_ptr(model_transform_matrix));
	glUniformMatrix4fv(_projection_location, 1, GL_FALSE, glm::value_ptr(projection_matrix));
	glUniformMatrix4fv(_rotation_location, 1, GL_FALSE, glm::value_ptr(rotation_matrix));
	glUniformMatrix4fv(_view_location, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(_scale_location, 1, GL_FALSE, glm::value_ptr(scale));

	glUniform1f(x_off_loc, x_o);
	glUniform1f(y_off_loc, y_o);
	glUniform1f(z_off_loc, z_o);
}







bool Window::Collision_Detection(VisualObject* object_1, VisualObject* object_2)
{
	bool collision_in_x = object_1->pos.x + object_1->size_x >= object_2->pos.x && object_2->pos.x + object_2->size_x >= object_1->pos.x;
	bool collision_in_y = object_1->pos.y + object_1->size_y >= object_2->pos.y && object_2->pos.y + object_2->size_y >= object_1->pos.y;

	return collision_in_x && collision_in_y;
}






void Window::Handle_Mouse(GLFWwindow* window, double xPos, double yPos)
{
	Window* the_window = static_cast<Window*>(glfwGetWindowUserPointer(window));

	if (the_window->mouse_first_moved) {
		the_window->last_coord_x = xPos;
		the_window->last_coord_y = yPos;
		the_window->mouse_first_moved = false;
	}

	the_window->x_move = xPos - the_window->last_coord_x;
	the_window->y_move =  yPos-the_window->last_coord_y;

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

	//if (key == GLFW_KEY_P && action == GLFW_PRESS) {
	//	npc->Function_y();
	//}

	//if (key == GLFW_KEY_O && action == GLFW_PRESS) {
	//	npc->Function_y_v_2();
	//}

	if (key >= 0 && key < 1024) {
		if (action == GLFW_PRESS) {
			the_window->keys[key] = true;
			std::cout << "The key is pressed: " << key << std::endl;
		}

		else if (action == GLFW_RELEASE) {
			the_window->keys[key] = false;
			std::cout << "The kkey is released " << key << std::endl;
		}


	}
}




void matrix4x4SetIdentity(Matrix4x4 matIdent4x4) {
	GLint row, column;

	for (row = 0; row < 4; row++) {
		for (column = 0; column < 4; column++) {
			matIdent4x4[row][column] = (row == column); // row == column sets values between 1 and 0 (true and false)
		}
	}
}

void translate3D(GLfloat tx, GLfloat ty, GLfloat tz)
{
	Matrix4x4 matTransl3D;
	matrix4x4SetIdentity(matTransl3D);

	matTransl3D[0][3] = tx;
	matTransl3D[1][3] = ty;
	matTransl3D[2][3] = tz;
	//matTransl3D[3][3] = 1; //maybe wrong, delete later
}
