#include <stdio.h>
#include <stdlib.h>
#include "column.h"
#include "string.h"

COLUMN *create_column(ENUM_TYPE type, char* title) {
    COLUMN *col = (COLUMN *)malloc(sizeof(COLUMN)); // Alloue de la mémoire pour la colonne
    if (col == NULL) {
        return NULL;
    }

    // Alloue de la mémoire pour le titre et copie la chaîne de caractères
    col->title = (char *)malloc(strlen(title) + 1); // +1 pour le caractère nul de fin de chaîne
    if (col->title == NULL) {
        free(col);
        return NULL;
    }
    strcpy(col->title, title);

    //Intialisation des tailles physique et logique
    col->max_size = REALOC_SIZE;
    col->size = 0;

    //Alloue de la mémoire pour les pointeurs des valeurs du tableau
    col->data = (COL_TYPE **)malloc(REALOC_SIZE * sizeof(COL_TYPE *));

    //Initialisation du type de données de la colonne
    col->column_type = type;

    //Initialise tous les pointeurs de données à NULL
    for (int i = 0; i < REALOC_SIZE; ++i) {
        col->data[i] = NULL;
    }
    return col;
}

int insert_value(COLUMN *col, void *value) {
    // insertion dans un tableau vide
    if (*col->data == NULL) {
        col->data = (COL_TYPE **)malloc(REALOC_SIZE * sizeof(COL_TYPE *));
        if (col->data == NULL) {
            return 1;
        }
        col->max_size = REALOC_SIZE;
    }

    // insertion dans un tableau rempli au maximum
    if (col->size >= col->max_size) {
        col->max_size =+ REALOC_SIZE;
        col->data =(COL_TYPE **) realloc(col->data, col->max_size * sizeof(COL_TYPE **));
        if (col->data == NULL) {
            return 1;
        }
    }

    COL_TYPE a;
    // insertion de la valeur en fonction du type
    switch(col->column_type){
        case NULLVAL:
            col->data[col->size] = "NULL";
            break;
        case UINT:
            col->data[col->size] = (a*)malloc(sizeof(a));
            *((unsigned int*)col->data[col->size])= *((unsigned int*)value);
            break;
        case INT:
            col->data[col->size] = (int*)malloc(sizeof(int));
            *((int*)col->data[col->size])= *((int*)value);
            break;
        case CHAR:
            col->data[col->size] = (char *)malloc(sizeof(char));
            *((char*)col->data[col->size])= *((char*)value);
            break;
        case FLOAT:
            col->data[col->size] = (char *)malloc(sizeof(char));
            *((char*)col->data[col->size])= *((char*)value);
            break;
        case DOUBLE:
            col->data[col->size] = (char *)malloc(sizeof(char));
            *((char*)col->data[col->size])= *((char*)value);
            break;
        case STRING:
            col->data[col->size] = (char *)malloc(sizeof(char));
            *((char*)col->data[col->size])= *((char*)value);
            break;
        case STRUCTURE:
            col->data[col->size] = (char *)malloc(sizeof(char));
            *((char*)col->data[col->size])= *((char*)value);
            break;
    }
    if (col->data[col->size] == NULL) {
        return 0;
    }
    col->size++;

    return 0;
}

void delete_column(COLUMN **col) {
    free((*col)->title); //suppression du titre de la mémoire
    free((*col)->data);
    free((*col)->index);
    free(*col); //suppression du tableau de pointeur
    *col = NULL; //réintialisation du pointeur de la colonne à NULL
}

void convert_value(COLUMN *col, unsigned long long int i, char *str, int size){
    if(i >= col->size){
        printf("error : out of bound");
    }
    switch(col->column_type){
        case INT:
            snprintf(str, size, "%d", *((int *)(col->data[i])));
            break;
        case UINT:
            snprintf(str, size, "%u", *((unsigned int *)col->data[i]));
            break;
        case CHAR:
            if(col->data[i] == NULL){
                snprintf(str, size, "NULL");
            }
            else {
                snprintf(str, size, "%c", *((char *) col->data[i]));
            }
            break;
        case FLOAT:
            snprintf(str, size, "%f", *((float *)col->data[i]));
            break;
        case DOUBLE:
            snprintf(str, size, "%lf", *((double *)col->data[i]));
            break;
        case STRING:
            if(col->data[i] == NULL){
                snprintf(str, size, "NULL");
            }
            else{
                strncpy(str, (char *)col->data[i], size-1);
                str[size-1] = '\0';
            }
            break;
        default:
            printf("error display type");
    }
}

void print_col(COLUMN* col){
    if(col == NULL){
        printf("Error pointer null");
        return;
    }
    for(int i = 0; i < col->size; i++){
        if (col->data[i] == NULL) {
            printf("[%d] NULL\n", i);
        }
        else{
            char str[256];
            convert_value(col, i, str, sizeof(str));
            printf("[%d] %s\n", i, str);}
    }
}

int nbr_occurences(COLUMN *col, int x) {
    int count = 0;
    for (int i = 0; i < col->size; ++i) {
        if (*(col->data[i]) == x) {
            count++;
        }
    }
    return count;
}

int get_values(COLUMN *col, int x) {
    if (x < 0 || x >= col->size){
        printf("Cette valeur n'existe pas");
    }
    return *col->data[x];
}

int values_superior(COLUMN *col, int x) {
    int count = 0;
    for (int i = 0; i < col->size; ++i) {
        if (*(col->data[i]) > x) {
            count++;
        }
    }
    return count;
}

int values_inferior(COLUMN *col, int x) {
    int count = 0;
    for (int i = 0; i < col->size; ++i) {
        if (*(col->data[i]) < x) {
            count++;
        }
    }
    return count;
}

int values_equal(COLUMN *col, int x) {
    int count = 0;
    for (int i = 0; i < col->size; ++i) {
        if (*(col->data[i]) == x) {
            count++;
        }
    }
    return count;
}
