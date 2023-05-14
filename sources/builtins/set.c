/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** set
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils/utils.h"
#include "utils/malloc2.h"
#include "types/var/var.h"
#include "types/args/defs.h"
#include "types/shell/shell.h"
#include "builtins/builtins.h"

static bool list_set(shell_t *shell, char *name, char *value)
{
    if (!CHAR_IS_ALPHA(name[0])) {
        fprintf(stderr, "set: Variable name must begin with a letter.\n");
        return false;
    }
    shell_set_var(shell, name, value);
    return true;
}

static bool parse_value(shell_t *shell, char *name, char *value)
{
    char *new_value = malloc2(sizeof(char) * strlen(value) - 2);
    size_t i = 1;

    if (value[0] != '"') {
        free(new_value);
        return list_set(shell, name, value);
    }
    while (value[i + 1] != '\0') {
        new_value[i - 1] = value[i];
        i++;
    }
    if (value[i] != '"') {
        fprintf(stderr, "Unmatched '\"'.\n");
        return false;
    }
    new_value[strlen(value) - 2] = '\0';
    return list_set(shell, name, new_value);
}

static bool set_var_value(args_t *args, shell_t *shell, int *index)
{
    char *consumable = strdup(args->argv[*index]);
    char *name = strtok(consumable, "=");
    char *value = strtok(NULL, "=");

    (*index)++;
    if (value) {
        return parse_value(shell, name, value);
    }
    if (*index == args->argc || strcmp(args->argv[*index], "="))
        return list_set(shell, name, "");
    (*index)++;
    if (*index == args->argc)
        return list_set(shell, name, "");
    (*index)++;
    return parse_value(shell, name, args->argv[*index - 1]);
}

int builtin_set(args_t *args, shell_t *shell)
{
    int index = 0;

    if (!args)
        return SHELL_EXIT_ERROR;
    if (args->argc == 1)
        return builtin_var(args, shell);
    while (index < args->argc) {
        if (!set_var_value(args, shell, &index))
            return SHELL_EXIT_ERROR;
    }
    return SHELL_EXIT_SUCCESS;
}
