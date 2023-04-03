#pragma once
#ifndef VERTEX
#define VERTEX
#include <vector>
#include <glm/glm/glm.hpp>
class Vertex
{
public:
	Vertex(float x, float y,  float z,  float r , float g,  float b, float u, float v, float x_n, float y_n, float z_n );
	glm::vec3  xyz_values;
	glm::vec3 rgb_values;
	glm::vec2 uv_values;
	glm::vec3 normal_values;

};

#endif VERTEX