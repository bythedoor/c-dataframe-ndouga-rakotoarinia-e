#include <stdio.h>
#include "column.h"
#include <stdlib.h>
#include "cdataframe.h"

int main() {
    /*
    // affichage du menu
    printf("*******Bienvenue sur le projet CDATAFRAME*******\n\n");
    printf("MENU\nAppuyez sur la touche 1 pour creer un dataframe : \n");


    // vérifie que 1 est bien entré
    int check;
    do {
        scanf("%d", &check);
    } while (check != 1);

    // création d'un dataframe vide
    //CDATAFRAME **cdf = create_cdataframe();

    // tests
    int nb_col, nb_row;
    printf("Combien de lignes et de colonnes souhaitez-vous dans votre colonne ? : ");
    scanf("%d %d", &nb_row, &nb_col);
    printf("\n");

    char title[100];
    int val;
    for (int i = 0; i < nb_col; i++) {
        //L'utilisateur choisit le titre de chaque colonne
        printf("Saisissez le titre de la colonne %d (99 caracteres maximum) :",i+1);
        scanf("%s", title);
        printf("\n");

        //Création d'une colonne avec le titre choisi
        COLUMN *mycol = create_column(title);

        //La boucle remplie chaque colonne avec les valeurs choisies par l'utilisateur
        for (int j = 0; j < nb_row; j++) {
            printf("Saisissez la valeur de la ligne %d (entiers uniquement) :", j+1);
            scanf("%d", &val);
            insert_value(mycol, val);
        }
        printf("\n");
    }
    */
    COLUMN *mycol = create_column("My column");
    insert_value(mycol, 52);
    insert_value(mycol, 44);
    insert_value(mycol, 15);
    print_col(mycol);

    return 0;
}
