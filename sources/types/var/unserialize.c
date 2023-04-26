/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** unserialize
*/

#include <stdlib.h>
#include <string.h>
#include "types/var/var.h"
#include "types/list/list.h"
#include "types/node/node.h"

static char *get_name(char *var)
{
    char *name = NULL;
    int len = 0;

    if ((!*var))
        return name;
    while (var[len] != '=')
        len += 1;
    len += 1;
    name = malloc(sizeof(char) * len);
    if (!name)
        return NULL;
    name[0] = '\0';
    strncpy(name, var, len - 1);
    return name;
}

static char *get_value(char *var)
{
    char *value = NULL;
    int len = 0;

    if ((!*var))
        return value;
    while (*var != '=')
        var++;
    var++;
    while (var[len] != '\0')
        len += 1;
    len += 1;
    value = malloc(sizeof(char) * len);
    if (!value)
        return NULL;
    value[0] = '\0';
    strncpy(value, var, len - 1);
    return value;
}

var_t *var_unserialize(char *serialized)
{
    char *name = serialized ? get_name(serialized) : NULL;
    char *value = serialized ? get_value(serialized) : NULL;
    var_t *var = NULL;

    if (name && value)
        var = var_new(name, value);
    free(name);
    free(value);
    return var;
}
