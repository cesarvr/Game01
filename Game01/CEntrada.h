//
//  CEntrada.h
//  Game01
//
//  Created by Cesar Luis Valdez on 26/11/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#ifndef __Game01__CEntrada__
#define __Game01__CEntrada__

#include <iostream>

class CEntradaData {
    bool isMovingUp;
    bool isMovingDwn;
    bool isMovingLeft;
    bool isMovingRight;
    bool isFire;
    float _time;
    
    
public:
   
    void reset();
    void setMovimientoArriba(){isMovingUp = true;};
    void setMovimientoAbajo(){isMovingDwn =true; };
    void setMovimientoIzquierda(){isMovingLeft = true;};
    void setMovimientoDerecha(){isMovingRight = true;};
    void setFire(){isFire =true;};
    void setTime(float time){_time = time;};
    
    
    bool isKeyUp(){ return isMovingUp; };
    bool isKeyDown(){return isMovingDwn; };
    bool isKeyLeft(){return isMovingLeft; };
    bool isKeyRight(){return isMovingRight; };
    bool isKeyFire(){return isFire; }
    float getTime(){return _time;};
};


#endif /* defined(__Game01__CEntrada__) */
