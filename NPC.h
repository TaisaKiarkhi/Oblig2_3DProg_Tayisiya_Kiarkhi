#pragma once
#include <VisualObject.h>
#include <Vertex.h>
#include <cmath>
class NPC :public VisualObject
{
public:
	NPC();
	~NPC();

	void draw() override;
	void init() override;



	void Function_y();

	
};
