//
//  CLFiguras.h
//  Game01
//
//  Created by Cesar Luis Valdez on 04/12/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#ifndef Game01_CLFiguras_h
#define Game01_CLFiguras_h



#include <stdio.h>
#include "CLVector2DLib.h"
#include "CLFDataType.h"





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


#ifdef __cplusplus
extern "C" {
    
    /*
     
     LINEA
     
     */
    
    Linea Linea_create(float x1, float y1, float x2, float y2);
    
    /*
     
        AABB 
     
     
     */
    
    AABB AABB_create(float x1, float y1, float x2, float y2);
    int TestAABBAABB(AABB a, AABB b);
    void updateAABBWithPosicion(AABB *a, CLVector2 posicion);
    
    
    /*
     
        CIRCLE
     
     
     */
    
    
    Circle Circle_create(float x1, float y1, float tamano);
    void UpdateCirclePosicion(Circle *circle, CLVector2 posicion);
    
    
    
}
#else




/* 
    
    LINEA
 
 */

Linea Linea_create(float x1, float y1, float x2, float y2);






/*
 
 AABB
 
 
 */

AABB AABB_create(float x1, float y1, float x2, float y2);
int TestAABBAABB(AABB a, AABB b);
void updateAABBWithPosicion(AABB *a, CLVector2 posicion);


/*
 
 CIRCLE
 
 
 */


Circle Circle_create(float x1, float y1, float tamano);
void UpdateCirclePosicion(Circle *circle, CLVector2 posicion);

#endif


#endif
