//
//  config_manager.h
//  Game01
//
//  Created by Cesar Luis Valdez on 25/11/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#ifndef Game01_config_manager_h
#define Game01_config_manager_h

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "utilidades.h"
#include "Constantes.h"


typedef  struct TexturaUV_t_ {
    float uvx1, uvx2, uvy1, uvy2;
    
} TexturaUV_t;


#ifdef __cplusplus


extern "C" {
    


    void set_propiedad_imagen( int ancho, int alto );
    void get_mapping_by_name(const char *nombre,  TexturaUV_t *textCoord);

}
#endif


#endif
