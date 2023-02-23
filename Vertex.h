#pragma once
#ifndef VERTEX
#define VERTEX
#include <vector>
#include <glm/glm/glm.hpp>
class Vertex
{
public:
	Vertex(float x, float y,  float z,  float r , float g,  float b );
	glm::vec3  xyz_values;
	glm::vec3 rgb_values;

};

#endif VERTEX