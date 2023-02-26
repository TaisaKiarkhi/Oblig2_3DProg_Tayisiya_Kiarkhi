#pragma once
#include <VisualObject.h>
class Interactive_Object : public VisualObject
{
public:
	Interactive_Object();
	~Interactive_Object();

	void draw() override;
	void init() override;
};

