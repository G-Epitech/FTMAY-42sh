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

int builtin_env(args_t *args, shell_t *shell)
{
    size_t i = 0;

    (void) shell;
    if (!args)
        return SHELL_EXIT_ERROR;
    while (environ[i]) {
        puts(environ[i]);
        i += 1;
    }
    fflush(stdout);
    return 0;
}
