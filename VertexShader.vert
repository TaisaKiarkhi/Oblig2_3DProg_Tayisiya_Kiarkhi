

#version 330

layout (location = 0) in vec3 pos;
layout (location = 1) in float offset;

out vec4 vCol;

uniform mat4 rotation;
uniform mat4 projection;
uniform mat4 model;
uniform mat4 view;

void main()
{
	gl_Position = projection*view*model*rotation*vec4(pos, 1.0);
	
	vCol = vec4(clamp(pos, 0.0f, 1.0f), 1.0f);
}