#version 330

in vec4 Col;
in vec3 Normals;
out vec4 colour;


struct Direct_Light{
vec3 color;
float ambient_intens;
vec3 direction;
float diffuse_intens;
};

uniform Direct_Light dir_light;

void main()
{
vec4 ambient_color = vec4(dir_light.color, 1.0f)*dir_light.ambient_intens;
float diffuse_factor= max(dot(normalize(Normals), normalize(dir_light.direction)), 0.0f);
vec4 diffuse_color = vec4(dir_light.color, 1.0f)*dir_light.diffuse_intens*diffuse_factor;
colour = Col*(ambient_color+diffuse_color);
}