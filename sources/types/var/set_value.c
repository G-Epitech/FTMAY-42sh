/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** set
*/

#include <stdlib.h>
#include <string.h>
#include "types/var/var.h"

int var_set_value(var_t *variable, char *value)
{
    if (!variable)
        return 84;
    free(variable->value);
    variable->value = strdup(value);
    return 0;
}
