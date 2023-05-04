/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** set
*/

#include <stdio.h>
#include <strings.h>
#include "utils/utils.h"
#include "types/var/var.h"
#include "types/args/defs.h"
#include "types/shell/defs.h"

static bool list_set(shell_t *shell, char *name, char *value)
{
    if (!CHAR_IS_ALPHA(name[0])) {
        fprintf(stderr, "set: Variable name must begin with a letter.\n");
        return false;
    }
    var_list_set(shell->vars, name, value);
    return true;
}

static bool set_var_value(args_t *args, shell_t *shell, int *index)
{
    char *consumable = strdup(args->argv[*index]);
    char *name = strtok(consumable, "=");
    char *value = strtok(NULL, "=");

    (*index)++;
    if (value)
        return list_set(shell, name, value);
    if (*index == args->argc || strcmp(args->argv[*index], "="))
        return list_set(shell, name, "");
    (*index)++;
    if (*index == args->argc)
        return list_set(shell, name, "");
    (*index)++;
    return list_set(shell, name, args->argv[*index - 1]);
}

unsigned char builtin_set(args_t *args, shell_t *shell)
{
    int index = 0;

    if (!args)
        return SHELL_EXIT_ERROR;
    if (args->argc == 1) {
        return SHELL_EXIT_SUCCESS;
    }
    while (index < args->argc) {
        if (!set_var_value(args, shell, &index)) {
            return SHELL_EXIT_ERROR;
        }
    }
    return SHELL_EXIT_SUCCESS;
}
