/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** running shell
*/

#include <stdio.h>
#include "types/shell/shell.h"

int mysh(void)
{
    int exit_code = 0;
    shell_t *shell = shell_new();
    char *input = NULL;

    while (shell->status == SH_RUNNING) {
        input = shell_get_input();
        shell_free_input(input);
    }
    exit_code = shell->exit_code;
    shell_free(shell);
    return exit_code;
}
