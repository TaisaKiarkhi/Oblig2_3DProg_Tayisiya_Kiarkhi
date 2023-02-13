#pragma once
#ifndef WINDOW
#define WINDOW
class Window
{
public:
	Window();
	~Window();


	GLint heigth = 1920, width = 1080;      //window size
	const char* window_title{ "Oblig2" };
	GLint buffer_w;
	GLint buffer_h;

};

#endif WINDOW