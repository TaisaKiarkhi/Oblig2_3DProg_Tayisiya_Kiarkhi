

#version 330

layout (location = 0) in vec3 pos;
layout(location = 1) in vec4 color;

out vec4 Col;

uniform mat4 rotation;
uniform mat4 projection;
uniform mat4 model;
uniform mat4 scale;
uniform mat4 view;
uniform float x_offset;
uniform float y_offset;
uniform float z_offset;

void main()
{
	gl_Position = projection*view*model*rotation*scale*vec4(pos.x + x_offset, pos.y + y_offset, pos.z + z_offset, 1.0);
	
	Col = color;
}