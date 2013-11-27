//
//  Renderable.cpp
//  EngineOne
//
//  Created by Cesar Luis Valdez on 12/11/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#include "Renderable.h"




Renderable::Renderable(){};
Renderable::Renderable(float *array, int size_array, short *indices, int size_indices){

    
    glGenBuffers(1, &vertexBufferObj);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObj);
    glBufferData(GL_ARRAY_BUFFER, size_array, array, GL_STATIC_DRAW);
    
    glGenBuffers(1, &indicesBufferObj);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indicesBufferObj);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size_indices, indices, GL_STATIC_DRAW);
    
    tamano_indices = size_indices / sizeof(short);
    tamano_total = (POSICION_DATA_TAMANO + COLOR_DATA_TAMANO + TEXTURA_DATA_TAMANO) * sizeof(float);

};


void Renderable::guardarVertices(float *array, int size_array, short *indices, int size_indices){

    glGenBuffers(1, &vertexBufferObj);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObj);
    glBufferData(GL_ARRAY_BUFFER, size_array, array, GL_STATIC_DRAW);
    
    glGenBuffers(1, &indicesBufferObj);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indicesBufferObj);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size_indices, indices, GL_STATIC_DRAW);
    
    tamano_indices = size_indices / sizeof(short);
    tamano_total = (POSICION_DATA_TAMANO + COLOR_DATA_TAMANO + TEXTURA_DATA_TAMANO) * sizeof(float);


}


void Renderable::updateVertices(float *array, int size_array, short *indices, int size_indices){

    glDeleteBuffers(1, &vertexBufferObj);
    glDeleteBuffers(1, &indicesBufferObj);
    
    
    glGenBuffers(1, &vertexBufferObj);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObj);
    glBufferData(GL_ARRAY_BUFFER, size_array, array, GL_DYNAMIC_DRAW);
    
    glGenBuffers(1, &indicesBufferObj);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indicesBufferObj);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size_indices, indices, GL_DYNAMIC_DRAW);
    
    tamano_indices = size_indices / sizeof(short);
    tamano_total = (POSICION_DATA_TAMANO + COLOR_DATA_TAMANO + TEXTURA_DATA_TAMANO) * sizeof(float);
    



}

void Renderable::setMVP(glm::mat4 mvp){

    _mvp = mvp;

}

void Renderable::render(Shader *shader){
  
    shader->activarPrograma();
    
    
    glUniformMatrix4fv(shader->getUniforme("mvp"), 1, GL_FALSE, &_mvp[0][0]);
    
    
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObj);
    
    
    /*
        Posicion Shaders.
     */
    glVertexAttribPointer(shader->getParametro("posicion"),     //Shader
                          POSICION_DATA_TAMANO,                 //Tamano
                          GL_FLOAT,                             //Tipo de dato.
                          GL_FALSE,                             //Falso.
                          tamano_total,                         //Tamano de una linea.
                          0                                     //permutacion
                                                        );
    
    glEnableVertexAttribArray(shader->getParametro("posicion"));
    
    
    /*
        Color Shaders.
     */
   
    glVertexAttribPointer(shader->getParametro("color"),
                          COLOR_DATA_TAMANO,
                          GL_FLOAT,
                          GL_FALSE,
                          tamano_total, (GLvoid*) (sizeof(float) * POSICION_DATA_TAMANO));
    
    glEnableVertexAttribArray(shader->getParametro("color"));
    
    
    
    /*
        Textura Shaders.
    */
    
    glVertexAttribPointer(shader->getParametro("textura"),
                          TEXTURA_DATA_TAMANO,
                          GL_FLOAT,
                          GL_FALSE,
                          tamano_total,
                          (GLvoid*) (sizeof(float) * (POSICION_DATA_TAMANO + COLOR_DATA_TAMANO)));
    
    glEnableVertexAttribArray(shader->getParametro("textura"));
    

    //Usamos indices
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indicesBufferObj);
    
    glDrawElements(GL_TRIANGLE_STRIP, tamano_indices, GL_UNSIGNED_SHORT, 0);
    
    
    shader->deactivarPrograma();

}