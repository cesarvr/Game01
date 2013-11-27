//
//  BackGround.h
//  Game01
//
//  Created by Cesar Luis Valdez on 25/11/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#ifndef __Game01__BackGround__
#define __Game01__BackGround__

#include <iostream>
#include "BlockTest.h"

#define TABLE_ANCHO 25.0f
#define TABLE_ALTO 35.0f
#define TABLE_POSX 10.0f
#define TABLE_POSY 2.0f
#define TBL_ESPACIADOX 0.5f
#define TBL_ESPACIADOY 0.5f

class CBackGround {
    

    
    
private:
    BlockTest dibujador;
    CBackend *back;
    
public:
    CBackGround( );
    CBackGround( CBackend *backend );
    void prepararDibujo();
    void draw();
    void update();
};




#endif /* defined(__Game01__BackGround__) */
