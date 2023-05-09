/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** append
*/

#include <string.h>
#include <stdbool.h>
#include "types/list/list.h"
#include "types/node/node.h"
#include "types/history/history.h"

bool history_append_entry(history_t *history, char *input)
{
    history_entry_t *new_entry = history_entry_new();
    node_t *node = NULL;
    node_data_t node_data;

    if (!new_entry | !history | !input)
        return false;
    new_entry->date = time(NULL);
    new_entry->input = strdup(input);
    new_entry->id = history->count + 1;
    node_data = NODE_DATA_FROM_PTR(new_entry);
    node = node_new(node_data);
    list_append(history->entries, node);
    history->selected = node;
    history->count++;
    return true;
}
