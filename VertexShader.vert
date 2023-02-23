

#version 330

layout (location = 0) in vec3 pos;

out vec4 vCol;

uniform mat4 view;
uniform mat4 projection;
uniform mat4 model;

void main()
{
	gl_Position = vec4(pos, 1.0);
	
	vCol = vec4(1.0f, 1.0f, 0.0f, 1.0f);
}