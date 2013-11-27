//
//  ShaderManager.h
//  EngineOne
//
//  Created by Cesar Luis Valdez on 12/11/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#ifndef __EngineOne__ShaderManager__
#define __EngineOne__ShaderManager__

#include <iostream>
#include "graphic_engine.h"
#include <assert.h>

class Shader {
    
    
public:
    
    void cargarFicheroShader( const char * vertexShader, const char * fragmentShader );
    void activarPrograma();
    void deactivarPrograma();
   
    
    GLuint getUniforme( const char *nombre );
    GLuint getParametro( const char *nombre );
    
};


#endif /* defined(__EngineOne__ShaderManager__) */
