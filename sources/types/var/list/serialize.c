/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** list_set
*/

#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "types/var/var.h"
#include "types/node/node.h"
#include "types/list/list.h"

static void serialize_and_append_var(var_t *variable,
size_t i, char **export)
{
    char *serialized = var_serialize(variable);

    if (!variable)
        export[i] = NULL;
    else
        export[i] = serialized;
}

char **var_list_serialize(list_t *vars)
{
    node_t *node = vars ? vars->first : NULL;
    char **export = vars ? malloc(sizeof(char *) * (vars->len + 1)) : NULL;
    var_t *var = NULL;
    size_t i = 0;

    if (!export)
        return NULL;
    while (node) {
        var = NODE_DATA_TO_PTR(node->data, var_t *);
        serialize_and_append_var(var, i, export);
        node = node->next;
        i++;
    }
    export[i] = NULL;
    return export;
}
