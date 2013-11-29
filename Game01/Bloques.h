//
//  Bloques.h
//  Game01
//
//  Created by Cesar Luis Valdez on 26/11/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#ifndef __Game01__Bloques__
#define __Game01__Bloques__

#include <iostream>
#include "BlockTest.h"
#include "CSimpleIntegrator.h"

#define BLOQUE_ANCHO 3.0f
#define BLOQUE_ALTO 3.0f



class CBloque {
private:
    BlockTest dibujador;
    CBackend *back;
    glm::vec2 _posicion;
    glm::vec2 _go_posicion;
    
    CSimpleFisica *_fisica;
    std::string color_nombre;
    GLfloat *vertices;
    GLshort *indices;
    
    
public:
    CBloque( );
    CBloque( CBackend *backend );
    void setPosicion(glm::vec2 posicion){_posicion = posicion;};
    void setFisica( CSimpleFisica *fisica ){_fisica = fisica;};
    
    glm::vec2 getPosicion(){return _posicion;};
    
    void    setGoPosicion(  glm::vec2 go_posicion   ){_go_posicion = go_posicion;};
    glm::vec2 getGoPosicion(){return _go_posicion; };
    
    std::string getColor(){return color_nombre; }
    
    
    void mover(float velx);
    
    
    void prepararDibujo();
    void draw();
    void update();
    
    
    
};


#endif /* defined(__Game01__Bloques__) */
