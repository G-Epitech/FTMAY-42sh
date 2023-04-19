/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** append
*/

#include "types/list/defs.h"

void list_append(list_t *list, node_t *node)
{
    if (list->last != NULL) {
        node->next = list->last->next;
        list->last->next = node;
        node->prev = list->last;
    } else {
        node->next = list->first;
        list->first = node;
        node->prev = NULL;
    }
    list->last = node;
    list->last->next = NULL;
    list->len++;
}
