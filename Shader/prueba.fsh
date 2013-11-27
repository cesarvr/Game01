/*
 Cesar Valdez
 
 */

#ifdef GL_ES
precision mediump float;
#endif

varying vec2 textura_cord_out;
varying vec3 s_color;

//Uniforms.
uniform sampler2D textura;

void main (void)
{
    
    vec4 text_color = texture2D(textura, textura_cord_out);

    vec4 color = vec4(s_color,1.0);
    gl_FragColor = text_color;
  
}
