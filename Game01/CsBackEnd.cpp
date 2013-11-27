//
//  CsBackEnd.cpp
//  Game01
//
//  Created by Cesar Luis Valdez on 26/11/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#include "CsBackEnd.h"

CBackend::CBackend(){};
CBackend::CBackend( Shader *shader, CsTexturas *texturas, CEntradaData *entrada,  glm::mat4 *camara ){

    _shader = shader;
    _texturas = texturas;
    _camara = camara;
    _entrada = entrada;

};