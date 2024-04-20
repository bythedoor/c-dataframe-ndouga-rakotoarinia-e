# Projet CDataframe

## Contributeurs
Jennifer RAKOTOARINIA \
Kimberley NDOUGA
## Instructions
Lorsque l'utilisateur lance le programme, il peut créer une colonne 
en utilisant la fonction create_column(). Cette fonction prend en paramètre le titre que l'utlisateur
choisit en ammont. Une fois la colonne créée, il peut la remplir d'entiers à l'aide de 
la fonction insert_value(), puis l'afficher avec print_column(). 

L'utilisateur peut désormais appeler plusieurs fonctions pour comparer les valeurs de la colonne 
avec une valeur qu'il aura choisit :
* nbr_occurences() : calcule le nombre d'occurences d'un nombre dans une colonne donnée
* get_value() : renvoie la valeur à la position donnée en entrée
* values_superior(), values_inferior(), values_equal() : renvoie le nombre de valeurs supérieures, inférieures ou égales à un nombre

## Lien vers Github
https://github.com/bythedoor/c-dataframe-ndouga-rakotoarinia-e

## Bugs
* Les fonctions pour créer un CDataframe sont encore en construction
* Les colonnes ne peuvent qu'accepter que des entiers comme valeur