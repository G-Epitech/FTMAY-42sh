/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** new
*/

#include <stdlib.h>
#include "types/list/defs.h"

list_t *list_new(void)
{
    list_t *list = malloc(sizeof(list_t));

    if (!list)
        return NULL;
    list->first = NULL;
    list->last = NULL;
    list->len = 0;
    return list;
}
