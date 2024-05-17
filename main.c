#include <stdio.h>
#include "column.h"
#include <stdlib.h>
#include "cdataframe.h"

int main() {
    /*
    //Pour les colonnes
    COLUMN *mycol = create_column("My column");
    insert_value(mycol, 52);
    insert_value(mycol, 44);
    insert_value(mycol, 15);
    print_col(mycol);

    int x;
    printf("Quel est le nombre que vous voulez comparer?");
    scanf("%d",&x);
    printf("Le nombre d'occurence de %d est %d.",x,nbr_occurences(mycol, x));
    printf("\nIl y a %d nombre(s) superieure(s) a %d.",x,values_superior(mycol, x));
    printf("\nIl y a %d nombre(s) inferieure(s) a %d.",x, values_inferior(mycol, x));
    printf("\nIl y a %d nombre(s) egale(s) a %d.",x, values_equal(mycol, x));

    int position;
    printf("\nQuel est la position de la valeur que vous voulez connaitre?");
    scanf("%d",&position);
    printf("\nLe nombre %d se trouve a la position %d", get_values(mycol, position),position);*/

    //Pour le cdataframe
    ENUM_TYPE cdftype [] = {INT,CHAR,INT};
    CDATAFRAME *cdf = create_cdataframe(cdftype,3);
    return 0;

}
