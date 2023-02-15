#pragma once
#ifndef VERTEX
#define VERTEX
#include <vector>
class Vertex
{
public:
	Vertex(float x, float y,  float z,  float r , float g,  float b );
	std::vector <float> xyz_values;
	std::vector <float> rgb_values;

};

#endif VERTEX