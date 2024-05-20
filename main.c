#include <stdio.h>
#include "column.h"
#include <stdlib.h>
#include "cdataframe.h"

int main() {
        char titre[100];
        int x;

        //pour les colonnes
        printf("Entrez le titre de la colonne: ");
        gets(titre);
        COLUMN *mycol = create_column(titre);
        //tableau en dure
        insert_value(mycol, 52);
        insert_value(mycol, 44);
        insert_value(mycol, 15);
        print_col(mycol);
        printf("Quel est le nombre que vous voulez comparer?");
        scanf("%d",&x);
        printf("Le nombre d'occurence de %d est %d.",x,nbr_occurences(mycol, x));
        printf("\nIl y a %d nombre(s) superieure(s) a %d.",x,values_superior(mycol, x));
        printf("\nIl y a %d nombre(s) inferieure(s) a %d.",x, values_inferior(mycol, x));
        printf("\nIl y a %d nombre(s) egale(s) a %d.",x, values_equal(mycol, x));

        int position;
        printf("\nQuel est la position de la valeur que vous voulez connaitre?");
        scanf("%d",&position);
        printf("\nLe nombre %d se trouve a la position %d", get_values(mycol, position),position);


        //pour un cdataframe
        ENUM_TYPE cdftype[] = {INT, CHAR};
        CDATAFRAME *cdf = create_cdataframe(cdftype, 2);
        LNODE *col_node = get_next_node(cdf, cdf->head); // Accéder à la deuxième colonne
        if (col_node != NULL) {
            COLUMN *col = col_node->data; // Récupérer la colonne à partir du nœud
            insert_value(col, 10); // Insérer des valeurs dans la colonne
            insert_value(col, 20);
            insert_value(col, 30);
        }

            // Vérification si le dataframe a été créé avec succès
            if (cdf != NULL) {
                printf("Dataframe cree avec succes.\n");

                // Affichage du dataframe
                printf("Contenu du dataframe :\n");
                print_cdataframe(&cdf);
            }

        int cols_size = get_cdataframe_cols_size(cdf);
        printf("Nombre de colonnes dans le CDATAFRAME : %d\n", cols_size);

        char col_name[] = "hello";
        delete_column_cdataframe(cdf, col_name);

        int ligne = count_cdataframe_rows(cdf);
        printf("nbr de lignes:",ligne);

        int value = 20;
        if (value_in_cdataframe(cdf, value)) {
            printf("La valeur %d existe dans le dataframe.\n", value);
        } else {
            printf("La valeur %d n'existe pas dans le dataframe.\n", value);
        }
        printf("Nombre de colonnes dans le CDATAFRAME : %d\n", cols_size);


        char old_title[] = "hello";
        char new_title[] = "bonjour";
        rename_column_title(cdf, old_title, new_title);
        return 0;
        }
