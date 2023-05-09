/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** clear
*/

#include <stdio.h>
#include "types/list/list.h"
#include "types/history/history.h"

bool history_clear(history_t *history)
{
    if (!history)
        return false;
    list_free(history->entries, &history_entry_node_freer);
    history->selected = NULL;
    history->entries = NULL;
    return true;
}
