#pragma once
#include <VisualObject.h>
#include <Vertex.h>
class House:public VisualObject
{
public:
	House();
	~House();

	void draw() override;
	void init() override;
};

