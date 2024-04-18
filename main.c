#include <stdio.h>
#include "column.h"


int main() {
    COLUMN *mycol = create_column("My column");
    insert_value(mycol, 52);
    insert_value(mycol, 44);
    insert_value(mycol, 15);
    print_col(mycol);
    printf("Le nombre de chiffres superieur a 40 est %d", values_equal(mycol,15) );
    return 0;
}
