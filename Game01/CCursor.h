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
#include "BackGround.h"

class CsCursor {
    BlockTest dibujador;
    CBackend *back;
    glm::vec2 _posicion;
    CEntradaData *_entrada;
    
    glm::vec2 _limite1;
    glm::vec2 _limite2;
    bool limites;
public:
    CsCursor( );
    CsCursor( CBackend *backend );
    void setPosicion(glm::vec2 posicion){_posicion = posicion;};
    void setLimite1(glm::vec2 limite){ _limite1 = limite; };
    void setLimite2(glm::vec2 limite2){ _limite2 = limite2; };
    void prepararDibujo();
    void draw();
    void update();
    
    
    void goDerecha();
    void goIzquierda();
    void goArriba();
    void goAbajo();
    
    
    void pickDosBloques(std::vector<CBloque> listado_bloque, std::vector<CBloque> &dos_bloques);
    
    
};



#endif /* defined(__Game01__CCursor__) */
