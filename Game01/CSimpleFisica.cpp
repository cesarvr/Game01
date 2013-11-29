//
//  CSimpleFisica.cpp
//  Game01
//
//  Created by Cesar Luis Valdez on 26/11/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#include "CSimpleFisica.h"


CSimpleFisica::CSimpleFisica(){}
CSimpleFisica::CSimpleFisica( float x1, float x2, float y1, float y2 ){

    _x1 = x1;
    _x2 = x2;
    _y1 = y1;
    _y2 = y2;
    

}

bool CSimpleFisica::estaColisionando(CSimpleFisica *objeto_fisico){

    float my_posicion_x = this->_posicion.x + this->_radio;
    float my_posicion_y = this->_posicion.y + this->_radio;
    float obj_posicion_x = objeto_fisico->getPosicion().x + objeto_fisico->getRadio();
    float obj_posicion_y = objeto_fisico->getPosicion().y + objeto_fisico->getRadio();

    glm::vec2 my_vec  = glm::vec2(my_posicion_x,my_posicion_y);
    glm::vec2 obj_vec = glm::vec2(obj_posicion_x, obj_posicion_y);
    
    glm::vec2 distancia = my_vec - obj_vec;
    
    float fdistancia =  glm::length(distancia);
    
    float radio_tamano = this->getRadio() + objeto_fisico->getRadio();
    
    
    /*
    printf("\n -> dist: x: %f, y: %f \n", distancia.x , distancia.y);
    printf(" -> dist_size: %f \n", fdistancia);
    printf(" -> radio: %f \n", this->getRadio());
    printf(" -> radio_tamano: %f \n\n",radio_tamano);
    */
    
    inamovible = false;
    
    
    return (fdistancia <= radio_tamano);
};


void CSimpleFisica::integrar(float delta){

    _posicion += _velocidad * delta;
    glm::vec2 resultado_accel = _aceleracion;


}


void CSimpleFisica::mover_en_xAxis(float velocidad_x){

    _posicion.x += velocidad_x;

}




