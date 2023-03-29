#pragma once
#include <GL/glew.h>
#include <stb_image.h>
#include <iostream>
class Texture
{
public: 
	//Texture();
	Texture(const char* file_loc);
	~Texture();

	void load_texture();
	void use_texture();

private: 
	GLuint TextureID;
	int width, height, bitDepth;

	const char* file_location;
};




