//
//  CLVector2DLib.h
//  Game01
//
//  Created by Cesar Luis Valdez on 03/12/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#ifndef Game01_CLVector2DLib_h
#define Game01_CLVector2DLib_h

#include <stdio.h>
#include <math.h>

typedef float CLVector2[2];
#define CLV_INLINE	static __inline__




#ifdef __cplusplus
extern "C" {
    
    
    void  CLVector2Make(CLVector2 vec2, float x, float y);
    void  CLVector2Sub(CLVector2 resultado, CLVector2 vector);
    void  CLVector2Add(CLVector2 vector1, CLVector2 vector2);
    void  CLVector2AddVectorEscalado(CLVector2 vector, CLVector2 vector2, float escalar);
    void  CLVector2MultiplicarEscalar(CLVector2 vector, float escalar);
    void  CLVector2Distancia(CLVector2 resultado, CLVector2 vector, CLVector2 addVector);
    void  CLVector2Copy(CLVector2 copy, CLVector2 vector1);
    void  CLVector2Multiplicacion(CLVector2 vector1, CLVector2 vector2);
    void  CLVector2NormalizarResultado(CLVector2 resultado, CLVector2 param1);
    void  CLVector2Normalizar(CLVector2 param1);
    void  CLVector2Copy(CLVector2 copy, CLVector2 vector1);
    void CLVector2AddResultado(CLVector2 resultado, CLVector2 vector1, CLVector2 vector2);
    float CLVector2Tamano(CLVector2 vector);
    float CLVector2Dot(CLVector2 vector1, CLVector2 vector2);
    
}

#else


    void  CLVector2Make(CLVector2 vec2, float x, float y);
    void  CLVector2Sub(CLVector2 resultado, CLVector2 vector);
    void  CLVector2Add(CLVector2 vector1, CLVector2 vector2);
    void  CLVector2AddVectorEscalado(CLVector2 vector, CLVector2 vector2, float escalar);
    void  CLVector2MultiplicarEscalar(CLVector2 vector, float escalar);
    void  CLVector2Distancia(CLVector2 resultado, CLVector2 vector, CLVector2 addVector);
    void  CLVector2Copy(CLVector2 copy, CLVector2 vector1);
    void  CLVector2Multiplicacion(CLVector2 vector1, CLVector2 vector2);
    void  CLVector2NormalizarResultado(CLVector2 resultado, CLVector2 param1);
    void  CLVector2Normalizar(CLVector2 param1);
    void  CLVector2Copy(CLVector2 copy, CLVector2 vector1);
    void  CLVector2AddResultado(CLVector2 resultado, CLVector2 vector1, CLVector2 vector2);
    float CLVector2Tamano(CLVector2 vector);
    float CLVector2Dot(CLVector2 vector1, CLVector2 vector2);

#endif

#endif
