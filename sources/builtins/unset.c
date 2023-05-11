/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** unset
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils/utils.h"
#include "utils/malloc2.h"
#include "types/var/var.h"
#include "types/args/defs.h"
#include "types/shell/defs.h"

int builtin_unset(args_t *args, shell_t *shell)
{
    int index = 1;

    if (!args)
        return SHELL_EXIT_ERROR;
    if (args->argc == 1) {
        fprintf(stderr, "unset: Too few arguments.\n");
        return SHELL_EXIT_ERROR;
    }
    while (index < args->argc) {
        var_list_unset(shell->vars, args->argv[index]);
        index++;
    }
    return SHELL_EXIT_SUCCESS;
}
