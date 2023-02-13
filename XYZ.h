#pragma once
#ifndef VISUAL_OBJECT
#define VISUAL_OBJECT
#include <VisualObject.h>

class XYZ : public VisualObject
{
public:
	XYZ();
	void draw() override;
	void init() override;

	unsigned int VAO{0};
	unsigned int VBO{0};

};

#endif  VISUAL_OBJECT