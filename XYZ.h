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

	

};

#endif  VISUAL_OBJECT