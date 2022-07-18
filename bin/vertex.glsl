#version 330

attribute vec4 a_position;
attribute vec3 a_normal;
attribute vec2 a_texcoords;

uniform float u_time;
uniform mat4 u_translation;
uniform mat4 u_rotation;
uniform mat4 u_scale;
uniform mat4 u_projection;

void main()
{
    gl_Position = u_projection * a_position;
}