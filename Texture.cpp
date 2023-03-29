#include "Texture.h"
#include <stb_image.h>

//Texture::Texture()
//{
//	TextureID = 0;
//	width = 0;
//	height = 0;
//	file_location = 0;
//}

Texture::Texture(const char* file_loc)
{
	TextureID = 0;
	width = 0;
	height = 0;
	file_location = file_loc;
}

Texture::~Texture()
{
}

void Texture::load_texture()
{
	unsigned char* texture_data = stbi_load(file_location, &width, &height, &bitDepth, 0);

	if (!texture_data) {
		std::cout << "Failed to find the file, location" << std::endl;
	}
	glGenTextures(1, &TextureID);
	glBindTexture(GL_TEXTURE_2D, TextureID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, texture_data);
	glGenerateMipmap(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,0);

	stbi_image_free(texture_data);
}

void Texture::use_texture()
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, TextureID);
}
