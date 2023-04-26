/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** serialize
*/

#include <stdlib.h>
#include <string.h>
#include "types/var/var.h"

char *var_serialize(var_t *variable)
{
    size_t len = 0;
    char *serialized = NULL;

    if (!variable)
        return NULL;
    len = strlen(variable->name) + strlen(variable->value) + 1;
    serialized = malloc(sizeof(char *) * (len + 1));
    if (!serialized)
        return NULL;
    serialized[0] = '\0';
    strcat(serialized, variable->name);
    strcat(serialized, "=");
    strcat(serialized, variable->value);
    return serialized;
}
