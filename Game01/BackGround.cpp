//
//  BackGround.cpp
//  Game01
//
//  Created by Cesar Luis Valdez on 25/11/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#include "BackGround.h"


CBackGround::CBackGround(){};

CBackGround::CBackGround( CBackend *backend ){

    dibujador = BlockTest( backend );
    back = backend;
};



void CBackGround::prepararDibujo(){

    TexturaUV_t textura;
    
    set_propiedad_imagen(back->getTexturas()->getWidth(), back->getTexturas()->getHeight());
    get_mapping_by_name( "fondo" , &textura );
    
    dibujador.figuraGeometrica(TABLE_ANCHO, TABLE_ALTO, glm::vec3(1.0f,1.0f,1.0f),textura);
    dibujador.setPosicion(TABLE_POSX, TABLE_POSY);
                     
}

void CBackGround::draw(){

    dibujador.draw();

    
}

void CBackGround::update(){

    dibujador.update();

}