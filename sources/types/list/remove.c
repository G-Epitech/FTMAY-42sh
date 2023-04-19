/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** remove
*/

#include <stdlib.h>
#include "types/list/list.h"
#include "types/node/node.h"

void list_remove(list_t *list, node_t *node)
{
    node_unlink(node);
    if (list->first == node)
        list->first = node->next;
    if (list->first)
        list->first->prev = NULL;
    if (list->last == node)
        list->last = node->prev;
    if (list->last)
        list->last->next = NULL;
    list->len--;
}

void list_delete(list_t *list, node_t *node, node_freeer_t freeer)
{
    list_remove(list, node);
    node_free(node, freeer);
}
