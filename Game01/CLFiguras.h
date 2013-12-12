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
