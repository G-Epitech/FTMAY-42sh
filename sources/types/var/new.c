/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** free
*/

#include <stdlib.h>
#include <string.h>
#include "types/var/var.h"

var_t *var_new(char *name, char *value)
{
    var_t *new = (name && value) ? malloc(sizeof(var_t)) : NULL;

    if (!new)
        return NULL;
    new->name = strdup(name);
    new->value = strdup(value);
    return new;
}
