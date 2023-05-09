/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** io
*/

#include <stdbool.h>
#include "types/shell/shell.h"

bool shell_init_io(shell_t *shell)
{
    if (!shell)
        return false;
    shell->io.stdin = dup(STDIN_FILENO);
    shell->io.stdout = dup(STDOUT_FILENO);
    return true;
}

bool shell_restore_io(shell_t *shell)
{
    if (!shell)
        return false;
    dup2(shell->io.stdin, STDIN_FILENO);
    dup2(shell->io.stdout, STDOUT_FILENO);
    return true;
}
