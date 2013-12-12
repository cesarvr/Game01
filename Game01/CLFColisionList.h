//
//  CLFColisionList.h
//  Game01
//
//  Created by Cesar Luis Valdez on 05/12/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#ifndef Game01_CLFColisionList_h
#define Game01_CLFColisionList_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CLFDataType.h"


typedef struct _contactos_lista{

    CLFContactoData contacto_data;
    int tipo_colision;
    struct _contactos_lista *next;

}contactos_lista;


void CLFListAdd(CLFContactoData *contact_data, int tipo_colision);
contactos_lista * CLFListGet();
void CLFListClear(contactos_lista *cabeza_lista);
int  CLFListBuscarByID(int id_colision1, int id_colision2);
void CLFListLiberarMemoria();



#endif
