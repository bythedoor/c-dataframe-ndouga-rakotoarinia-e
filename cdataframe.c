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
            printf("%d", temp->data[1]);
        }
        for (int i = 0; i < 2; i++)
            print_col("%d \n", (*cdf)->data);

    }
}

void print_cdataframe_rows(CDATAFRAME **cdf, int* start, int* end) {
    if (*cdf == NULL) {
        printf("La liste est vide");
        return;
    }
    else {
        LNODE *pos_node = (*cdf)->head;
        while (pos_node->next != NULL) {
            pos_node->data[0] = 1;
            pos_node = get_next_node(*cdf, pos_node);
        }
    }
}

void print_cdataframe_col(CDATAFRAME **cdf, int* start, int* end) {
    if (*cdf == NULL) {
        printf("Le dataframe est vide.\n");
        return;
    }
    else {
        LNODE *temp = (*cdf)->head;
        while (temp->next != NULL) {
            print_col(temp->data);
            temp = get_next_node(*cdf, temp);
        }
    }
}

void add_row(CDATAFRAME **cdf, int* values[], int pos) {
    if (*cdf == NULL) {
        printf("test");
        return;
    }
    else {
        LNODE *pos_node = (*cdf)->head;
        while (pos_node->next != NULL) {
            pos_node->data[pos] = *values[pos];
            pos_node = get_next_node(*cdf, pos_node);
        }
    }
}

void delete_row(CDATAFRAME **cdf, int pos) {
    if (*cdf == NULL) {
        printf("test");
    }
    else {
        LNODE *pos_node = (*cdf)->head;
        for (int i=0; i < pos; i++) {
            pos_node = get_next_node( *cdf, pos_node);
        }
        lst_delete_lnode(*cdf, pos_node);
    }
}

void add_col(CDATAFRAME** cdf, void *values, int pos) {
    if (*cdf == NULL) {
        printf("test");
    }
    else {
        // création d'un nouveau node
        LNODE *new = lst_create_lnode(values);

        // on itialise la position d'insertion à la tête de la liste
        LNODE *pos_node = (*cdf)->head;
        //on parcourt la liste jusqu'à la position (pos) indiquée
        for (int i=0; i < pos; i++) {
            pos_node = get_next_node( *cdf, pos_node);
        }
        // on insert la colonne dans le tableau
        lst_insert_after(*cdf, new,pos_node);
        printf("test");
    }
}

//fonction pour supprimer une colonne dans le dataframe
//prend en paramètre le cdataframe et le titre de la colonne qu'on souhaite supprimer
void delete_column_cdataframe(CDATAFRAME *cdf, char *col_name) {
    // Vérifier si la liste est vide
    if (cdf->head == NULL || cdf->head->next == NULL) {
        printf("Le dataframe est vide ou ne contient qu'une seule colonne.\n");
        return;
    }

    // Supprimer la première colonne si elle correspond au titre donné
    COLUMN *first_col = cdf->head->next->data;
    if (strcmp(first_col->title, col_name) == 0) {
        LNODE *first_col_node = cdf->head->next;
        delete_column(first_col);
        lst_delete_lnode(cdf, first_col_node);
        printf("La colonne '%s' a ete supprimee avec succes.\n", col_name);
        return;
    }

    // Dans le cas où on supprime pas la première colonne
    //On trouve le nœud de la colonne à supprimer
    LNODE *prev_node = cdf->head;
    LNODE *current_node = prev_node->next;
    while (current_node != NULL) {
        COLUMN *mycol = current_node->data;
        if (strcmp(mycol->title, col_name) == 0) {
            // Supprimer la colonne associée à ce nœud
            delete_column(mycol);

            // Supprimer le nœud de la liste chaînée
            lst_delete_lnode(cdf, current_node);

            // Si la colonne supprimée est la dernière colonne, on metà jour la queue
            if (current_node->next == NULL) {
                cdf->tail = prev_node;
            }

            printf("La colonne '%s' a été supprimée avec succès.\n", col_name);
            return;
        }
        prev_node = current_node;
        current_node = current_node->next;
    }

    // Si la colonne n'a pas été trouvée
    printf("La colonne '%s' n'a pas été trouvée dans le dataframe.\n", col_name);}


//fonction pour avoir le nombre de colonnes dans la cdataframe
int count_cdataframe_col(CDATAFRAME *cdf) {
    if (cdf == NULL || cdf->head == NULL) {
        return 0;
    }

    int count = 0;
    LNODE *current_node = cdf->head;

    while (current_node != NULL) {
        count++;
        current_node = current_node->next;
    }

    // Soustrait 2 pour exclure la tête et la queue de la liste chaînée
    return count - 2;
}

//fonction pour renomer le titre d'une colonne dans le cdataframe
void rename_column_title(CDATAFRAME *cdf, char *old_title, char *new_title) {
    LNODE *temp = cdf->head;  // Début de la liste

    // Parcourt tous les nœuds de la liste
    while (temp != NULL) {
        COLUMN *col = (COLUMN *)temp->data;

        // Compare le titre de la colonne avec l'ancien titre
        if (strcmp(col->title, old_title) == 0) {
            // Alloue de la mémoire pour le nouveau titre
            col->title = (char *)malloc(strlen(new_title) + 1);
            if (col->title == NULL) {
                printf("Erreur lors de l'allocation de mémoire pour le nouveau titre.\n");
                return;
            }

            // Copie le nouveau titre dans l'espace alloué
            strcpy(col->title, new_title);

            printf("Le titre de la colonne a été renommé avec succès.\n");
            return;
        }

        temp = temp->next;  // Passer au nœud suivant dans la liste
    }

    // Si on arrive ici, cela signifie que la colonne avec l'ancien titre n'a pas été trouvée
    printf("La colonne avec l'ancien titre n'a pas été trouvée.\n");
}

//cherche une valeur dans de cdataframe
//prends en paramètre le cdt et la valeur qu'on cherche
int value_in_cdataframe(CDATAFRAME *cdf, int value) {
    if (cdf == NULL || cdf->head == NULL) {
        return 0;
    }

    LNODE *col_node = cdf->head;
    while (col_node != NULL) {
        COLUMN *col = (COLUMN *)col_node->data;
        if (nbr_occurences(col, value) > 0) { //appelle la fonction qu'on a déjà utiliser pour les colonnes
            return 1;
        }
        col_node = col_node->next;
    }
    return 0;
}

//conte le nombre de ligne dans le cdataframe
int count_cdataframe_rows(CDATAFRAME *cdf) {
    if (cdf == NULL || cdf->head == NULL) {
        return 0;
    }

    int row_count = 0;
    LNODE *col_node = cdf->head;
    COLUMN *first_col = col_node->data;

    // Nombre de lignes est égal à la taille de la première colonne
    row_count = first_col->t_log;

    return row_count;
}


int count_cdataframe_col(CDATAFRAME *cdf) {
    int count = 0;
    LNODE *current_node = cdf->head;

    // Parcours de la liste chaînée de colonnes
    while (current_node != NULL) {
        count++;
        current_node = current_node->next;
    }

    return count;}


//fonction qui affiche le nombre de valeurs égale à x
//prends en paramètre le cdt et la valeur x qu'on donne
int values_equal_cdataframe(CDATAFRAME *cdf, int x) {
    int count = 0;
    LNODE *col_node = cdf->head;

    // Parcours la liste chaînée de colonnes
    while (col_node != NULL) {
        COLUMN *col = (COLUMN *)col_node->data;
        if (col != NULL) {
            count += values_equal(col, x); // Appel de la fonction values_equal pour chaque colonne
        }
        col_node = col_node->next;
    }

    return count;
}

//fonction qui affiche le nombre de valeurs supérieur à x
//prends en paramètre le cdt et la valeur x qu'on donne
int values_superior_cdataframe(CDATAFRAME *cdf, int x) {

    int count = 0;
    LNODE *col_node = cdf->head;

    // Parcours de la liste chaînée de colonnes
    while (col_node != NULL) {
        COLUMN *col = (COLUMN *)col_node->data;
        if (col != NULL) {
            count += values_superior(col, x); // Appel de la fonction values_superior pour chaque colonne
        }
        col_node = col_node->next;
    }

    return count;
}

//fonction qui affiche le nombre de valeurs inférieur à x
//prends en paramètre le cdt et la valeur x qu'on donne
int values_inferior_cdataframe(CDATAFRAME *cdf, int x) {

    int count = 0;
    LNODE *col_node = cdf->head;

    // Parcours de la liste chaînée de colonnes
    while (col_node != NULL) {
        COLUMN *col = (COLUMN *)col_node->data;
        if (col != NULL) {
            count += values_inferior(col, x); // Appel de la fonction values_superior pour chaque colonne
        }
        col_node = col_node->next;
    }

    return count;
}
