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

void find_node(list_t *list, char *input)
{
    node_t *tmp = list->first;
    history_entry_t *entry = NULL;

    while (tmp) {
        entry = NODE_DATA_TO_PTR(tmp->data, history_entry_t *);
        if (strcmp(entry->input, input) == 0)
            list_delete(list, tmp, &history_entry_node_freer);
        tmp = tmp->next;
    }
}

bool history_append_entry(history_t *history, char *input)
{
    history_entry_t *new_entry = history_entry_new();
    node_t *node = NULL;
    node_data_t node_data;

    if (!new_entry | !history | !input)
        return false;
    find_node(history->entries, input);
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

void list_append_after(list_t *list, node_t *ref, node_t *node)
{
    if (ref != NULL) {
        node->next = ref->next;
        ref->next = node;
        node->prev = ref;
    } else {
        list->first->prev = node;
        node->next = list->first;
        list->first = node;
        node->prev = NULL;
    }
    list->len++;
}

static node_t *find_node_time(list_t *list, long int date)
{
    node_t *tmp = list->first;
    history_entry_t *entry = NULL;

    while (tmp) {
        entry = NODE_DATA_TO_PTR(tmp->data, history_entry_t *);
        if (date <= entry->date)
            return tmp;
        tmp = tmp->next;
    }
    return NULL;
}

bool history_append_entry_date(history_t *history, char *input, long int date)
{
    node_t *pos = NULL;
    node_t *node = NULL;
    history_entry_t *new_entry = history_entry_new();

    if (!new_entry | !history | !input | !history->entries->first)
        return false;
    find_node(history->entries, input);
    new_entry->date = date == -1 ? time(NULL) : date;
    new_entry->input = strdup(input);
    new_entry->id = history->count + 1;
    node = node_new(NODE_DATA_FROM_PTR(new_entry));
    pos = find_node_time(history->entries, new_entry->date);
    if (pos)
        list_append_after(history->entries, pos->prev, node);
    else
        list_append(history->entries, node);
    history->selected = history->entries->last;
    history->count++;
    return true;
}
