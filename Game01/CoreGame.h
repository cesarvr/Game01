//
//  CoreGame.h
//  EngineOne
//
//  Created by Cesar Luis Valdez on 12/11/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#ifndef __EngineOne__CoreGame__
#define __EngineOne__CoreGame__

#include <iostream>
#include "ShaderManager.h"
#include "BlockEngine.h"
#include "Constantes.h"
#include "CsTexturas.h"


#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

using namespace std;

class CoreGame {
private:
    Shader shaderManager;
    glm::mat4 camara;
    BlockEngine blocker;
    CsTexturas texturas;
    CEntradaData *_entrada;
    
    
public:
    
    CoreGame();
    CoreGame( CEntradaData *entrada );
    void draw();
    void update();
    void finish();
    
    
    
};


#endif /* defined(__EngineOne__CoreGame__) */
