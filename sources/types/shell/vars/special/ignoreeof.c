/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** ignoreeof
*/

#include "types/var/var.h"
#include "types/shell/shell.h"

bool shell_special_vars_ignoreeof_set(char *name, char *value, char *dependency,
shell_t *shell)
{
    (void) dependency;
    shell->exit_in = SHELL_VAR_IGNOREEOF(value);
    return var_list_set(shell->vars, name, value);
}
