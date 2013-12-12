//
//  BlockEngine.cpp
//  Game01
//
//  Created by Cesar Luis Valdez on 25/11/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#include "BlockEngine.h"



BlockEngine::BlockEngine( ){};

BlockEngine::BlockEngine( CBackend *backend ){

    _background = CBackGround( backend );
    _cursor     = CsCursor( backend );
    _entrada = backend->getEntradaData();
    integrador = CSimpleIntegrator(TABLE_ALTO+TABLE_POSY);
    animar_interpolacion = false;
    
    
    
    
    int cantidad_bloques_ancho = TABLE_ANCHO / BLOQUE_ANCHO;
    int cantidad_bloques_alto = TABLE_ALTO / BLOQUE_ALTO;
    
    
    bool primero = false;
    /*
     for (int x = 0; x < cantidad_bloques_ancho; x++) {
     for (int y = 0; y < cantidad_bloques_alto; y++) {
     
     
     
     
     
     for (int x = 0; x < 1; x++) {
     for (int y = 0; y < 3; y++) {
     
     
     
     */
    
    
    glm::vec2 BOUND_ONE, BOUND_TWO ;
    bool primero_bound = false;
    

    for (int x = 0; x < 1; x++) {
        for (int y = 0; y < 1; y++) {
            
            
            
            
    
        CBloque _bloque = CBloque( backend );
            
        glm::vec2 posicion = glm::vec2(TBL_ESPACIADOX +TABLE_POSX+x*BLOQUE_ANCHO, TBL_ESPACIADOY+TABLE_POSY+y*BLOQUE_ALTO);
            
        _bloque.setPosicion(posicion);
            
        CLFObjetos *fisico = integrador.crearFisicaObjeto(posicion.x, posicion.y, BLOQUE_ANCHO, BLOQUE_ALTO);
            
            
            if (!primero_bound) {
                primero_bound = true;
                BOUND_ONE = posicion;
            }
            
        _bloque.setFisica(fisico);
        _bloque.prepararDibujo();

        listado_bloque.push_back(_bloque);
    
            if (!primero) {
                primero = true;
                _cursor.setPosicion(_bloque.getPosicion());
            }
            
            
            if (x == cantidad_bloques_ancho-1 && y == cantidad_bloques_alto-1) {
                BOUND_TWO = posicion;
            }
            
        }
    }

   
    
    _cursor.setLimite1(BOUND_ONE);
    _cursor.setLimite2(BOUND_TWO);
    
    
    
}


void BlockEngine::swapBloques(){

    if (animar_interpolacion) {
        
        
        
      /*
        printf("\n id-> %s \n", swp_bloq[0].getColor().c_str());
        printf("\n id-> %s \n", swp_bloq[1].getColor().c_str());
        */
        
        for (int x = 0 ; x < swp_bloq.size(); x++) {
            
            if(swp_bloq[x].getPosicion().x !=  swp_bloq[x].getGoPosicion().x){
                
                if (swp_bloq[x].getPosicion().x < swp_bloq[x].getGoPosicion().x) {
                    swp_bloq[x].mover(0.5f);
                }else
                    swp_bloq[x].mover(-0.5f);
                
            }
            
            
            if (swp_bloq[0].getPosicion().x == swp_bloq[0].getGoPosicion().x
                && swp_bloq[1].getPosicion().x == swp_bloq[1].getGoPosicion().x) {
                
                
                
                animar_interpolacion = false;
                swp_bloq.clear();
                
                
                
            }
            
            
        }
        
    
    }
    
        
 
    
    
        
        
    
   
    
    
    


}



void BlockEngine::generar_nivel(){

    
    _background.prepararDibujo();
    _cursor.prepararDibujo();
 

}


void BlockEngine::draw(){


    _background.draw();
  
    for (int z= 0; z < listado_bloque.size(); z++){
        listado_bloque[z].draw();
    }
    
      _cursor.draw();

}

void BlockEngine::update(){
    
    
    
    if (_entrada->isKeyLeft()) {
        _cursor.goIzquierda();
        _entrada->reset();
    }
    
    if (_entrada->isKeyRight()) {
  
        _cursor.goDerecha();
        _entrada->reset();
    }
    
    
    if (_entrada->isKeyUp()) {
        
        _cursor.goArriba();
        _entrada->reset();
    }

    
    if (_entrada->isKeyDown()) {
        
        _cursor.goAbajo();
        _entrada->reset();
    }
    
    if (_entrada->isKeyFire()) {
        //swp_bloq = _cursor.pickDosBloques(listado_bloque);
       _cursor.pickDosBloques(listado_bloque, swp_bloq);
        if (swp_bloq.size() >0) {
            animar_interpolacion = true;
        }
        _entrada->reset();
        
    }
    
    swapBloques();
    
    _background.update();

    for (int z= 0; z < listado_bloque.size(); z++){
        listado_bloque[z].update();
    }
    
        _cursor.update();
    
    
    integrador.integrar(_entrada->getTime());
}



void BlockEngine::finish(){

  
    integrador.limpiarMemoria();



};