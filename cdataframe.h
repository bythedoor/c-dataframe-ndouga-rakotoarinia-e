//
// Created by Kimberley on 5/14/2024.
//

#ifndef C_DATAFRAME_NDOUGA_RAKOTOARINIA_E_CDATAFRAME_H
#define C_DATAFRAME_NDOUGA_RAKOTOARINIA_E_CDATAFRAME_H

#include "liste.h"


CDATAFRAME *create_cdataframe(ENUM_TYPE *cdftype, int size);

void delete_column2(CDATAFRAME *cdf, char *col_name);

#endif //C_DATAFRAME_NDOUGA_RAKOTOARINIA_E_CDATAFRAME_H
