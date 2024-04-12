//
// Created by Kimberley on 3/31/2024.
//

#include <stdlib.h>
#include "column.h"
/*
COLUMN *create_column(char* title)
{
    COLUMN c = {*title, 256, 0, {}};
    COLUMN* c_ptr = NULL;
    return c_ptr;
}
*/

COLUMN *create_column(char* title) {
    COLUMN *c_ptr = (COLUMN *)malloc(sizeof(COLUMN)); //permet d'allouer de la mémoire pour la colonne
    if (c_ptr == NULL) {
        return NULL;
    }
    //affecte les différents paramètres de la colonne
    c_ptr->title = *title;
    c_ptr->t_phys = REALOC_SIZE;
    c_ptr->t_log = 0;

    //initialise tous les pointeurs de données à NULL
    for (int i = 0; i < REALOC_SIZE; ++i) {
        c_ptr->data[i] = NULL;
    }

    return c_ptr;
}

