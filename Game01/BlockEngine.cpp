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
    
    int cantidad_bloques_ancho = TABLE_ANCHO / BLOQUE_ANCHO;
    int cantidad_bloques_alto = TABLE_ALTO / BLOQUE_ALTO;
    
    
    bool primero = false;
    /*
     for (int x = 0; x < cantidad_bloques_ancho; x++) {
     for (int y = 0; y < cantidad_bloques_alto; y++) {
     
     
     for (int x = 0; x < 5; x++) {
     for (int y = 0; y < 5; y++) {
     
     
     */
    
    
    for (int x = 0; x < 2; x++) {
        for (int y = 0; y < 5; y++) {

            
    
        CBloque _bloque = CBloque( backend );
            
        glm::vec2 posicion = glm::vec2(TBL_ESPACIADOX +TABLE_POSX+x*BLOQUE_ANCHO, TBL_ESPACIADOY+TABLE_POSY+y*BLOQUE_ALTO);
            
        _bloque.setPosicion(posicion);
            
        CSimpleFisica *fisico = integrador.crearFisicaObjeto(posicion.x, posicion.y, BLOQUE_ANCHO, BLOQUE_ALTO);
        _bloque.setFisica(fisico);
        _bloque.prepararDibujo();

        listado_bloque.push_back(_bloque);
    
            if (!primero) {
                primero = true;
                _cursor.setPosicion(_bloque.getPosicion());
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
  
    for (CBloque &_bloque : listado_bloque) {
        _bloque.draw();
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
    
    _background.update();

    for (CBloque &_bloque : listado_bloque) {
        _bloque.update();
    }
    
        _cursor.update();
    
    
    integrador.integrar(_entrada->getTime());
}
