
#define STB_IMAGE_IMPLEMENTATION
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
#include <Texture.h>
#include<Light.h>
#include <Heightmap.h>
#include <Interactive_Object.h>
using namespace std;


static const char* VShader = "VertexShader.vert";
static const char* FShader = "FragmentShader.frag";
static const char* TextShader = "TextureShader.text";
static const char* TexFragShader = "TexFragShader.txt";
Light* main_light;

	//calculate_average_normals(inter,inter->Vertex_Holder, inter->Vertex_Holder.size());


Window::Window()
{
	x_move = 0.0f,
	y_move = 0.0f;

	for (size_t i = 0; i < 1024; i++){
	keys[i] = 0;
	}

	if (!glfwInit()){
    std::cout << "GLFW Init failed!" << std::endl;
	glfwTerminate();	
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    main_window = glfwCreateWindow(width, heigth, window_title, NULL, NULL);

	if (!main_window){
	std::cout << "failed window";
	}

	glfwGetFramebufferSize(main_window, &buffer_w, &buffer_h);
	glfwMakeContextCurrent(main_window);
	Call_Back(); //pressing keys
	glfwSetInputMode(main_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
	glewExperimental = GL_TRUE;
	glewInit();

	if (glewInit() != GLEW_OK){
		std::cout << "GLEW Init failed!" << std::endl;
		glfwTerminate();
	}

	glEnable(GL_DEPTH_TEST);
	glViewport(0, 0, buffer_w, buffer_h);
    glfwSetWindowUserPointer(main_window, this);
	
	path = "cursed_textures/photo-1495578942200-c5f5d2137def.jpg";
	Texture* cursed_texture = new Texture(path);

	Objects();
	Adding_Shaders();

	//textures and light
	cursed_texture->load_texture();
	main_light = new Light(0.9f, 1.0f, 1.0f, 0.5f, 10.0f, 10.0f, 0.0f, 0.9f);

	NPC* npc = new NPC(); //12
	//calculate_average_normals(npc,npc->Vertex_Holder, npc->Vertex_Holder.size());
	npc->init();
	meshes.push_back(npc);
	
	Interactive_Object* inter = new Interactive_Object(); //13
	
	cam = Camera(glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), -90.0f, 0.0f, 5.0f, 0.5f, *inter);
	Camera* camera_h = new Camera(glm::vec3(-14.0f, 1.0f, -14.0f), glm::vec3(0.0f, 1.0f, 0.0f), -90.0f, 0.0f, 5.0f, 0.5f, *inter);

	calculate_average_normals(inter, inter->Vertex_Holder, inter->Vertex_Holder.size());
	inter->init();
	meshes.push_back(inter);

	inside = false;

	while (!glfwWindowShouldClose(main_window)){
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

		//try to initialize every mesh inside the loop, not separ
		shader_list.at(13)->Use_Shader();

		create_uniform(shader_list.at(13)->Shader_Program, (cam.position.x + 1.0f), cam.position.y, (cam.position.z - 5.0f), 0.0f, cam.front.x, cam.front.y, cam.front.z, 90.f, 0.1f, 100.0f, 1.0f, 1.0f, 1.0f, 0.0f , 0.0f, 0.0f);
		meshes.at(13)->pos = glm::vec3(cam.position.x + 1.0f, cam.position.y, cam.position.z - 5.0f);
		meshes.at(13)->draw();

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
        
    //Random TETRAGONS
	    c = 2;
        for (int i = 3; i < 9; i++){
	  
	    shader_list.at(i)->Use_Shader();
	    create_uniform(shader_list.at(i)->Shader_Program, 5.0f + c, 0.4f, 5.0f + c, 0.0f, 0.0f, 0.0f, 1.0f, 90.0f, 0.1f, 100.0f, 0.4f, 0.4f, 0.4f, 0.0f, 0.0f, 0.0f);
	    cursed_texture->use_texture();
	    meshes.at(i)->pos = glm::vec3(5.0f + c, 0.4f, 5.0f + c);
	  
	    if (meshes.at(i)->collided != true){
	 	   meshes.at(i)->draw();
	    }
	  
	    if (Collision_Detection(inter, meshes.at(i)) == true){
	    meshes.at(i)->collided = true;
	    meshes.at(i)->VAO = 0;
	    meshes.at(i)->VBO = 0;
	    }

	    c += 10.0f + i;
	    c *= -1.2f;
        }

		//object inside the house fixed
	    shader_list.at(9)->Use_Shader();
	    create_uniform(shader_list.at(9)->Shader_Program, -15.0f, .5f, -15.0f, 0.0f, 0.0f, 0.0f, 1.0f, 90.0f, 0.1f, 100.0f, 0.2f, 0.2f, 0.2f, 0.0f, 0.0f, 0.0f);
	    meshes.at(9)->draw();

		//door
        shader_list.at(10)->Use_Shader();
		create_uniform(shader_list.at(10)->Shader_Program, -15.0f, 1.7f, -15.0f, 0.0f, 0.0f, 0.0f, 1.0f, 90.0f, 0.1f, 100.0f, 3.0f, 3.0f, 3.0f, 0.0f, 0.0f, 0.0f);
		meshes.at(10)->draw();

		//npc
		shader_list.at(11)->Use_Shader();
		create_uniform(shader_list.at(11)->Shader_Program, 12.0f, .5f, 9.0f, 0.0f, 0.0f, 0.0f, 1.0f, 90.0f, 0.1f, 100.0f, 0.2f, 0.2f, 0.2f, npc->x_change, npc->y_change, 0.0f);
		meshes.at(12)->draw();

		//heightmap
		shader_list.at(12)->Use_Shader();
		create_uniform(shader_list.at(12)->Shader_Program, -15.0f, -10.0F, -15.0f, 0.0f, 0.0f, 0.0f, 1.0f, 90.0f, 0.1f, 100.0f, 0.2f, 0.2f, 0.2f, 0.0f, 0.0f, 0.0f);
		meshes.at(11)->draw();

		main_light->use_light(uniformAmbientIntensity, uniformAmbientColor, uniform_dif_int, uniform_dir);

		glUseProgram(0);
		glfwSwapBuffers(main_window);
		
	 }

	//destroy objects
	for (int i = 0; i < 6; i++){
	shader_list.at(i)->~Shader();
	meshes.at(i)->~VisualObject();
	}

	cout << meshes.size();
}





//This functuons  creates objects and initialize them
void Window::Objects()
{
	XYZ* xyz = new XYZ(); //0 
	xyz->init();
	meshes.push_back(xyz);
	

	Surface* surf = new Surface(); //1
	calculate_average_normals(surf, surf->Vertex_Holder, surf->Vertex_Holder.size());
	surf->init();
	meshes.push_back(surf);


	House* house = new House();  //2
	calculate_average_normals(house, house->Vertex_Holder, house->Vertex_Holder.size());
	house->init();
	meshes.push_back(house);
    
	//pickups
    for (int i = 0; i < 6; i++) { //3, 4,5,6,7,8
    Tetragons* tet = new Tetragons();
	calculate_average_normals(tet, tet->Vertex_Holder, tet->Vertex_Holder.size());
    tet->init();
    meshes.push_back(tet);
    }

	House_Object* object_inside = new House_Object(); //9
	calculate_average_normals(object_inside, object_inside->Vertex_Holder, object_inside->Vertex_Holder.size());
	object_inside->init();
	meshes.push_back(object_inside);
	

	Door* door = new Door(); //10
	calculate_average_normals(door, door->Vertex_Holder, door->Vertex_Holder.size());
	door->init();
	meshes.push_back(door);
	

	//Map 11
	Heightmap* map = new Heightmap();
	map->init();
	meshes.push_back(map);

    }





//Adds shaders to the objects
void Window::Adding_Shaders()
{
	Shader* xyz_shader = new Shader();    //0
	xyz_shader->Create_from_file(VShader, FShader);
	shader_list.push_back(xyz_shader);

	Shader* surface_shader = new Shader();  //1
	surface_shader->Create_from_file(VShader, FShader);
	shader_list.push_back(surface_shader);

	Shader* house_shader = new Shader();   //2
	house_shader->Create_from_file(VShader, FShader);
	shader_list.push_back(house_shader);

	for (int i = 0; i < 6; i++) { //3 ,4,5, 6,7,8
	Shader* pickups_shader = new Shader();
	pickups_shader->Create_from_file(TextShader, TexFragShader);
	shader_list.push_back(pickups_shader);
	}
	
	Shader* object_inside_house_shader = new Shader(); //9
	object_inside_house_shader->Create_from_file(VShader, FShader);
	shader_list.push_back(object_inside_house_shader);

	Shader* door_shader = new Shader(); //10
	door_shader->Create_from_file(VShader, FShader);
	shader_list.push_back(door_shader);

	Shader* npc_shader = new Shader(); //11
	npc_shader->Create_from_file(VShader, FShader);
	shader_list.push_back(npc_shader);

	

	//TESTING QUTERNION
	

	Shader*map = new Shader(); //12
	map->Create_from_file(VShader, FShader);
	shader_list.push_back(map);

	Shader* interactive_object_shader = new Shader(); //13
	interactive_object_shader->Create_from_file(VShader, FShader);
	shader_list.push_back(interactive_object_shader);

}

//Matrices, model, view, projection
void Window::create_uniform(GLuint shader, float m_x, float m_y, float m_z, float angle,
	float r_x, float r_y, float r_z, float perspective, float near, float far, float scale_x, float scale_y, float scale_z,
	float x_off, float y_off, float z_off)
{
	glm::mat4 model_transform_matrix = glm::translate(glm::mat4(1.0f), glm::vec3(m_x, m_y, m_z));
	glm::mat4 rotation_matrix = glm::rotate(glm::mat4(1.0f), angle, glm::vec3(r_x, r_y, r_z));
	glm::mat4 projection_matrix = glm::perspective(glm::radians(perspective), (GLfloat)buffer_w / (GLfloat)buffer_h, near, far);
	glm::mat4 view = cam.calculateViewMatrix();
	glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(scale_x, scale_y, scale_z));


	float x_o = x_off;
	float y_o = y_off;
	float z_o = z_off;

	_model_location = glGetUniformLocation(shader, "model");
	_projection_location = glGetUniformLocation(shader, "projection");
	_rotation_location = glGetUniformLocation(shader, "rotation");
	_view_location = glGetUniformLocation(shader, "view");
	_scale_location = glGetUniformLocation(shader, "scale");

	uniformAmbientColor = glGetUniformLocation(shader, "dir_light.color");
	uniformAmbientIntensity = glGetUniformLocation(shader, "dir_light.ambient_intens");
	uniform_dif_int = glGetUniformLocation(shader, "dir_light.diffuse_intens");
	uniform_dir = glGetUniformLocation(shader, "dir_light.direction");

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

	main_light->use_light(uniformAmbientIntensity, uniformAmbientColor, uniform_dif_int, uniform_dir);
}



 

bool Window::Collision_Detection(VisualObject* object_1, VisualObject* object_2)
{
	bool collision_in_x = object_1->pos.x + object_1->size_x >= object_2->pos.x && object_2->pos.x + object_2->size_x >= object_1->pos.x;
	bool collision_in_y = object_1->pos.y + object_1->size_y >= object_2->pos.y && object_2->pos.y + object_2->size_y >= object_1->pos.y;
	bool collision_in_z = object_1->pos.z + object_1->size_z >= object_2->pos.z && object_2->pos.z + object_2->size_z >= object_1->pos.z;
	

	return collision_in_x && collision_in_y&&collision_in_z;
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




//CALCULATE NORMALSSSSSSSSSSSSSSSSSSSSSSSS
void Window::calculate_average_normals(VisualObject* obj, std::vector<Vertex> verts, unsigned int vector_size)
{
	for (int i = 0; i < vector_size; i++) {
	if (i+2 >= vector_size)
	{
	return;
	}


	
	 glm::vec3 v1(verts.at(i + 1).xyz_values.x - verts.at(i).xyz_values.x,
	 verts.at(i + 1).xyz_values.y - verts.at(i).xyz_values.y,
	 verts.at(i + 1).xyz_values.z - verts.at(i).xyz_values.z);
	 
	 glm::vec3 v2(verts.at(i + 2).xyz_values.x - verts.at(i).xyz_values.x,

	 verts.at(i + 2).xyz_values.y - verts.at(i).xyz_values.y,
	 verts.at(i + 2).xyz_values.z - verts.at(i).xyz_values.z);
        
	 float n_x = (v1.y * v2.z) - (v1.z * v2.y);
	 float n_y = (v1.z * v2.x) - (v1.x * v2.z);
	 float n_z = (v1.x * v2.y) - (v1.y * v2.x);

	 glm::vec3 normal (n_x, n_y, n_z);
	 normal = glm::normalize(normal);
		//verts.at(i).normal_values = glm::vec3(n_x, n_y, n_z);
	 obj->Vertex_Holder.at(i).normal_values +=normal;
	 obj->Vertex_Holder.at(i+1).normal_values += normal;
		
	}
	std::cout << "calculated" << std::endl;
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




Window::~Window()
{
	glfwDestroyWindow(main_window);
	glfwTerminate();
}

