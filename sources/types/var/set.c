/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** set
*/

#include <stdlib.h>
#include <string.h>
#include "types/var/var.h"

bool var_set(var_t *variable, char *value)
{
    if (!variable || !value)
        return false;
    free(variable->value);
    variable->value = strdup(value);
    return true;
}
