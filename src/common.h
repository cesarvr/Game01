//
//  common.h
//  BlockGame
//
//  Created by Cesar Luis Valdez on 13/10/14.
//  Copyright (c) 2014 Cesar Luis Valdez. All rights reserved.
//

#ifndef BlockGame_common_h
#define BlockGame_common_h

#include <OpenGL/gl.h>
#include <iostream>
#include <assert.h>
#include "mathla.h"
#include "constants.h"


inline void GL_CHECK_ERROR()
{
    
    GLenum err = glGetError();
    while(err!=GL_NO_ERROR) {
        std::string error;
        
        switch(err) {
            case GL_INVALID_OPERATION:
                error = "INVALID_OPERATION";
                break;
            case GL_INVALID_ENUM:
                error= "INVALID_ENUM";
                break;
            case GL_INVALID_VALUE:
                error= "INVALID_VALUE";
                break;
            case GL_OUT_OF_MEMORY:
                error= "OUT_OF_MEMORY";
                break;
            case GL_INVALID_FRAMEBUFFER_OPERATION:
                error= "INVALID_FRAMEBUFFER_OPERATION";
                break;
        }
        if (err != GL_NO_ERROR) {
            printf("GL Error --> %s \n", error.c_str());
        }
       
        assert(err== GL_NO_ERROR);
        err=glGetError();
    }

    
    
}

#endif 