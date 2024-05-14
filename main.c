#include <stdio.h>
#include "column.h"
#include <stdlib.h>
#include "cdataframe.h"

int main() {
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
    printf("\nLe nombre %d se trouve a la position %d", get_values(mycol, position),position);

    //Pour le data frame
    // On ne peut pas encore créer le Dataframe puisque les fonctions qu'on va utiliser ne sont pas encore fini


    // Affichage du contenu du DataFrame
    printDataFrame(dtf);

    //Afficher une partie des lignes du CDataframe selon une limite fournie par l’utilisateur
    int limit_lig;
    printf("Vous voulez afficher jusqu'a quel ligne ?  ");
    scanf("%d",&limit_lig);
    limit_lig_DataFrame(dtf, limit_lig);

    //Afficher une partie des colonnes du CDataframe selon une limite fournie par l’utilisateur
    int limit_col;
    printf("Entrez le nombre de colonnes a afficher: ");
    scanf("%d", &limit_col);
    limit_col_DataFrame(dtf, limit_col);

    //print le nombre de lignes du dataframe
    print_nbr_lig(dtf);

    //print le nombre de colonnes du dataframe
    print_nbr_col(dtf);
    
    //permet de cherchr une valeur dans le dataframe
    int value_to_search;
    printf("Quel est la valeur que vous souhaitez rechercher dans le DataFrame? ");
    scanf("%d", &value_to_search);

    // Affichage du nombre de cellules contenant la valeur spécifiée par l'utilisateur
    printf("Il y a %d cellule(s) qui contient (contiennent) la valeur %d \n",cell_equal_df(dtf, value_to_search),value_to_search );
    printf("Il y a %d cellule(s) qui contient (contiennent) une(des) valeur(s) superieure(s) a %d \n",cell_superior_df(dtf, value_to_search),value_to_search );
    printf("Il y a %d cellule(s) qui contient (contiennent) une(des) valeur(s) inferieure(s) a %d \n",cell_inferior_df(dtf, value_to_search),value_to_search );
    return 0;
}
