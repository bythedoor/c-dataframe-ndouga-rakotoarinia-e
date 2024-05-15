//
// Created by Kimberley on 5/14/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "liste.h"


LNODE *lst_create_lnode(void *dat) {
    LNODE *ptmp = (LNODE *) malloc(sizeof(LNODE));
    ptmp->data = dat;
    ptmp->next = NULL;
    ptmp->prev = NULL;
    return ptmp;
}
LIST *lst_create_list() {
    LIST *lst = (LIST *) malloc(sizeof(LIST));
    lst->head = NULL;
    lst->tail = NULL;
    return lst;
}
void lst_delete_list(LIST * lst) {
    lst_erase(lst);
    free(lst);
}
void lst_insert_head(LIST * lst, LNODE * pnew) {
    if (lst->head == NULL) {
        lst->head = pnew;
        lst->tail = pnew;
        return;
    }
    pnew->next = lst->head;
    pnew->prev = NULL;
    lst->head = pnew;
    pnew->next->prev = pnew;
}
void lst_insert_tail(LIST * lst, LNODE * pnew) {
    if (lst->head == NULL) {
        lst->head = pnew;
        lst->tail = pnew;
        return;
    }
    pnew->next = NULL;
    pnew->prev = lst->tail;
    lst->tail = pnew;
    pnew->prev->next = pnew;
}
void lst_insert_after(LIST * lst, LNODE * pnew, LNODE * ptr) {
    if (lst->head == NULL) {
        lst->head = pnew;
        lst->tail = pnew;
    } else if (ptr == NULL) {
        return;
    } else if (lst->tail == ptr) {
        lst_insert_tail(lst, pnew);
    } else {
        pnew->next = ptr->next;
        pnew->prev = ptr;
        pnew->next->prev = pnew;
        pnew->prev->next = pnew;
    }
}
void lst_delete_head(LIST * lst) {
    if (lst->head->next == NULL) {
        free(lst->head);
        lst->head = NULL;
        lst->tail = NULL;
        return;
    }
    lst->head = lst->head->next;
    free(lst->head->prev);
    lst->head->prev = NULL;
}
void lst_delete_tail(LIST * lst) {
    if (lst->tail->prev == NULL) {
        free(lst->tail);
        lst->head = NULL;
        lst->tail = NULL;
        return;
    }
    lst->tail = lst->tail->prev;
    free(lst->tail->next);
    lst->tail->next = NULL;
}
void lst_delete_lnode(LIST * lst, LNODE * ptr) {
    if (ptr == NULL)
        return;
    if (ptr == lst->head) {
        lst_delete_head(lst);
        return;
    }
    if (ptr == lst->tail) {
        lst_delete_tail(lst);
        return;
    }
    ptr->next->prev = ptr->prev;
    ptr->prev->next = ptr->next;
    free(ptr);
}
void lst_erase(LIST * lst) {
    if (lst->head == NULL)
        return;
    while (lst->head != lst->tail) {
        lst->head = lst->head->next;
        free(lst->head->prev);
    }
    free(lst->head);
    lst->head = NULL;
    lst->tail = NULL;
}
LNODE *get_first_node(LIST * lst) {
    if (lst->head == NULL)
        return NULL;
    return lst->head;
}
LNODE *get_last_node(LIST * lst) {
    if (lst->tail == NULL)
        return NULL;
    return lst->tail;
}
LNODE *get_next_node(LIST * lst, LNODE * lnode) {
    if (lnode == NULL)
        return NULL;
    return lnode->next;
}
void *get_previous_elem(LIST * lst, LNODE * lnode) {
    if (lnode == NULL)
        return NULL;
    return lnode->prev;
}