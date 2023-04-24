/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** free
*/

#include <stdlib.h>
#include "types/var/var.h"

void var_free(var_t *variable)
{
    if (variable->name != NULL)
        free(variable->name);
    if (variable->value != NULL)
        free(variable->value);
    if (variable != NULL)
        free(variable);
}
