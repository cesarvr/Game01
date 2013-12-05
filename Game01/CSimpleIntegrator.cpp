//
//  CSimpleIntegrator.cpp
//  Game01
//
//  Created by Cesar Luis Valdez on 26/11/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#include "CSimpleIntegrator.h"

CSimpleIntegrator::CSimpleIntegrator(){};

CSimpleIntegrator::CSimpleIntegrator(float suelo){


    
     CLVector2Make(_gravedad, 0.0f, 9.0f);
    
    
    
    /*
        Definiendo el suelo.
     */
    
    
    CLFObjetos *objeto = (CLFObjetos *) malloc(sizeof(CLFObjetos));
    objeto->shape = AABB_create(0.0f, suelo-1.0f,  50.0f, suelo+15 );
    objeto->circle  = Circle_create(5.0f, suelo, 35.0f);
    
    objeto->linea = Linea_create(0.0f, suelo-2.5f, 40.0f, suelo-2.5f);
    objeto->tipo    = LINEA;
    setCLFObjetosPropiedades(objeto, 6666, 0.0f, 0.0f);
    setCLFObjetosPosicion(objeto, 0.0f, suelo-0.5f);
    
    objetos_col.push_back(objeto);
    

}


CLFObjetos  *CSimpleIntegrator::crearFisicaObjeto(float x1, float y1, float x2, float y2){

    
    dt  = 1.0f/float(70.0f);
    
    
    CLFObjetos *objeto = (CLFObjetos *) malloc(sizeof(CLFObjetos));
    objeto->circle = Circle_create(x1, y1, 3.0f);
    
    objeto->tipo = CIRCULO;
    setCLFObjetosPropiedades(objeto, contador++, 2.0f, 0.5f);
    setCLFObjetosPosicion(objeto, x1,y1);
    
    objetos_col.push_back(objeto);
    
    
    
    return objeto;
}


void CSimpleIntegrator::integrar(float delta){
    
    
    std::vector <CLFContactoData> list_contact;
    
    // Detectar colisiones.
    for (CLFObjetos *obj_fisico: objetos_col) {
        
        
        for (CLFObjetos *objeto_colision: objetos_col) {
            
            if (obj_fisico->indice != objeto_colision->indice) {
                
                
                CLFContactoData contact_data;
                contact_data.colision1 = obj_fisico;
                contact_data.colision2 = objeto_colision;

                
                int resultado = CLFColisionDetector(&contact_data);
                if ( resultado == COLISION_AABB_CIRCULO && objeto_colision->indice == 6666) {
                    
                    obj_fisico->test = 1;
          
          
                }
                if ( resultado == COLISION_LINEA_CIRCULO && objeto_colision->indice == 6666) {
                    
                    CLFColisionApplyLinearImpulse(&contact_data);
                    contact_data.colision1->test = true;
           
                }
                if (resultado == COLISION_CIRCULO_CIRCULO) {
                    
                    CircleToCircleResolver(&contact_data);
                    CLFColisionApplyLinearImpulse(&contact_data);
               
                    
                }
                
                
                
                
                
                
            }
            
        }


            CLFObjetosUpdateVelocidad(obj_fisico, _gravedad, dt);
            CLFObjetosUpdatePosicion(obj_fisico, dt);
        
        
       
        
        
    }


}

void CSimpleIntegrator::limpiarMemoria(){
    
    printf("\n liberando recursos. \n");
    
    for(CLFObjetos *objetos : objetos_col){
        
        free(objetos);
        objetos = 0;
        
    }

}


CSimpleIntegrator::~CSimpleIntegrator(){

  


}
