//
//  CSimpleIntegrator.cpp
//  Game01
//
//  Created by Cesar Luis Valdez on 26/11/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#include "CSimpleIntegrator.h"

CSimpleIntegrator::CSimpleIntegrator(){};

CSimpleIntegrator::CSimpleIntegrator(float suelo){

    _y = suelo;
    _gravedad = glm::vec2(0, 10.0f);
}


CSimpleFisica  *CSimpleIntegrator::crearFisicaObjeto(float x1, float y1, float x2, float y2){

    CSimpleFisica *objeto_fisico = new CSimpleFisica(x1,y1,x2,y2);
    objeto_fisico->setPosicion(glm::vec2(x1,y1));
    objetos_colision.push_back(objeto_fisico);
    
    

    return objeto_fisico;
}

void CSimpleIntegrator::integrar(float delta){

    if (delta <0.66f) {
   
    for(CSimpleFisica *_fisik : objetos_colision)
    {
        
        if ( _fisik->_posicion.y+3.4f < _y) {
            _fisik->_velocidad = _gravedad * delta;
            _fisik->_posicion = _fisik->_posicion  + _fisik->_velocidad;
            
        }
  
     
    
    }
        
    }


}