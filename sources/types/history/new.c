/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** new
*/

#include "utils/malloc2.h"
#include "types/list/list.h"
#include "types/history/defs.h"

history_t *history_new(void)
{
    history_t *tmp = malloc2(sizeof(history_t));

    if (!tmp)
        return NULL;
    tmp->count = 0;
    tmp->selected = NULL;
    tmp->entries = list_new();
    return tmp;
}
