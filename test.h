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

void printDataFrame(DATAFRAME *dtf);

void limit_lig_DataFrame(DATAFRAME *dtf, int limit_lig);

void limit_col_DataFrame(DATAFRAME *dtf, int limit_col);

void print_nbr_lig(DATAFRAME *dtf);

void print_nbr_col(DATAFRAME *dtf);

int cell_equal_df(DATAFRAME *dtf, int x);

int cell_superior_df(DATAFRAME *dtf, int x);

int cell_inferior_df(DATAFRAME *dtf, int x);

#endif //C_DATAFRAME_NDOUGA_RAKOTOARINIA_E_TEST_H
