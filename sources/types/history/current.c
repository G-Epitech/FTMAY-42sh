/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** current
*/

#include <stdio.h>
#include "types/history/history.h"

history_entry_t *history_current(history_t *history)
{
    if (!history || !history->selected)
        return NULL;
    return NODE_DATA_TO_PTR(history->selected->data, history_entry_t *);
}
