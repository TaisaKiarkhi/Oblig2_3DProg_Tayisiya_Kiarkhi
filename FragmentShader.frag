#version 330

in vec4 Col;

out vec4 colour;


struct Direct_Light{
vec3 color;
float ambient_intens;
};

uniform Direct_Light dir_light;

void main()
{
vec4 ambient_color = vec4(dir_light.color, 1.0f)*dir_light.ambient_intens;
	colour = Col*ambient_color;
}