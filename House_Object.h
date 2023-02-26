#pragma once
#include <VisualObject.h>
#include <Vertex.h>
class House_Object :public VisualObject
{
public:
	House_Object();
	~House_Object();

	void draw() override;
	void init() override;
};

