#version 430 core

uniform sampler2D u_Texture;
varying vec2 ex_TexCoord;
varying vec3 ex_Normal;

void main()
{
gl_FragColor = texture2D(u_Texture, ex_TexCoord);
if (gl_FragColor.x == 9) gl_FragColor.x = ex_Normal.x;
}