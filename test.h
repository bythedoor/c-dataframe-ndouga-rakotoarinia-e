//
// Created by Kimberley on 4/21/2024.
//

#ifndef C_DATAFRAME_NDOUGA_RAKOTOARINIA_E_TEST_H
#define C_DATAFRAME_NDOUGA_RAKOTOARINIA_E_TEST_H
#include "column.h"

typedef struct {
    char title;
    int t_phys;
    int t_log;
    COLUMN *data[REALOC_SIZE]
} DATAFRAME;

DATAFRAME* create_dataframe(char title);

int user_insert_value_dataframe(DATAFRAME *dtf);

int insert_value_dataframe(DATAFRAME *dtf, int value);

void add_line(DATAFRAME *dtf, COLUMN *column);

void delete_line(DATAFRAME *dtf, COLUMN *column);

void add_column(DATAFRAME *dtf, COLUMN *column);

void delete_column(DATAFRAME *dtf, COLUMN *column);

void rename_column(DATAFRAME *dtf, COLUMN *column);

int search_value(DATAFRAME *dtf, COLUMN *column, int x);

int replace_value(DATAFRAME *dtf, COLUMN *column, int l, int c);

void print_column_names(DATAFRAME *dtf, COLUMN *column);

#endif //C_DATAFRAME_NDOUGA_RAKOTOARINIA_E_TEST_H
