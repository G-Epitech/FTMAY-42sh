/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** new
*/

#include "utils/malloc2.h"
#include "types/history/defs.h"

history_entry_t *history_entry_new(void)
{
    history_entry_t *tmp = malloc2(sizeof(history_entry_t));

    if (!tmp)
        return NULL;
    tmp->date = 0;
    tmp->id = 0;
    tmp->input = NULL;
    return tmp;
}
