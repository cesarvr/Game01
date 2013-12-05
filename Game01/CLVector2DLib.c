//
//  CLVector2DLib.c
//  Game01
//
//  Created by Cesar Luis Valdez on 03/12/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#include "CLVector2DLib.h"

void CLVector2Make(CLVector2 vec2, float x, float y){

    vec2[0] = x; vec2[1] = y;

}

/*
    SUMA
 */
void CLVector2Add(CLVector2 vector1, CLVector2 vector2){
  

    vector1[0] = vector1[0] + vector2[0];
    vector1[1] = vector1[1] + vector2[1];

    
}

/*
 SUMA
 */
void CLVector2AddResultado(CLVector2 resultado, CLVector2 vector1, CLVector2 vector2){
    
    
    resultado[0] = vector1[0] + vector2[0];
    resultado[1] = vector1[1] + vector2[1];
    
    
}


/*
    Normalizar.
 */

void CLVector2Normalizar(CLVector2 param1){
    
    float largo = CLVector2Tamano(param1);
    
    param1[0] = param1[0] / largo;
    param1[1] = param1[1] / largo;
    
}



/*
 Normalizar.
 */

void CLVector2NormalizarResultado(CLVector2 resultado, CLVector2 param1){
    
    float largo = CLVector2Tamano(param1);
    
    resultado[0] = param1[0] / largo;
    resultado[1] = param1[1] / largo;
    
}

/*
 Magnitud de vectores
 */

float CLVector2Tamano(CLVector2 vector){
    
   return sqrtf( (vector[0]*vector[0]) + (vector[1]*vector[1]) );
 
}



/*
    Multiplicacion
 */
void CLVector2Multiplicacion(CLVector2 vector1, CLVector2 vector2){
    
    
    vector1[0] = vector1[0] * vector2[0];
    vector1[1] = vector1[1] * vector2[1];
    
}


/*
 
 Dot Product <- no se decirlo en español.
 
*/

float CLVector2Dot(CLVector2 vector1, CLVector2 vector2){
    
    CLVector2 copy1, copy2;
    
    CLVector2Copy(copy1, vector1);
    CLVector2Copy(copy2, vector2);
    
    CLVector2Multiplicacion(copy1, copy2);
    
    return copy1[0]+copy1[1];
    
}

void CLVector2Copy(CLVector2 copy, CLVector2 vector1){
    copy[0] = vector1[0];
    copy[1] = vector1[1];

}


/*
 Resta de vectores
 */
void CLVector2Distancia(CLVector2 resultado, CLVector2 vector, CLVector2 addVector){
    
    
    resultado[0] = vector[0] + (-addVector[0]);
    resultado[1] = vector[1] + (-addVector[1]);
    //resultado[2] = vector[2] + (-addVector[2]);
    
}

/*
 Resta de vectores
 */
void CLVector2Sub(CLVector2 resultado, CLVector2 vector){
    
    
    resultado[0] = resultado[0] + (-vector[0]);
    resultado[1] = resultado[1] + (-vector[1]);
    resultado[2] = resultado[2] + (-vector[2]);
    
}


/*
 Multiplicacion de vectores por escalar
 */

void CLVector2MultiplicarEscalar(CLVector2 vector, float escalar){
    
  //  printf("x: %f y: %f\n", vector[0], vector[1]);
    
    vector[0] = vector[0] * escalar;
    vector[1] = vector[1] * escalar;
    
   

    
}


/*
    ESCALAR VEC2 + SUM VEC 1
 */
void CLVector2AddVectorEscalado(CLVector2 vector, CLVector2 vector2, float escalar){
  
    CLVector2 copy;
    copy[0] = vector2[0]; copy[1] = vector2[1];
    
    CLVector2MultiplicarEscalar(copy, escalar);
    CLVector2Add(vector, copy);
  
    
}






