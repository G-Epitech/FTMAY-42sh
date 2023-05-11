/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** tty
*/

#include <unistd.h>
#include "types/var/var.h"
#include "types/shell/shell.h"

bool shell_special_vars_tty_init(char *name, shell_t *shell, char *dependency)
{
    char *tty = ttyname(STDIN_FILENO);

    (void) dependency;
    if (!name || !shell || !tty)
        return false;
    return var_list_set(shell->vars, name, tty);
}
