//
//  CsBackEnd.h
//  Game01
//
//  Created by Cesar Luis Valdez on 26/11/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#ifndef __Game01__CsBackEnd__
#define __Game01__CsBackEnd__

#include <iostream>
#include "CsTexturas.h"
#include "ShaderManager.h"
#include "CEntrada.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

class CBackend {
private:
    Shader *_shader;
    CsTexturas *_texturas;
    CEntradaData *_entrada;
    glm::mat4 *_camara;
    
    
public:
    
    CBackend();
    CBackend( Shader *shader, CsTexturas *texturas, CEntradaData *entrada,  glm::mat4 *camara );
    Shader* getShader(){ return _shader; };
    CsTexturas* getTexturas(){ return _texturas; };
    glm::mat4* getCamara(){ return _camara; };
    CEntradaData* getEntradaData(){return _entrada;};
};


#endif /* defined(__Game01__CsBackEnd__) */
