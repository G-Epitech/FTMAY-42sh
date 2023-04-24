/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** List type free function
*/

#include <stdlib.h>
#include "types/list/defs.h"
#include "types/node/node.h"

void list_free(list_t *list, node_freer_t freer)
{
    node_t *node = list ? list->first : NULL;
    node_t *next = NULL;

    while (node) {
        next = node->next;
        node_free(node, freer);
        node = next;
    }
    free(list);
}
