//
// Created by Kimberley on 3/31/2024.
//

#include <stdlib.h>
#include "column.h"

COLUMN *create_column(char* title)
{
    COLUMN c = {*title, 256, 0, {}};
    COLUMN* c_ptr = NULL;
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

    col->data[col->t_log] = &value;
    col->t_log++;

    return 1;
}