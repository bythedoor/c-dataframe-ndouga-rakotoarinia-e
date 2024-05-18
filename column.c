#include <stdio.h>
#include <stdlib.h>
#include "column.h"
#include "string.h"
#define REALOC_SIZE 256
/*
COLUMN *create_column(char* title)
{
    COLUMN c = {*title, 256, 0, {}};
    COLUMN* c_ptr = NULL;
    return c_ptr;
}
*/

COLUMN *create_column(char* title) {
    COLUMN *c_ptr = (COLUMN *)malloc(sizeof(COLUMN)); // Alloue de la mémoire pour la colonne
    if (c_ptr == NULL) {
        return NULL;
    }

    // Alloue de la mémoire pour le titre et copie la chaîne de caractères
    c_ptr->title = (char *)malloc(strlen(title) + 1); // +1 pour le caractère nul de fin de chaîne
    if (c_ptr->title == NULL) {
        free(c_ptr);
        return NULL;
    }
    strcpy(c_ptr->title, title);

    c_ptr->t_phys = REALOC_SIZE;
    c_ptr->t_log = 0;

    // Initialise tous les pointeurs de données à NULL
    for (int i = 0; i < REALOC_SIZE; ++i) {
        c_ptr->data[i] = NULL;
    }

    return c_ptr;
}
int insert_value(COLUMN *col, int value) {
    if (*col->data == NULL) {
        *col->data = (int**)malloc(REALOC_SIZE * sizeof(int **));
        if (col->data == NULL) {
            return 0;
        }
        col->t_phys = REALOC_SIZE;
    }
    if (col->t_log >= col->t_phys) {
        int nouvelle_taille = col->t_phys + REALOC_SIZE;
        int **nouveau_tableau =(int **) realloc(col->data, nouvelle_taille * sizeof(int *));
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
void free_column(COLUMN *col) {
    if (col == NULL) {
        return;
    }
    // Libère la mémoire allouée pour le titre
    free(col->title);
    // Libère la mémoire allouée pour chaque valeur
    for (int i = 0; i < col->t_log; ++i) {
        free(col->data[i]);
    }
    // Libère la mémoire allouée pour la structure COLUMN
    free(col);
}
void print_col(COLUMN* col) {
    if (col == NULL) {
        printf("Column is NULL\n");
        return;
    }
    else {
        printf("%s \n", col->title);
        for (int i = 0; i < (*col).t_log; ++i) {
            printf("[%d] %d\n", i, *col->data[i]);
        }
    }
}

int nbr_occurences(COLUMN *col, int x) {
    int count = 0;
    for (int i = 0; i < col->t_log; ++i) {
        if (*(col->data[i]) == x) {
            count++;
        }
    }
    return count;
}


int get_values(COLUMN *col, int x) {
    if (x < 0 || x >= col->t_log){
        printf("Cette valeur n'existe pas");
    }
    return *col->data[x];
}

int values_superior(COLUMN *col, int x) {
    int count = 0;
    for (int i = 0; i < col->t_log; ++i) {
        if (*(col->data[i]) > x) {
            count++;
        }
    }
    return count;
}

int values_inferior(COLUMN *col, int x) {
    int count = 0;
    for (int i = 0; i < col->t_log; ++i) {
        if (*(col->data[i]) < x) {
            count++;
        }
    }
    return count;
}

int values_equal(COLUMN *col, int x) {
    int count = 0;
    for (int i = 0; i < col->t_log; ++i) {
        if (*(col->data[i]) == x) {
            count++;
        }
    }
    return count;
}

void delete_column(COLUMN **col) {
    free(*col);
    *col = NULL;
}