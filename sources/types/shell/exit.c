/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** exit
*/

#include <stdio.h>
#include "types/shell/shell.h"

static void exit_shell(shell_t *shell)
{
    shell->status = SH_EXITED;
    printf("exit\n");
}

void shell_exit(shell_t *shell)
{
    char *ignoreeof = NULL;

    if (shell->is_tty == true)
        return exit_shell(shell);
    ignoreeof = shell_get_var(shell, "ignoreeof", false);
    if (!ignoreeof)
        return exit_shell(shell);
    else if (ignoreeof)
        printf("Use 'exit' to leave tcsh.\n");
    else
        return exit_shell(shell);
}
