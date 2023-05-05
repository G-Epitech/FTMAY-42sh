/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** exit
*/

#include <stdio.h>
#include "types/shell/shell.h"

void shell_exit(shell_t *shell)
{
    if (shell->is_tty == true) {
        shell->status = SH_EXITED;
        printf("exit\n");
        fflush(stdout);
    }
}
