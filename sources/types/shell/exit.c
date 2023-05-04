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
    shell->status = SH_EXITED;
    printf("exit\n");
}

