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

    _y = suelo;
    _gravedad = glm::vec2(0, -10.0f);
    contador = 0;
}


CSimpleFisica  *CSimpleIntegrator::crearFisicaObjeto(float x1, float y1, float x2, float y2){

    CSimpleFisica *objeto_fisico = new CSimpleFisica(x1,y1,x2,y2);
    objeto_fisico->setPosicion(glm::vec2(x1,y1));
    objeto_fisico->setMass(4.0f);
    objeto_fisico->setRadio(3.0f/2);
    objeto_fisico->setCoeficienteRestitucion(0.4f);
    objeto_fisico->setIndice(contador++);
    objeto_fisico->setInamovible(false);
    objetos_colision.push_back(objeto_fisico);
    
    time  = 0.0f;
    
    
    return objeto_fisico;
}

void CSimpleIntegrator::ResolverColision(CSimpleFisica *objeto_uno, CSimpleFisica *objeto_dos){

  

    

}



 float timeIncr = 0.05f;
void CSimpleIntegrator::integrar(float delta){
    
    if (delta <0.33f) {
        
       
        time += timeIncr;
        
        
        for(CSimpleFisica *_fisik : objetos_colision)
        {
            
            _fisik->_aceleracion = 0.05f * _gravedad  * delta   ;
            
            for(CSimpleFisica *_collition : objetos_colision){
                
                
                
                if ( _collition->getIndice() != _fisik->getIndice() ) {
                    
                    bool isContacto = _fisik->estaColisionando( _collition );
                    
                    
                    /*
                        Si hay contacto entonces calcular los resultados de estos.
                    
                     
                     */
                
                    if (isContacto) {
                        
                        float tmp = 0.03f; //1.0f / (_fisik->getMass() - _collition->getMass());
                        float e_fisik = _fisik->getCoeficienteRestitucion();
                        
                        /*
                         vx′ = m1−em2v
                         
                         */
                        
                        float nueva_vel_fisik = ( _fisik->getMass() - ( e_fisik *_collition->getMass() ) )* _fisik->_velocidad.y *tmp;
                        
                        
                        
                        /*
                         (1+e)m2v 1x m+m1x m+m2x
                         */
                        nueva_vel_fisik += (1.0f + e_fisik)*_collition->getMass()*_collition->_velocidad.y*tmp;
                        
                        
                        float nueva_vel_collition = (1.0f + e_fisik)* _fisik->getMass() * _fisik->_velocidad.y *tmp;
                        
                        nueva_vel_collition+= ( _collition->getMass() - ( ( e_fisik *_fisik->getMass() ) )) * _collition->_velocidad.y * tmp;
                        
                        
                        if ( nueva_vel_fisik >0 ) {
                            printf("\n stop :) \n");
                        }
                        _fisik->_velocidad.y = nueva_vel_fisik * 15.0f; //* delta;
                        _collition->_velocidad.y = nueva_vel_fisik; // * delta;
                    
                    
                    
                }
                
             
                if ( _fisik->_posicion.y+3.4f < _y) {
                    
                    
                   
                       _fisik->_posicion +=  _fisik->_velocidad;
                    _fisik->_posicion -= _fisik->_aceleracion;
                    
                    
                    
                }
                
        }
                
                
                
                
                
            }
            
            
            
            
            
        }
        
    
    
    }
}