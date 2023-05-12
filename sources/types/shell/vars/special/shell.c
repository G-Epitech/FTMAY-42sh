/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** tty
*/

#include "types/var/var.h"
#include "types/shell/shell.h"

bool shell_special_vars_shell_init(char *name, shell_t *shell, char *dependency)
{
    (void) dependency;
    if (!name || !shell)
        return false;
    return var_list_set(shell->vars, name, SHELL_PATH);
}
