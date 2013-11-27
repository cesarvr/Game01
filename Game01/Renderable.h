//
//  Renderable.h
//  EngineOne
//
//  Created by Cesar Luis Valdez on 12/11/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#ifndef __EngineOne__Renderable__
#define __EngineOne__Renderable__

#include <iostream>
#include "glfw3.h"
#include "ShaderManager.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

static const int POSICION_DATA_TAMANO = 3;
static const int COLOR_DATA_TAMANO = 3;
static const int TEXTURA_DATA_TAMANO = 2;


typedef struct _Vertex{
    float Position[3];
    float Color[4];
    float TexCoord[2]; // New
} Vertex;


class Renderable {
private:
    GLuint vertexBufferObj, indicesBufferObj;
    int tamano_indices;
    int tamano_total;
    glm::mat4 _mvp;
    
    
public:
    Renderable();
    Renderable(float *array, int size_array, short *indices, int size_indices);
    void guardarVertices( float *array, int size_array, short *indices, int size_indices );
    void updateVertices(  float *array, int size_array, short *indices, int size_indices );
    void setMVP(glm::mat4 mvp);
    void render(Shader *shader);
    
};



#endif /* defined(__EngineOne__Renderable__) */
