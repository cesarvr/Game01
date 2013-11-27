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

    
public:
    
    CSimpleFisica();
    CSimpleFisica( float x1, float x2, float y1, float y2 );
    void setPosicion(  glm::vec2 posicion  ){   _posicion  = posicion; };
    void setVelocidad( glm::vec2 velocidad ){  _velocidad  = velocidad; };
    glm::vec2 getPosicion(){return _posicion;};
    glm::vec2 _posicion;
    glm::vec2 _velocidad;
};


#endif /* defined(__Game01__CSimpleFisica__) */
