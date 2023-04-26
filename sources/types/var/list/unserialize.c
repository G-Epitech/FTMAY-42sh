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

static void unserialize_and_append_var(list_t *vars, char *serialized)
{
    var_t *var = var_unserialize(serialized);
    node_t *node = NULL;

    if (!var || !vars)
        return;
    node = node_new(NODE_DATA_FROM_PTR(var));
    if (!node)
        return var_free(var);
    list_append(vars, node);
}

list_t *var_list_unserialize(char **list)
{
    list_t *vars = list_new();

    while (*list && vars) {
        unserialize_and_append_var(vars, *list);
        list++;
    }
    return vars;
}
