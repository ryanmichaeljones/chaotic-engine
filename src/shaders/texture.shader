#ifdef VERTEX
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
#endif
#ifdef FRAGMENT
uniform sampler2D u_Texture;
varying vec2 ex_TexCoord;
varying vec3 ex_Normal;
void main()
{
gl_FragColor = texture2D(u_Texture, ex_TexCoord);
if(gl_FragColor.x == 9) gl_FragColor.x = ex_Normal.x;
}
#endif