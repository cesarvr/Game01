//
//  CoreGame.cpp
//  EngineOne
//
//  Created by Cesar Luis Valdez on 12/11/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#include "CoreGame.h"


/*
    inicializador.
 */

CoreGame::CoreGame(){}

CoreGame::CoreGame( CEntradaData *entrada ){

    glClearColor(0.1f, 0.2f, 0.0f, 1.0f);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    
    shaderManager.cargarFicheroShader(PATH_VERTEX, PATH_FRAGMENT);
    
    camara = glm::ortho(0.0f, 50.0f, 40.0f, 0.0f, 1.0f, -1.0f);
   
    texturas.cargarTexturas();
    
    CBackend backend = CBackend(&shaderManager, &texturas,entrada, &camara);
    
    blocker = BlockEngine( &backend );
    blocker.generar_nivel();
};





void CoreGame::draw(){
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    blocker.draw();
    
}

void CoreGame::update(){
    blocker.update();

}





