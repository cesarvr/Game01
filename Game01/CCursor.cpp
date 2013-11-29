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
    limites = false;
};



void CsCursor::prepararDibujo(){
    
    TexturaUV_t textura;
    
    set_propiedad_imagen(back->getTexturas()->getWidth(), back->getTexturas()->getHeight());
    get_mapping_by_name( "cursor" , &textura );
    
    dibujador.figuraGeometrica(BLOQUE_ANCHO*2, BLOQUE_ALTO, glm::vec3(1.0f,1.0f,1.0f),textura);
    dibujador.setPosicion(_posicion);
    
}



void CsCursor::goDerecha(){
if (_posicion.x < (_limite2.x - BLOQUE_ANCHO) || !limites) {
     _posicion += glm::vec2(BLOQUE_ANCHO,0);
    dibujador.setPosicion(_posicion);
}

}

void CsCursor::goIzquierda(){
    
    if (_posicion.x > _limite1.x || !limites) {
        _posicion += glm::vec2(-BLOQUE_ANCHO,0);
        dibujador.setPosicion(_posicion);
    }


}

void CsCursor::goAbajo(){
if (_posicion.y < _limite2.y || !limites) {
    _posicion += glm::vec2(0.0f,BLOQUE_ALTO);
    dibujador.setPosicion(_posicion);
}
}

void CsCursor::goArriba(){
    if (_posicion.y > _limite1.y || !limites) {
        _posicion += glm::vec2(0.0f,-BLOQUE_ALTO);
        dibujador.setPosicion(_posicion);

    }
}


void CsCursor::pickDosBloques(std::vector<CBloque> listado_bloque, std::vector<CBloque> &dos_bloques){
    //std::vector<CBloque *> dos_bloques;
    
    float x1_uno = _posicion.x;
    float x2_uno = _posicion.x + BLOQUE_ANCHO;
    float x1_dos = _posicion.x + BLOQUE_ANCHO;
    float x2_dos = _posicion.x + BLOQUE_ANCHO*2;
    
    
    float y1 = _posicion.y;
    float y2 = _posicion.y + BLOQUE_ALTO;
    
    
    bool zona1 = false;
    bool zona2 = false;
    
    for (CBloque &bloque : listado_bloque) {
        
        float blqx1 =  bloque.getPosicion().x;
        float blqx2 =  bloque.getPosicion().x + BLOQUE_ANCHO;
        float blqy1 =  bloque.getPosicion().y;
        float blqy2 =  bloque.getPosicion().y + BLOQUE_ALTO;
        
        if (x1_uno <= blqx1 && x2_uno >= blqx2 && y1 == blqy1 && y2 == blqy2) {
            dos_bloques.push_back(bloque);
            zona1 =true;
        }
        
        if (x1_dos <= blqx1 && x2_dos >= blqx2 && y1 == blqy1 && y2 == blqy2) {
            dos_bloques.push_back(bloque);
            zona2 = true;
        }
        
        
        
    }
    
    if (dos_bloques.size() >1) {
        dos_bloques[0].setGoPosicion(dos_bloques[1].getPosicion());
        dos_bloques[1].setGoPosicion(dos_bloques[0].getPosicion());
    }else if (dos_bloques.size() == 1){
        printf("solo uno");
        if (zona1) {
            dos_bloques[0].setGoPosicion(glm::vec2(x2_uno,y1));
        }
        if (zona2) {
            dos_bloques[0].setGoPosicion(glm::vec2(x1_uno,y1));
        }
    
    }
    
   
  
}



void CsCursor::draw(){
    
    dibujador.draw();
    
}





void CsCursor::update(){

    dibujador.update();
    
}