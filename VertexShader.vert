#version 330
layout (location = 0) in vec3 pos;
out vec4 color;

void main(){

gl_Position  = vec4(pos, 1.0f);
color =  vec4(1.0f, 1.0f, 0.0f, 1.0f);
};