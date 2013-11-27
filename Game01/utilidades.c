//
//  utilidades.c
//  Game01
//
//  Created by Cesar Luis Valdez on 25/11/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#include <stdio.h>
#include "utilidades.h"

/*
 ====================
 Lector de ficheros
 ====================
 */



void leerFichero(const char *nombreFichero,const char **buffer){
    
    FILE *fp;
    long lSize;
    
    fp = fopen ( nombreFichero , "rb" );
    if( !fp ){
        
        printf("error al abrir fichero");
    }
    
    
    
    fseek( fp , 0L , SEEK_END);
    lSize = ftell( fp );
    rewind( fp );
    
    /* allocate memory for entire content */
    *buffer = calloc( sizeof(char), lSize+1 );
    if( !buffer ) printf("no hay memoria");
    
    /* copy the file into the buffer */
    if( 1!=fread( *buffer , lSize, 1 , fp) )
        fclose(fp),free(*buffer),fputs("entire read fails",stderr),exit(1);
    
    fclose(fp);
}
