/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** free
*/

#include <stdlib.h>
#include "types/var/var.h"

void var_node_freer(node_data_t data)
{
    var_t *var = NODE_DATA_TO_PTR(data, var_t *);

    if (var) {
        free(var->name);
        free(var->value);
    }
    free(var);
}

void var_free(var_t *variable)
{
    if (!variable)
        return;
    free(variable->name);
    free(variable->value);
    free(variable);
}
