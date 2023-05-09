/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** free
*/

#include "types/node/defs.h"
#include "types/history/defs.h"

void history_entry_free(history_entry_t *history_entry)
{
    if (!history_entry)
        return;
    free(history_entry->input);
    free(history_entry);
}

void history_entry_node_freer(node_data_t data)
{
    history_entry_t *entry = NODE_DATA_TO_PTR(data, history_entry_t *);

    history_entry_free(entry);
}
