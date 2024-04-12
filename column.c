//
// Created by Kimberley on 3/31/2024.
//

#include <stdlib.h>
#include "column.h"
#include <stdio.h>

/*COLUMN *create_column(char* title)
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
int insert_value(COLUMN *col, int value) {
    if (*col->data == NULL) {
        *col->data = (int *) malloc(REALOC_SIZE * sizeof(int *));
        if (col->data == NULL) {
            return 0;
        }
        col->t_phys = REALOC_SIZE;
    }

    if (col->t_log >= col->t_phys) {
        int nouvelle_taille = col->t_phys + REALOC_SIZE;
        int **nouveau_tableau =(int **)realloc(col->data, nouvelle_taille * sizeof(int *));
        if (nouveau_tableau == NULL) {
            return 0;
        }
        *col->data = nouveau_tableau;
        col->t_phys = nouvelle_taille;
    }
    col->data[col->t_log] = (int *)malloc(sizeof(int)); // Alloue de la mémoire pour la valeur
    if (col->data[col->t_log] == NULL) {
        return 0;
    }

    *col->data[col->t_log] = value;
    col->t_log++;

    return 1;
}

void print_col(COLUMN* col) {
    if (col == NULL) {
        printf("Column is NULL\n");
            return;
        }

    for (int i = 0; i < col->t_log; ++i) {
        printf("[%d] %d\n", i, *(col->data[i]));
    }
}
