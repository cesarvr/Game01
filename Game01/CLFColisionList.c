//
//  CLFColisionList.c
//  Game01
//
//  Created by Cesar Luis Valdez on 05/12/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#include "CLFColisionList.h"



contactos_lista *head;
contactos_lista *tail;


void CLFListAdd(CLFContactoData *contact_data, int tipo_colision){


    contactos_lista *current = (contactos_lista *)malloc(sizeof(contactos_lista));
    //current->contacto_data = contact_data;
    current->contacto_data = *contact_data;
    current->tipo_colision = tipo_colision;
    
    if (head == NULL) {
        head = current;
    }else{
        tail->next = current;
    }
    
    tail = current;
    tail->next = NULL;
    
    
    printf("\n save:     col1 [ %d ]  ---   col2 [ %d ] \n", contact_data->colision1->indice,  contact_data->colision2->indice);
    
}


int CLFListBuscarByID(int id_colision1, int id_colision2){

    contactos_lista *current = head;

    int c = 0;
    //printf("\n search:     col1 [ %d ]  ---   col2 [ %d ] \n", id_colision1, id_colision2);
    
    while (current != NULL) {
  
      //  printf("\n search field:  %d ", c++);
        if (( current->contacto_data.colision1->indice == id_colision1 &&
              current->contacto_data.colision2->indice == id_colision2 ) ||
          
            ( current->contacto_data.colision1->indice == id_colision2 &&
              current->contacto_data.colision2->indice == id_colision1 )
            
            ) {
            
            return 1;
        }
        
        current = current->next;

        
    }
    
    return 0;
}

contactos_lista * CLFListGet(){

    return head;
    
}

void CLFListClear(contactos_lista *cabeza_lista){
    contactos_lista *current;
    
    
    while (cabeza_lista != NULL) {
        current = cabeza_lista;
        cabeza_lista = cabeza_lista->next;
        free(current);
        current = 0;
        
    }


}

void CLFListLiberarMemoria(){

    contactos_lista *current;
    
    
    while (head != NULL) {
        current = head;
        head = head->next;
        free(current);
        current = 0;
        
    }
    
    //free(tail);
    
    printf("lista memoria: %lu", sizeof(head) + sizeof(tail));
    
}



