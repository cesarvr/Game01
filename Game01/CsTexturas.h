//
//  CsTexturas.h
//  Game01
//
//  Created by Cesar Luis Valdez on 25/11/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#ifndef __Game01__CsTexturas__
#define __Game01__CsTexturas__

#include <iostream>
#include "ShaderManager.h"
#include "lodepng.h"
#include "Constantes.h"




class CsTexturas {
    GLuint texturaId;
    unsigned width, height;
    
public:
    void cargarTexturas();
    
    int getWidth() {  return width; };
    int getHeight(){  return height; };
    
    
    
};



#endif /* defined(__Game01__CsTexturas__) */
