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

#endif //C_DATAFRAME_NDOUGA_RAKOTOARINIA_E_DATAFRAME_H
