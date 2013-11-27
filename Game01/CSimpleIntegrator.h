//
//  CSimpleIntegrator.h
//  Game01
//
//  Created by Cesar Luis Valdez on 26/11/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#ifndef __Game01__CSimpleIntegrator__
#define __Game01__CSimpleIntegrator__

#include <iostream>
#include <vector>
#include "CSimpleFisica.h"



class CSimpleIntegrator {

private:
    std::vector <CSimpleFisica *> objetos_colision;
    float _y;
    glm::vec2 _gravedad;
    
public:
    
    CSimpleIntegrator();
    CSimpleIntegrator(float suelo);
    CSimpleFisica * crearFisicaObjeto(float x1, float y1, float x2, float y2);
    void integrar(float delta);
    
    
};


#endif /* defined(__Game01__CSimpleIntegrator__) */
