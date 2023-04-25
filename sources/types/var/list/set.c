/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** list_set
*/

#include <string.h>
#include "types/var/var.h"
#include "types/node/node.h"
#include "types/list/list.h"

void var_list_unset(list_t *vars, char *name)
{
    node_t *node = vars ? vars->first : NULL;
    var_t *var = NULL;

    while (node) {
        var = NODE_DATA_TO_PTR(node->data, var_t *);
        if (strcmp(var->name, name) == 0)
            list_delete(vars, node, &var_node_freer);
    }
}

void var_list_set(list_t *vars, char *name, char *value)
{
    var_t *variable = var_list_get(vars, name);

    if (!variable)
        return;
    var_set_value(variable, value);
}
