//
//  CLFiguras.c
//  Game01
//
//  Created by Cesar Luis Valdez on 04/12/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#include "CLFiguras.h"


/* 
    LINEA
 
 */

Linea Linea_create(float x1, float y1, float x2, float y2){
    Linea linea;
    
    linea.min[0] = x1;
    linea.min[1] = y1;
    
    linea.max[0] = x2;
    linea.max[1] = y2;
    
    return linea;
}



/*
 
 CIRCLE
 
 */

Circle Circle_create(float x1, float y1, float tamano){
    
    Circle circle;
    
    circle.centro[0] = x1 + ( tamano/2 );
    circle.centro[1] = y1 + ( tamano/2 );
    circle.radio = ( tamano/2 );
    
    return circle;
    
}


void UpdateCirclePosicion(Circle *circle, CLVector2 posicion){

    circle->centro[0] = posicion[0] + circle->radio;
    circle->centro[1] = posicion[1] + circle->radio;

   // printf("\n circle x: %f y: %f  \n",circle->centro[0],circle->centro[1]);
    
}


/*
 
 AABB
 
 
 */

/*  Crear Objeto AABB */
AABB AABB_create(float x1, float y1, float x2, float y2){
    
    AABB temp;
    
    temp.min[0] = x1;
    temp.min[1] = y1;
    temp.max[0] = x2;
    temp.max[1] = y2;
    
    return temp;
}



/*  o AABB */
int TestAABBAABB(AABB a, AABB b){
    
    
    if (a.max[0] < b.min[0] || a.min[0] > b.max[0]) return 0;
    if (a.max[1] < b.min[1] || a.min[1] > b.max[1]) return 0;
    //3D  if (a.max[2] < b.min[2] || a.min[2] > b.max[2]) return 0;
    
    return 1;
}


void updateAABBWithPosicion(AABB *a, CLVector2 posicion){
    
    a->min[0] =  posicion[0];
    a->min[1] =  posicion[1];
    a->max[0] =  posicion[0]+3.0f;
    a->max[1] =  posicion[1]+3.0f;

    
}
