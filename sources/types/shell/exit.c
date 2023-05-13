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
    if (shell->is_tty == true)
        printf("exit\n");
    shell->status = SH_EXITED;
}

void shell_exit(shell_t *shell)
{
    char *ignoreeof = NULL;

    if (shell->is_tty == false)
        return exit_shell(shell);
    ignoreeof = shell_get_var(shell, "ignoreeof", false);
    if (ignoreeof)
        shell->exit_in--;
    if (!ignoreeof || (shell->status == SH_EXITED && shell->exit_in == 0))
        return exit_shell(shell);
    else if (shell->exit_in > 0) {
        shell->status = SH_RUNNING;
        printf("\nUse \"exit\" to leave tcsh.\n");
    } else {
        return exit_shell(shell);
    }
}
