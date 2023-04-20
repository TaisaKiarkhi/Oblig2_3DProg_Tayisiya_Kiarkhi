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
#include <glm/glm/glm.hpp>
#include <glm/glm/ext/matrix_transform.hpp>
#include <glm/glm/mat4x4.hpp>
#include <glm/glm/gtc/type_ptr.hpp>
#include <Quaternion.h>

typedef GLfloat Matrix4x4[4][4]; //for testing reasons only

class Window
{
public:
	Window();
	~Window();

	void Objects();
	void Other_Objects();
	void Adding_Shaders();
	void create_uniform(GLuint shader, float m_x, float m_y, float m_z, float angle, 
		                float r_x, float r_y, float r_z, float perspective, float near, float far,
		                float scale_x, float scale_y, float scale_z);
    bool Collision_Detection(VisualObject* object_1, VisualObject* object_2);
	void Call_Back();
	static void Handle_Key(GLFWwindow* window, int key, int code, int action, int mode);
	static void handle_key_for_npc(GLFWwindow* window, int key, int action);
	static void Handle_Mouse(GLFWwindow* window, double xPos, double yPos);
	void calculate_average_normals(VisualObject* obj, std::vector <Vertex> verts, unsigned int vector_size);
	GLfloat get_x_change();
	GLfloat get_y_change();

	//uniforms
	GLint _model_location;
	GLint _projection_location;
	GLint _rotation_location;
	GLint _view_location;
	GLint _scale_location;
	GLint x_off_loc;
	GLint y_off_loc;
	GLint  z_off_loc;
	GLint  uniformAmbientColor;
	GLint uniformAmbientIntensity;
	GLint uniform_dif_int, uniform_dir;

	GLint heigth = 1080, width = 1920;      //window size
	const char* window_title{ "Oblig2" };
	const char* path = "cursed_textures/photo-1495578942200-c5f5d2137def.jpg";
	

	int buffer_w, buffer_h;

	std::vector <VisualObject*> meshes;
	std::vector <Shader*> shader_list;
	
	Camera cam;

	GLfloat last_coord_x;
	GLfloat last_coord_y;
	GLfloat deltaTime = 0.0f;
	GLfloat lastTime = 0.0f;
	GLfloat y_move;
	GLfloat x_move;

	bool* get_keys() { return keys; }
    bool keys[1024]; //keys as a ASCII code numbers
	bool mouse_first_moved;
	bool inside;

	GLFWwindow* main_window;

	float c;
};

#endif WINDOW