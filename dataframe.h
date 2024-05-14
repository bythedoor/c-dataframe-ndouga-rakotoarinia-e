//
// Created by Kimberley on 4/21/2024.
//

#ifndef C_DATAFRAME_NDOUGA_RAKOTOARINIA_E_DATAFRAME_H
#define C_DATAFRAME_NDOUGA_RAKOTOARINIA_E_DATAFRAME_H
#include "column.h"

typedef struct {
    char title;
    int t_phys;
    int t_log;
    COLUMN column;
} DATAFRAME;

DATAFRAME* create_dataframe(char title);

int insert_value_dataframe(DATAFRAME *dtf, int value);

void printDataFrame(DATAFRAME *dtf);

void limit_lig_DataFrame(DATAFRAME *dtf, int limit_lig);

void limit_col_DataFrame(DATAFRAME *dtf, int limit_col);

void print_nbr_lig(DATAFRAME *dtf);

void print_nbr_col(DATAFRAME *dtf);

int cell_equal_df(DATAFRAME *dtf, int x);

int cell_superior_df(DATAFRAME *dtf, int x);

int cell_inferior_df(DATAFRAME *dtf, int x);


#endif //C_DATAFRAME_NDOUGA_RAKOTOARINIA_E_DATAFRAME_H
