/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** free
*/

#include <stdlib.h>
#include "types/var/var.h"

var_t *var_new(char *name, char *value)
{
    var_t *new = malloc(sizeof(var_t));

    if (!new)
        return NULL;
    new->name = name;
    new->value = value;
    return new;
}
