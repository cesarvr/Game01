//
//  Bloques.cpp
//  Game01
//
//  Created by Cesar Luis Valdez on 26/11/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#include "Bloques.h"


CBloque::CBloque(){};

CBloque::CBloque( CBackend *backend ){
    
    dibujador = BlockTest( backend );
    back = backend;
};

int roll(int min, int max)
{
    // x is in [0,1[
    double x = rand()/static_cast<double>(RAND_MAX);
    
    // [0,1[ * (max - min) + min is in [min,max[
    int that = min + static_cast<int>( x * (max - min) );
    
    return that;
}


void CBloque::prepararDibujo(){
    
    TexturaUV_t textura;
    
    set_propiedad_imagen(back->getTexturas()->getWidth(), back->getTexturas()->getHeight());
    
    int rand = roll(1, 5);
    
    switch (rand) {
        case 1:
            get_mapping_by_name( "amarillo" , &textura );
            color_nombre= "amarillo";
            break;
        case 2:
            get_mapping_by_name( "rojo" , &textura );
            color_nombre= "rojo";
            break;
        case 3:
            get_mapping_by_name( "azul" , &textura );
            color_nombre= "azul";
            break;
        case 4:
            get_mapping_by_name( "verde" , &textura );
            color_nombre= "verde";
            break;
        default:
            break;
    }
   
    
    dibujador.figuraGeometrica(BLOQUE_ANCHO, BLOQUE_ALTO, glm::vec3(0.8f,0.8f,0.8f),textura);
   dibujador.setPosicion(_posicion);
    
}


void CBloque::mover(float velx){

 
        _fisica->mover_en_xAxis(velx);
        _posicion = _fisica->_posicion;
 
}

void CBloque::draw(){
    
    dibujador.draw();
    
    
}

void CBloque::update(){
    
    glm::vec2 pos = _fisica->getPosicion();
    this->setPosicion(pos);
    // printf("\n x %f y %f", pos.x, pos.y );
    dibujador.setPosicion(pos);
    dibujador.update();
    
}