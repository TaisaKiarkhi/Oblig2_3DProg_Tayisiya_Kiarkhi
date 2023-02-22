

#version 330

layout (location = 0) in vec3 pos;

out vec4 vCol;

uniform mat4 view;
uniform mat4 projection;

void main()
{
	gl_Position = projection* view*vec4(pos, 1.0);
	vCol = vec4(1.0f, 1.0f, 0.0f, 1.0f);
}