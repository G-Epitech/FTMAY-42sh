/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** exit
*/

#include <stdio.h>
#include <string.h>
#include "types/shell/shell.h"

static void exit_shell(shell_t *shell)
{
    if (shell->status == SH_EXITED)
        printf("exit\n");
    else {
        shell->status = SH_EXITED;
        printf("exit");
    }
}

void shell_exit(shell_t *shell)
{
    char *ignoreeof = NULL;

    if (shell->is_tty != true)
        return exit_shell(shell);
    ignoreeof = shell_get_var(shell, "ignoreeof", false);
    if (ignoreeof)
        shell->exit_in--;
    if (!ignoreeof || shell->status == SH_EXITED)
        return exit_shell(shell);
    else if (shell->exit_in > 0) {
        printf("\r\nUse \"exit\" to leave tcsh.");
    } else
        return exit_shell(shell);
}
