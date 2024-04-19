#include <stdio.h>
#include "column.h"


int main() {
    COLUMN *mycol = create_column("My column");
    insert_value(mycol, 52);
    insert_value(mycol, 44);
    insert_value(mycol, 15);
    print_col(mycol);
    printf("Quel le nombre d'occurence de 44? %d", nbr_occurences(mycol,44));
    printf("\nQuel est le nombre a la position 1? %d", get_values(mycol,1));
    printf("\nIl y a %d nombre(s) superieur(s) a 40.", values_superior(mycol,40) );
    printf("\nIl y a %d nombre(s) inferieur(s) a 40.", values_inferior(mycol,40) );
    printf("\nIl y a %d nombre(s) egale(s) a 40.", values_equal(mycol,40) );
    return 0;
}
