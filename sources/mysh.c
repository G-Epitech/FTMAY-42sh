/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** running shell
*/

#include <stdio.h>
#include "builtins/defs.h"
#include "types/shell/shell.h"

int mysh(void)
{
    int exit_code = 0;
    shell_t *shell = shell_new(builtins_cmds);
    char *input = NULL;

    while (shell->status == SH_RUNNING) {
        shell_display_prompt(shell);
        input = shell_get_input(shell);
        free(input);
    }
    exit_code = shell->exit_code;
    shell_free(shell);
    return exit_code;
}
