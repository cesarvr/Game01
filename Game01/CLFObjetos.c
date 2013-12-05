//
//  CLFObjetos.c
//  Game01
//
//  Created by Cesar Luis Valdez on 03/12/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#include "CLFObjetos.h"

/* objeto_fisico->setCoeficienteRestitucion(0.5f);
 objeto_fisico->setIndice(contador++);
 objeto_fisico->setInamovible(false);
 
 CE Coefieciente de restitucion.
 
 */
void setCLFObjetosPropiedades(CLFObjetos *objeto, short indice, float masa, float CE ){

    objeto->indice = indice;
    
    if (masa == 0.0f) objeto->masa = 0.0f;
    else objeto->masa = 1/masa;
    
    objeto->coeficiente_restitucion = CE;
    
    //inicializar vectores
    
    objeto->velocidad[0] = 0.0f;
    objeto->velocidad[1] = 0.0f;
    
    objeto->aceleracion[0] = 0.0f;
    objeto->aceleracion[1] = 0.0f;
    
    objeto->test = 0;
    
};



void setCLFObjetosPosicion(CLFObjetos *objeto, float x, float y){
    objeto->posicion[0] = x; objeto->posicion[1] = y;

}

void CLFObjetosUpdateVelocidad(CLFObjetos *objeto, CLVector2 aceleracion, float dt){

   if (objeto->masa != 0) {
    
    CLVector2AddVectorEscalado(objeto->velocidad, aceleracion, dt);
  
   }
    
}
void CLFObjetosUpdatePosicion(CLFObjetos *objeto, float dt){

    if (objeto->masa != 0) {
    
        CLVector2AddVectorEscalado(objeto->posicion, objeto->velocidad, dt);
        
        
        if (objeto->tipo == CUADRADO) {
            updateAABBWithPosicion(&objeto->shape, objeto->posicion);
        }else if (objeto->tipo == CIRCULO)
            UpdateCirclePosicion(&objeto->circle, objeto->posicion);
        

        
        
        // printf("objeto->shape x: %f y: %f", objeto->shape.min[0], objeto->shape.min[1]);
        // printf(" x2: %f y2: %f \n", objeto->shape.max[0], objeto->shape.max[1]);
        
    }
}



