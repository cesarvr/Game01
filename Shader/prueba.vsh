/*
 Cesar Valdez
 
 */

uniform mat4 mvp;

attribute vec3 posicion;
attribute vec3 color;
attribute vec2 textura;

varying vec2 textura_cord_out;
varying vec3 s_color;



void main(void)
{
	
	s_color = color;
    textura_cord_out = textura;
    gl_Position = mvp * vec4(posicion, 1.0);
    
    
}