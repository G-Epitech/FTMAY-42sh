/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** Node type free function
*/

#include <stdlib.h>
#include "types/node/defs.h"

void node_free(node_t *node, node_freer_t freer)
{
    if (!node)
        return;
    if (freer)
        freer(node->data);
    free(node);
}
