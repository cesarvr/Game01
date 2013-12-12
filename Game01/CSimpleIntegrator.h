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
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "gtc/random.hpp"
#include "CLFObjetos.h"
#include "CLFiguras.h"
#include "CLFColision.h"

class CSimpleIntegrator {

private:

    std::vector <CLFObjetos *> objetos_col;
    float _y;
    CLVector2 _gravedad;
    short contador;
    float dt;

    void Resolver(std::vector<struct CSContactos> contactos);

    
    
public:
    
    CSimpleIntegrator();
    CSimpleIntegrator(float suelo);
    ~CSimpleIntegrator();
   // CSimpleFisica * crearFisicaObjeto(float x1, float y1, float x2, float y2);
    CLFObjetos * crearFisicaObjeto(float x1, float y1, float x2, float y2);
    void integrar(float delta);
    void limpiarMemoria();
    
    
    
    
};


#endif /* defined(__Game01__CSimpleIntegrator__) */
