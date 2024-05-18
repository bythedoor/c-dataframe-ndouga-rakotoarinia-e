
#ifndef C_DATAFRAME_NDOUGA_RAKOTOARINIA_E_COLUMN_H
#define C_DATAFRAME_NDOUGA_RAKOTOARINIA_E_COLUMN_H
#define REALOC_SIZE 256

typedef struct{
    char *title;
    int t_phys;
    int t_log;
    int* data[REALOC_SIZE];
}COLUMN;

COLUMN *create_column(char* title);
void free_column(COLUMN *col);

int insert_value(COLUMN* col, int value);

void print_col(COLUMN* col);

int nbr_occurences(COLUMN *col, int x);

int get_values(COLUMN *col, int x);

int values_superior(COLUMN *col, int x);

int values_inferior(COLUMN *col, int x);

int values_equal(COLUMN *col, int x);

void delete_column(COLUMN **col);

#endif //C_DATAFRAME_NDOUGA_RAKOTOARINIA_E_COLUMN_H
