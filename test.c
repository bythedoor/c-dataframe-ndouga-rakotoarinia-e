//
// Created by Kimberley on 4/21/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include "test.h"

DATAFRAME* create_dataframe(char title){
    DATAFRAME *dtf = (DATAFRAME *) malloc(sizeof(DATAFRAME));

    dtf->title = title;
    dtf->t_phys = REALOC_SIZE;
    dtf->t_log = 0;

    for (int i = 0; i < REALOC_SIZE; ++i) {
        dtf->data[i] = NULL;
    }

    return dtf;

}

int user_insert_value_dataframe(DATAFRAME *dtf) {
    printf("Combien de colonnes souhaitez-vous ? ");
    scanf("%d", dtf->t_log);
    COLUMN *col;
    char title;

    for (int i=0; i < dtf->t_log; i++) {

        if (dtf->data[i] ==  NULL) {
            printf("Choissisez un titre pour la colonne : ");
            scanf("%s", title);
            *col = create_column(title);
        }

        printf("Combien de lignes souhaitez-vous ? ");
        scanf("%d", *col);


    }
}