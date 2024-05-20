//
// Created by Kimberley on 5/14/2024.
//

#ifndef C_DATAFRAME_NDOUGA_RAKOTOARINIA_E_CDATAFRAME_H
#define C_DATAFRAME_NDOUGA_RAKOTOARINIA_E_CDATAFRAME_H

#include "liste.h"


CDATAFRAME *create_cdataframe(ENUM_TYPE *cdftype, int size);

void delete_cdataframe(CDATAFRAME **cdf);

void print_cdataframe(CDATAFRAME **cdf);

void delete_column_cdataframe(CDATAFRAME *cdf, char *col_name);

int get_cdataframe_cols_size(CDATAFRAME *cdf);

void rename_column_title(CDATAFRAME *cdf, char *old_title, char *new_title);

int value_in_cdataframe(CDATAFRAME *cdf, int value);

int count_cdataframe_rows(CDATAFRAME *cdf);

int count_cdataframe_col(CDATAFRAME *cdf);

int values_equal_cdataframe(CDATAFRAME *cdf, int x);

int values_superior_cdataframe(CDATAFRAME *cdf, int x);

int values_inferior_cdataframe(CDATAFRAME *cdf, int x);


#endif //C_DATAFRAME_NDOUGA_RAKOTOARINIA_E_CDATAFRAME_H
