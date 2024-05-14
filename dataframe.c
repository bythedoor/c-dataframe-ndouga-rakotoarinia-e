//
// Created by Kimberley on 4/21/2024.
//

#include <stdio.h>
#include "dataframe.h"

DATAFRAME* create_dataframe(char title){
    printf("test");
}

//Il faut encore changer et harmonsier ces fonctions pour qu'elles fonctionnent avec le CDataFrame qu'on va créer
void printDataFrame(DATAFRAME *dtf) {
    for (int row = 0; row < dtf->columns[0].t_log; row++) {
        for (int col = 0; col < dtf->num_columns; col++) {
            printf("%s : %d\t", dtf->columns[col].title, *(dtf->columns[col].data[row]));
        }
        printf("\n");
    }

}

void limit_lig_DataFrame(DATAFRAME *dtf, int limit_lig) {
    for (int row = 0; row < limit_lig; row++) {
        for (int col = 0; col < dtf->num_columns; col++) {
            // Vérifier si la ligne est dans les limites de données disponibles pour cette colonne
            if (row < dtf->columns[col].t_log) {
                printf("%s : %d\t", dtf->columns[col].title, *(dtf->columns[col].data[row]));
            } else {
                printf("Pas de valeurs  ");
            }
        }
        printf("\n");
    }
}

void limit_col_DataFrame(DATAFRAME *dtf, int limit_col) {
    // Vérifier si le nombre de colonnes spécifié par l'utilisateur est valide
    if (limit_col <= 0 || limit_col > dtf->num_columns) {
        printf("Nombre de colonnes invalide\n");
        return;
    }
    for (int i = 0; i < dtf->columns[0].t_log; i++) {
        for (int j = 0; j < limit_col; j++) {
            printf("%s: %d\t", dtf->columns[j].title, *(dtf->columns[j].data[i]));
        }
        printf("\n");
    }
}

void print_nbr_lig(DATAFRAME *dtf) {
    for (int i = 0; i < dtf->num_columns; i++) {
        printf("Nombre de lignes de la colonne %s : %d\n", dtf->columns[i].title, dtf->columns[i].t_log);
    }
}

void print_nbr_col(DATAFRAME *dtf) {
    printf("Nombre de colonnes du DataFrame : %d\n", dtf->num_columns);
}

int cell_equal_df(DATAFRAME *dtf, int x) {
    int count = 0;
    for (int i = 0; i < dtf->num_columns; i++) {
        count += values_equal(&(dtf->columns[i]), x);
    }
    return count;
}

int cell_superior_df(DATAFRAME *dtf, int x) {
    int count = 0;
    for (int i = 0; i < dtf->num_columns; i++) {
        count += values_superior(&(dtf->columns[i]), x);
    }
    return count;
}

int cell_inferior_df(DATAFRAME *dtf, int x) {
    int count = 0;
    for (int i = 0; i < dtf->num_columns; i++) {
        count += values_inferior(&(dtf->columns[i]), x);
    }
    return count;
}
