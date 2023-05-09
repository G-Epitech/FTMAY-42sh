/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** env
*/

#include <stdio.h>
#include "utils/utils.h"
#include "types/args/defs.h"
#include "types/shell/defs.h"

int builtin_unsetenv(args_t *args, shell_t *shell)
{
    (void) shell;
    if (!args)
        return SHELL_EXIT_ERROR;
    if (args->argc < 2) {
        write(2, "unsetenv: Too few arguments.\n", 29);
        return SHELL_EXIT_ERROR;
    }
    for (int i = 1; i < args->argc; i++)
        unsetenv(args->argv[i]);
    return SHELL_EXIT_SUCCESS;
}
