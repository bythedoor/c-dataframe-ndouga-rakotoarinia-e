//
// Created by Kimberley on 3/31/2024.
//

#include <stdlib.h>
#include "column.h"

COLUMN *create_column(char* title)
{
    COLUMN c = {*title, 256, 0, {}};
    COLUMN* c_ptr = NULL;
    return c_ptr;
}