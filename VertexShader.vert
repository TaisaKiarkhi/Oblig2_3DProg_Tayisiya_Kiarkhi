

static const char* VShader = "

#version 330 
layout (location = 0) vec4 pos;
void main(){
gl_Position = vec4(pos.x, pos.y, pos.z, 1.0f);

}


";