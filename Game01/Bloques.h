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
    CSimpleFisica *_fisica;
    
public:
    CBloque( );
    CBloque( CBackend *backend );
    void setPosicion(glm::vec2 posicion){_posicion = posicion;};
    void setFisica( CSimpleFisica *fisica ){_fisica = fisica;};
    
    glm::vec2 getPosicion(){return _posicion;};
    
    
    void prepararDibujo();
    void draw();
    void update();
    
    
    
};


#endif /* defined(__Game01__Bloques__) */
