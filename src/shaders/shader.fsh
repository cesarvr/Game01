/*
 Cesar Valdez
 
 */

#ifdef GL_ES
precision mediump float;
#endif


uniform sampler2D texture_map;
varying vec2 UVtextura;
varying vec4 effect_color;


void main (void)
{
    vec4 text_color = texture2D(texture_map, UVtextura);

    if (text_color.x == 0.0)
    {
    	/* code */
    	gl_FragColor = effect_color;	
    }else{

    	gl_FragColor = text_color * effect_color;	
    }
       
}