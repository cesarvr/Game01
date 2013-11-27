//
//  CCursor.h
//  Game01
//
//  Created by Cesar Luis Valdez on 26/11/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#ifndef __Game01__CCursor__
#define __Game01__CCursor__

#include <iostream>
#include "BlockTest.h"
#include "Bloques.h"
#include "CEntrada.h"


class CsCursor {
    BlockTest dibujador;
    CBackend *back;
    glm::vec2 _posicion;
    CEntradaData *_entrada;
    
    
    
public:
    CsCursor( );
    CsCursor( CBackend *backend );
    void setPosicion(glm::vec2 posicion){_posicion = posicion;};
    void prepararDibujo();
    void draw();
    void update();
    
    
    void goDerecha();
    void goIzquierda();
    void goArriba();
    void goAbajo();
    
    
};



#endif /* defined(__Game01__CCursor__) */
