//
//  CCursor.cpp
//  Game01
//
//  Created by Cesar Luis Valdez on 26/11/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#include "CCursor.h"


CsCursor::CsCursor(){};

CsCursor::CsCursor( CBackend *backend ){
    
    dibujador = BlockTest( backend );
    back = backend;
    _entrada = backend->getEntradaData();
};



void CsCursor::prepararDibujo(){
    
    TexturaUV_t textura;
    
    set_propiedad_imagen(back->getTexturas()->getWidth(), back->getTexturas()->getHeight());
    get_mapping_by_name( "cursor" , &textura );
    
    dibujador.figuraGeometrica(BLOQUE_ANCHO*2, BLOQUE_ALTO, glm::vec3(1.0f,1.0f,1.0f),textura);
    dibujador.setPosicion(_posicion);
    
}



void CsCursor::goDerecha(){

     _posicion += glm::vec2(BLOQUE_ANCHO,0);
    dibujador.setPosicion(_posicion);


}

void CsCursor::goIzquierda(){
     _posicion += glm::vec2(-BLOQUE_ANCHO,0);
    dibujador.setPosicion(_posicion);

}

void CsCursor::goAbajo(){

    _posicion += glm::vec2(0.0f,BLOQUE_ALTO);
    dibujador.setPosicion(_posicion);
}

void CsCursor::goArriba(){
    
    _posicion += glm::vec2(0.0f,-BLOQUE_ALTO);
    dibujador.setPosicion(_posicion);


}


void CsCursor::draw(){
    
    dibujador.draw();
    
}





void CsCursor::update(){

    dibujador.update();
    
}