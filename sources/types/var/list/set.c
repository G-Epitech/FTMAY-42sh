/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** list_set
*/

#include "types/var/var.h"
#include "types/list/defs.h"

void var_list_set(list_t *vars, char *name, char *value)
{
    var_t *variable = var_list_get(vars, name);

    if (!variable)
        return;
    var_set_value(variable, value);
}
