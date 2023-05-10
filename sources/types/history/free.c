/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** free
*/

#include "types/list/list.h"
#include "types/history/history.h"

void history_free(history_t *history)
{
    if (!history)
        return;
    list_free(history->entries, &history_entry_node_freer);
    free(history);
}
