#pragma once
#include <GL/glew.h>
#include <VisualObject.h>
class Heightmap:public VisualObject
{
public:
	Heightmap();
	~Heightmap();

	void load_from_file();
	void draw() override;
	void init() override;

private: 
	int width;
	int height;
	int bitDepth;
	unsigned char* data;
	const char* file= "cursed_heightmap/Heightmap.png";

	const int strips = height - 1, verts_per_strip = width * 2;
};

