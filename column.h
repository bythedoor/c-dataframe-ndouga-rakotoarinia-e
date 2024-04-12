//
// Created by Kimberley on 3/28/2024.
//

#ifndef C_DATAFRAME_NDOUGA_RAKOTOARINIA_E_COLUMN_H
#define C_DATAFRAME_NDOUGA_RAKOTOARINIA_E_COLUMN_H
#define REALOC_SIZE 256

typedef struct{
    char title;
    int t_phys;
    int t_log;
    int* data[REALOC_SIZE];
}COLUMN;

COLUMN *create_column(char* title);

int insert_value(COLUMN* col, int value);

void print_col(COLUMN* col);
#endif //C_DATAFRAME_NDOUGA_RAKOTOARINIA_E_COLUMN_H
