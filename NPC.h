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


	void press_key_to_change_function(bool* key);
	void Function_y();
	void Function_y_v_2();

	
};
