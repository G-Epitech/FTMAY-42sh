/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** list_set
*/

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "types/var/defs.h"
#include "types/list/defs.h"
#include "types/node/defs.h"

var_t *var_list_get(list_t *vars, char *name)
{
    node_t *node = vars ? vars->first : NULL;
    var_t *var = NULL;

    while (node) {
        var = NODE_DATA_TO_PTR(node->data, var_t *);
        if (strcmp(var->name, name) == 0)
            return var;
    }
    return NULL;
}

char *var_list_get_value(list_t *vars, char *name, bool copy)
{
    var_t *var = var_list_get(vars, name);
    char *value = NULL;

    if (!var)
        return NULL;
    if (copy)
        value = strdup(var->value);
    else
        value = var->value;
    return value;
}
