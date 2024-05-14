//
// Created by Kimberley on 5/14/2024.
//

#ifndef C_DATAFRAME_NDOUGA_RAKOTOARINIA_E_CDATAFRAME_H
#define C_DATAFRAME_NDOUGA_RAKOTOARINIA_E_CDATAFRAME_H

enum enum_type
{
    NULLVAL = 1 , UINT, INT, CHAR, FLOAT, DOUBLE, STRING, STRUCTURE
};
typedef enum enum_type ENUM_TYPE;

typedef struct lnode_ {
    void *data;
    struct lnode_ *prev;
    struct lnode_ *next;
} LNODE;

typedef struct list_ {
    LNODE *head;
    LNODE *tail;
} LIST;

typedef LIST CDATAFRAME;

CDATAFRAME *create_cdataframe(ENUM_TYPE *cdftype, int size);


#endif //C_DATAFRAME_NDOUGA_RAKOTOARINIA_E_CDATAFRAME_H
