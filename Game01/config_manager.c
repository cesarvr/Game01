//
//  config_manager.c
//  Game01
//
//  Created by Cesar Luis Valdez on 25/11/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//
#include "config_manager.h"



int _ancho = 0, _alto = 0;


void set_propiedad_imagen( int ancho, int alto ){

    _ancho = ancho;
    _alto = alto;


}


void get_mapping_by_name(const char *nombre,  TexturaUV_t *textCoord){

    
    
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    
    fp = fopen(PATH_CONFIG, "r");
    if (fp == NULL){
     
        printf("fichero de configuracion deberia estar en la carpeta config.");
        exit(EXIT_FAILURE);
    }
    while ((read = getline(&line, &len, fp)) != -1) {
      //  printf("Retrieved line of length %zu :\n", read);
      //  printf("%s", line);
        char tmp[50];
        
        sscanf (line,"%s %f %f %f %f",tmp, &textCoord->uvx1, &textCoord->uvy1, &textCoord->uvx2, &textCoord->uvy2);
        
        
        if (strcmp(tmp, nombre) == 0) {
        
            textCoord->uvx1 = textCoord->uvx1 / _ancho;
            textCoord->uvx2 = textCoord->uvx2 / _ancho;
            textCoord->uvy1 = textCoord->uvy1 / _alto;
            textCoord->uvy2 = textCoord->uvy2 / _alto;
            
            
            free(line);
            break;
        }
        
        
        
        
        
    }

    
    
}