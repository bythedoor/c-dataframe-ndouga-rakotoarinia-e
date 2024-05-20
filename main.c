#include <stdio.h>
#include "column.h"
#include <stdlib.h>
#include "cdataframe.h"

int main() {
    char titre[100];
    int valeur;

    printf("Entrez le titre de la colonne: ");
    gets(titre); //permet de récupérer le titre avec les espace compris

    COLUMN *mycol = create_column(titre);

    /*
    if (mycol != NULL) {
        printf("Column title: %s\n", mycol->title);
        printf("Entrez les valeurs a inserer (-1 pour terminer la saisie) :\n");
        while (1) {
            printf("Valeur: ");
            scanf("%d", &valeur);
            if (valeur == -1) {
                break;
            }
            insert_value(mycol, valeur);
        }
        printf("Colonne : %s\n", mycol->title);
        for (int i = 0; i < mycol->t_log; ++i) {
            printf("[%d] %d\n", i, *mycol->data[i]);
        }

        free_column(mycol);
    }
    */

    ENUM_TYPE cdftype[] = {INT, CHAR};
    CDATAFRAME *cdf = create_cdataframe(cdftype, 2);



   /*int x;
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
*/
    //Pour le cdataframe
}
