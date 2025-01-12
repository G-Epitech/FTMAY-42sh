/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** exit
*/

#include <stdio.h>
#include "utils/utils.h"
#include "types/args/defs.h"
#include "types/shell/defs.h"
#include "types/shell/shell.h"

int builtin_exit(args_t *args, shell_t *shell)
{
    if (!args)
        return SHELL_EXIT_ERROR;
    shell->exit_in = 0;
    if (args->argc == 1) {
        shell->status = SH_EXITED;
        if (shell->is_tty)
            printf("exit\n");
        return SHELL_EXIT_SUCCESS;
    }
    if (args->argc != 2 || !is_number(args->argv[1])) {
        fprintf(stderr, "exit: Expression Syntax.\n");
        return SHELL_EXIT_ERROR;
    }
    if (shell->is_tty)
        printf("exit\n");
    shell->status = SH_EXITED;
    return atoi(args->argv[1]);
}
