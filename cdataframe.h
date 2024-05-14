//
// Created by Kimberley on 5/14/2024.
//

#ifndef C_DATAFRAME_NDOUGA_RAKOTOARINIA_E_CDATAFRAME_H
#define C_DATAFRAME_NDOUGA_RAKOTOARINIA_E_CDATAFRAME_H

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

#endif //C_DATAFRAME_NDOUGA_RAKOTOARINIA_E_CDATAFRAME_H
