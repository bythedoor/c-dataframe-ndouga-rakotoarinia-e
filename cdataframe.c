//
// Created by Kimberley on 5/14/2024.
//
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "column.h"
#include "cdataframe.h"
#define bool true 1 false 0

CDATAFRAME *create_cdataframe(ENUM_TYPE *cdftype, int size) {
    //création du dataframe sous forme d'une liste chaînée
    LIST* list = lst_create_list();

    //création tête et queue du dataframe
    LNODE* head = lst_create_lnode(cdftype);
    LNODE* tail = lst_create_lnode(cdftype);

    //intégration de la tête et de la queue dans la liste chaînée
    lst_insert_head(list, head);
    lst_insert_tail(list, tail);

    //création d'une liste chaînée de taille size
    LNODE* temp = head;
    for (int i = 0; i < size; ++i) {
        LNODE* lnew = lst_create_lnode(cdftype);
        lst_insert_after(list, lnew, lnew->prev);
    }
    return list;
}


void delete_cdataframe(CDATAFRAME **cdf) {
    // création variable temporaire
    LNODE *temp = (*cdf)->head;

    while (temp->next != NULL) {
        //suppression de la colonne dans le node
        delete_column(temp->data);

        //suppression du node
        *temp = *temp->next;
        lst_delete_lnode(*cdf, (*cdf)->head);

    }
    lst_erase(*cdf);
}


void print_cdataframe(CDATAFRAME **cdf) {
    if (*cdf == NULL) {
        printf("Le dataframe est vide.\n");
        return;
    } else {
        LNODE *temp = (*cdf)->head;
        while (temp->next != NULL) {
            print_col(temp->data);
        }
    }
}