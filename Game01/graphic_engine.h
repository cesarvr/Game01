//
//  graphic_engine.h
//  OpenGLCurso
//
//  Created by Cesar Luis Valdez on 25/10/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#ifndef OpenGLCurso_graphic_engine_h
#define OpenGLCurso_graphic_engine_h

#include "glfw3.h"
#include <stdio.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {

  

    void cargarShaders(const char *vertex_fichero, const char *fragment_fichero);
    void cargar_fichero_maping(const char *nombre_fichero);
    GLuint getPrograma();
}
#endif
#endif
