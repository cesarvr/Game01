//
//  BlockEngine.h
//  Game01
//
//  Created by Cesar Luis Valdez on 25/11/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#ifndef __Game01__BlockEngine__
#define __Game01__BlockEngine__

#include <iostream>
#include "BackGround.h"
#include "CsBackEnd.h"
#include "Bloques.h"
#include "CCursor.h"
#include <vector>
#include "CEntrada.h"



class BlockEngine {
    
    CBackGround _background;
    CsCursor _cursor;
    std::vector <CBloque> listado_bloque;
    CEntradaData *_entrada;
    CSimpleIntegrator integrador;
    
public:
    
    BlockEngine();
    BlockEngine( CBackend *backend );
    void generar_nivel();
    
    void draw();
    void update();
    
    
    
};

#endif /* defined(__Game01__BlockEngine__) */
