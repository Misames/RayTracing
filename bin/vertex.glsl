#version 330

attribute vec4 a_position;
attribute vec3 a_normal;
attribute vec2 a_texcoords;

uniform float u_time;
uniform mat4 u_translation;
uniform mat4 u_rotation;
uniform mat4 u_scale;
uniform mat4 u_projection;
uniform vec3 lightPos;
uniform vec3 view_pos;

varying vec3 v_color_obj;
varying vec3 v_color_light;
varying vec3 v_normal;
varying vec3 FragPos;

void main()
{
    mat4 model = u_translation * u_rotation * u_scale;
    gl_Position = u_projection * a_position;

    v_color_obj = vec3(1.0, 0.2, 0.4);
    v_color_light = vec3(1.0, 1.0, 1.0);
    v_normal = a_normal;

    FragPos = vec3(model * a_position);
}