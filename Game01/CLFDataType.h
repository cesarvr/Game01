//
//  CLFDataType.h
//  Game01
//
//  Created by Cesar Luis Valdez on 04/12/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#ifndef Game01_CLFDataType_h
#define Game01_CLFDataType_h

#include "CLVector2DLib.h"


typedef float Punto_t[2];






/*
 
 AABB
 
 
 */


struct AABB_t{
    
    Punto_t min;
    Punto_t max;
    
};

typedef struct AABB_t AABB;



/*
 
 CIRCLE
 
 */

struct Circle_t {
    
    CLVector2   centro;
    float       radio;
    
};


typedef struct Circle_t Circle;


/*
 LINEA
 
 */


struct Linea_t {
    CLVector2 min;
    CLVector2 max;
    
};

typedef struct Linea_t Linea;

enum CLFSHAPE {
    CUADRADO = 1,
    CIRCULO = 2,
    LINEA = 3
};



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



enum colision_tipo {
    COLISION_CIRCULO_CIRCULO = 1,
    COLISION_AABB_CIRCULO = 2,
    COLISION_LINEA_CIRCULO = 3,
    NO_COLISION = 0
};

struct CLFContactoData_t
{
    
    CLFObjetos *colision1;
    CLFObjetos *colision2;
    CLVector2  normal;
    
    int estado_contacto;
    float penetracion;
    
    
};
typedef struct CLFContactoData_t CLFContactoData;

#endif
