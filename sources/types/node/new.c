/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** Node type new function
*/

#include <stdlib.h>
#include "types/node/defs.h"

node_t *node_new(node_data_t data)
{
    node_t *node = malloc(sizeof(node_t));

    if (!node)
        return NULL;
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}
