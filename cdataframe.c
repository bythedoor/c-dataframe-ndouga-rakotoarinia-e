//
// Created by Kimberley on 5/14/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include "column.h"
#include "cdataframe.h"

CDATAFRAME *create_cdataframe(ENUM_TYPE *cdftype, int size) {
    //création du dataframe sous forme d'une liste chaînée
    LIST* list = lst_create_list();

    //création tête et queue du dataframe
    LNODE* head = lst_create_lnode(cdftype);
    LNODE* tail = lst_create_lnode(cdftype);

    //intégration de la tête et de la queue dans la liste chaînée
    list->head = head;
    list->tail = tail;

    //création d'une liste chaînée de taille size
    LNODE* temp = head;
    for (int i = 0; i < size; ++i) {
        LNODE* new = lst_create_lnode(cdftype);
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->prev = temp;
        temp->next = new;
    }
}

