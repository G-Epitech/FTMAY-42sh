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
    if (!variable)
        return;
    free(variable->name);
    free(variable->value);
    free(variable);
}
