//
//  ShaderManager.cpp
//  EngineOne
//
//  Created by Cesar Luis Valdez on 12/11/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#include "ShaderManager.h"


void Shader::cargarFicheroShader(const char *vertexShader, const char *fragmentShader)
{
    
    cargarShaders(vertexShader, fragmentShader);

    
}


void Shader::activarPrograma(){

    glUseProgram(getPrograma());

}


void Shader::deactivarPrograma(){

    glUseProgram(0);

}


GLuint Shader::getParametro( const char *nombre ){

    
    GLuint temp =  glGetAttribLocation(getPrograma(), nombre);
    assert(temp != 0xFFFFFFFF);
    
    return temp;


}

GLuint Shader::getUniforme( const char *nombre ){

    GLuint temp =  glGetUniformLocation(getPrograma(), nombre);
    assert(temp != 0xFFFFFFFF);
    
    return temp;

}

