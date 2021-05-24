#version 430 core

attribute vec3 a_Position;
attribute vec2 a_TexCoord;
attribute vec3 a_Normal;
uniform mat4 u_Projection;
uniform mat4 u_View;
uniform mat4 u_Model;
varying vec2 ex_TexCoord;
varying vec3 ex_Normal;

void main()
{
gl_Position = u_Projection * u_View * u_Model * vec4(a_Position, 1);
ex_TexCoord = a_TexCoord;
ex_Normal = a_Normal;
}

