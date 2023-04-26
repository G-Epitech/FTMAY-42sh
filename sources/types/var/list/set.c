/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** list_set
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "types/var/var.h"
#include "types/node/node.h"
#include "types/list/list.h"

void var_list_unset(list_t *vars, char *name)
{
    node_t *node = vars ? vars->first : NULL;
    node_t *next = NULL;
    var_t *var = NULL;

    while (node) {
        var = NODE_DATA_TO_PTR(node->data, var_t *);
        next = node->next;
        if (strcmp(var->name, name) == 0)
            list_delete(vars, node, &var_node_freer);
        node = next;
    }
}

bool var_list_set(list_t *vars, char *name, char *value)
{
    var_t *variable = var_list_get(vars, name);
    node_t *node = NULL;

    if (!vars)
        return false;
    if (variable)
        return var_set(variable, value);
    variable = var_new(name, value);
    if (!variable)
        return false;
    node = node_new(NODE_DATA_FROM_PTR(variable));
    if (!node) {
        var_free(variable);
        return false;
    }
    list_append(vars, node);
    return true;
}
