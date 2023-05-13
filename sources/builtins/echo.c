/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** echo
*/

#include <stdio.h>
#include <string.h>
#include "utils/utils.h"
#include "types/args/defs.h"
#include "types/shell/defs.h"

static bool builtin_echo_needs_new_line(args_t *args)
{
    if (args->argc < 2)
        return true;
    return strcmp(args->argv[1], "-n") != 0;
}

int builtin_echo(args_t *args, shell_t *shell)
{
    bool new_line = builtin_echo_needs_new_line(args);
    int start = !new_line ? 2 : 1;

    (void) shell;
    for (int i = start; i < args->argc; i++) {
        printf("%s", args->argv[i]);
        if (i < args->argc - 1)
            printf(" ");
    }
    if (new_line)
        printf("\n");
    return SHELL_EXIT_SUCCESS;
}
