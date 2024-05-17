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
    list->head = head;
    list->tail = tail;

    //création d'une liste chaînée de taille size
    LNODE* temp = head;
    for (int i = 0; i < size; ++i) {
        LNODE *new = lst_create_lnode(cdftype);
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->prev = temp;
        temp->next = new;
    }
}

void delete_column2(CDATAFRAME *cdf, char *col_name) {
    // Déclaration d'un pointeur vers le nœud actuel pour parcourir la liste chaînée
    LNODE *current = cdf->head;

    // Parcours de la liste chaînée
    while (current != NULL) {
        // Vérification si le nom de la colonne correspond
        // (Assumez que le nom de la colonne est stocké dans un champ "nom" de la structure ENUM_TYPE)
        if (strcmp(col_name, current->data->nom) == 0) {
            // Si le nom de la colonne correspond, nous avons trouvé la colonne à supprimer

            // Récupération des nœuds précédent et suivant pour le nœud actuel
            LNODE *prev_node = current->prev;
            LNODE *next_node = current->next;

            // Mise à jour des pointeurs des nœuds voisins pour "sauter" le nœud actuel
            if (prev_node != NULL) {
                prev_node->next = next_node;
            } else {
                // Si le nœud actuel est la tête de la liste, mettez à jour la tête
                cdf->head = next_node;
            }

            if (next_node != NULL) {
                next_node->prev = prev_node;
            } else {
                // Si le nœud actuel est la queue de la liste, mettez à jour la queue
                cdf->tail = prev_node;
            }

            // Libération de la mémoire occupée par le nœud actuel
            free(current);

            // Sortie de la fonction après la suppression
            return;
        }

        // Passage au nœud suivant dans la liste chaînée
        current = current->next;
    }
}
