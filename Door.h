#pragma once
#include <VisualObject.h>
class Door:public VisualObject
{
public:
	Door();
	~Door();

	void draw() override;
	void init() override;
};

