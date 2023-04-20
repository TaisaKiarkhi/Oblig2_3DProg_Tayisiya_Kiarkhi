

#version 330

layout (location = 0) in vec3 pos;
layout(location = 1) in vec4 color;
layout (location = 2) in vec2 textures;
layout(location = 3) in vec3 normal;

out vec4 Col;
out vec2 tex_coord;
out vec3 Normals;

uniform mat4 rotation;
uniform mat4 projection;
uniform mat4 model;
uniform mat4 scale;
uniform mat4 view;

void main()
{
	gl_Position = projection*view*model*rotation*scale*vec4(pos, 1.0);
	
	Col = color;

       tex_coord = textures;
	   Normals = mat3(transpose(inverse(model)))*normal;
}