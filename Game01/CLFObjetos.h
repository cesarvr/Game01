//
//  CLFObjetos.h
//  Game01
//
//  Created by Cesar Luis Valdez on 03/12/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#ifndef Game01_CLFObjetos_h
#define Game01_CLFObjetos_h

#include "CLVector2DLib.h"
#include "CLFiguras.h"
#include "CLFDataType.h"



struct CLFObjetos_t{
    
    AABB   shape;
    Circle circle;
    Linea  linea;
    CLVector2   posicion;
    CLVector2   velocidad;
    CLVector2   aceleracion;
    float inverse_mass;
    short indice;
    float masa;
    float coeficiente_restitucion;
    int test;
    enum CLFSHAPE tipo;
};


typedef struct CLFObjetos_t CLFObjetos;


#ifdef __cplusplus
extern "C" {
    
    void setCLFObjetosPropiedades(CLFObjetos *objeto, short indice, float masa, float CE );
    void setCLFObjetosPosicion(CLFObjetos *objeto, float x, float y);
    void CLFObjetosUpdateVelocidad(CLFObjetos *objeto, CLVector2 aceleracion, float dt);
    void CLFObjetosUpdatePosicion(CLFObjetos *objeto, float dt);
}
#endif

#endif
