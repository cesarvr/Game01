//
//  graphic_engine.c
//  OpenGLCurso
//
//  Created by Cesar Luis Valdez on 25/10/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//






#include "graphic_engine.h"
#include "utilidades.h"

void compilar(GLuint *shader, const char *nombreFichero,  GLenum type);
int realizarLink();
GLuint _program;



void cargar_fichero_maping(const char *nombre_fichero){
    const char *buffer;
    
    leerFichero(nombre_fichero, &buffer);
    
    
    



}



GLuint getPrograma(){


    return _program;
}



/*
 ====================
    Cargar shaders
 ====================
 */


void cargarShaders(const char *vertex_fichero, const char *fragment_fichero){

    
    printf("\n ===================      \n");
    printf("   init shader              \n");
    printf("\n ===================      \n");
    
    
    GLuint vertex_shader = 0, fragment_shader = 0;
    
    
    // Create shader program.
    _program = glCreateProgram();
    
    printf("\n compilando vertex");
    compilar(&vertex_shader, vertex_fichero, GL_VERTEX_SHADER);
    
    printf("\n compilando fragment");
    compilar(&fragment_shader, fragment_fichero, GL_FRAGMENT_SHADER);

    
    
    // Attach vertex shader to program.
    glAttachShader(_program, vertex_shader);
    
    // Attach fragment shader to program.
    glAttachShader(_program, fragment_shader);
    
    
    if (0 == realizarLink()) {
        
        glDeleteShader(vertex_shader);
      
        
        glDeleteShader(fragment_shader);
            
        
        if (_program) {
            glDeleteProgram(_program);
            _program = 0;
        }
        
        printf("Failed to link program: %d", _program);
        return;
    }
    
    // Release vertex and fragment shaders.
    if (vertex_shader) {
        glDetachShader(_program, vertex_shader);
        glDeleteShader(vertex_shader);
    }
    
    if (fragment_shader) {
        glDetachShader(_program, fragment_shader);
        glDeleteShader(fragment_shader);
    }

    printf("\n ===================  \n");
    printf("   shader cargado       \n");
    printf("\n ===================  \n");
    
    glUseProgram(_program);
    
    
    
}



/*
 ====================
 Linkar
 ====================
*/

int realizarLink(){
    
    GLint status;
    glLinkProgram(_program);
    
#if defined(DEBUG)
    GLint logLength;
    glGetProgramiv(_program, GL_INFO_LOG_LENGTH, &logLength);
    if (logLength > 0) {
        GLchar *log = (GLchar *)malloc(logLength);
        glGetProgramInfoLog(_program, logLength, &logLength, log);
        printf("Program link log:\n%s", log);
        free(log);
    }
#endif
    
    glGetProgramiv(_program, GL_LINK_STATUS, &status);
    return  status;

}



/*
 ====================
    Compilar
 ====================
*/




void compilar(GLuint *shader,const char *nombreFichero,  GLenum type){

    
    GLint status;
    const char *source;
    
    leerFichero(nombreFichero, &source);
    
   // printf("%s", source);
    
    
    *shader = glCreateShader(type);
    glShaderSource(*shader, 1,&source, NULL);
    glCompileShader(*shader);
    
#if defined(DEBUG)
    GLint logLength;
    glGetShaderiv(*shader, GL_INFO_LOG_LENGTH, &logLength);
    if (logLength > 0) {
        GLchar *log = (GLchar *)malloc(logLength);
        glGetShaderInfoLog(*shader, logLength, &logLength, log);
        printf("error -> %s", log);
        free(log);
    }
#endif
    
    
    free((char*)source);
    
    glGetShaderiv(*shader, GL_COMPILE_STATUS, &status);
    if (status == 0) {
        glDeleteShader(*shader);
        
        
        return;
    }
    
    

}



