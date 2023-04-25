/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** exit
*/

#include <stdio.h>
#include "types/shell/defs.h"
#include "types/args/defs.h"
#include "utils/utils.h"

unsigned char *builtin_exit(args_t *args, shell_t *shell)
{
    if (args->argc == 1) {
        shell->status = SH_EXITED;
        return SHELL_EXIT_SUCCESS;
    }
    if (args->argc != 2 || !is_number(args->argv[1])) {
        fprintf(stderr, "exit: Expression Syntax.\n");
        return SHELL_EXIT_ERROR;
    }
    shell->status = SH_EXITED;
    return atoi(args->argv[1]);
}
