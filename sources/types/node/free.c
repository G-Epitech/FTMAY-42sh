/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** Node free
*/

#include <stdlib.h>
#include "types/node/defs.h"

void node_free(node_t *node, node_freeer_t freeer)
{
    if (!node)
        return;
    if (freeer)
        freeer(node->data);
    free(node);
}
