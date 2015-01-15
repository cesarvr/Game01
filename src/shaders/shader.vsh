/*Cesar Valdez*/

uniform mat4 mv;

attribute vec3 position;
attribute vec4 color;
attribute vec2 textura_uv;

varying vec2 UVtextura;
varying vec4 effect_color;

void main(void)
{
	
    gl_Position = mv * vec4(position, 1.0);
    effect_color = color;
    UVtextura = textura_uv;
}