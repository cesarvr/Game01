//
//  BlockTest.h
//  EngineOne
//
//  Created by Cesar Luis Valdez on 12/11/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#ifndef __EngineOne__BlockTest__
#define __EngineOne__BlockTest__

#include <iostream>
#include "Renderable.h"
#include "CsBackEnd.h"
#include "ShaderManager.h"
#include "CsTexturas.h"
#include "config_manager.h"

/*
 
 Clase compuesta
 
 _modelo matrix que maneja la world cordinates del objeto.
 _camara maneja y controla la visualizacion.
 
 
 _render clase encargada de dibujar todo.
 
 
 
 */



class BlockTest {
private:
    glm::mat4 _modelo;
    glm::mat4 *_camara;
    glm::vec3 colores;
    Renderable render;
    Shader *_shader;
    
    
public:
    
    BlockTest();
    BlockTest( CBackend *backend );
   
    virtual void figuraGeometrica(float ancho , float alto, glm::vec3 color, TexturaUV_t textura );
    
    void setPosicion( float x, float y );
    void setPosicion( glm::vec2 posicion );
    
    void draw();
    void update();
    
};



#endif /* defined(__EngineOne__BlockTest__) */
