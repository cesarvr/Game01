//
//  CSimpleFisica.h
//  Game01
//
//  Created by Cesar Luis Valdez on 26/11/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#ifndef __Game01__CSimpleFisica__
#define __Game01__CSimpleFisica__

#include <iostream>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

class CSimpleFisica {
    
private:
    float _x1, _x2, _y1, _y2;
    float _radio;  // detectar colision.
    short _indice;
    float _mass;
    float _coefficiente_restitucion;
    bool inamovible;
    
public:
    
    CSimpleFisica();
    CSimpleFisica( float x1, float x2, float y1, float y2 );
    
    // fisica related things
    
    bool estaColisionando(CSimpleFisica *objeto_fisico);
    
    
    
    
    // getter-setters.
    
    void mover_en_xAxis(float velocidad_x);
    
    void  setPosicion(  glm::vec2 posicion  ){   _posicion  = posicion; };
    glm::vec2 getPosicion(){ return _posicion; };
    
    
    void  setMass(float mass){   _mass  = mass; };
    float getMass(){ return _mass; };
    
    
    void  setVelocidad( glm::vec2 velocidad ){  _velocidad  = velocidad; };
    
    void  setRadio( float radio ){ _radio = radio; };
    float getRadio(){ return _radio; };
    
    void  setIndice( short indice ){ _indice = indice; };
    short getIndice(){ return _indice; };
    
    
    void setCoeficienteRestitucion(float restitucion){ _coefficiente_restitucion = restitucion;};
    float getCoeficienteRestitucion(){return _coefficiente_restitucion; };
    
    void setInamovible(bool _inamobible){ inamovible = _inamobible;};
    float isInamovible(){return inamovible; };
    
    
    void integrar(float delta);
    
    //mejorar.
    glm::vec2 _posicion;
    glm::vec2 _velocidad;
    glm::vec2 _aceleracion;
};


#endif /* defined(__Game01__CSimpleFisica__) */
