/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** home
*/

#include "types/var/var.h"
#include "types/shell/shell.h"

bool shell_special_vars_std_update(char *name, char *value, shell_t *shell)
{
    if (!shell || !value)
        return false;
    return var_list_set(shell->vars, name, value);
}

bool shell_special_vars_std_set(char *name, char *value, char *dependency,
shell_t *shell)
{
    if (dependency)
        setenv(dependency, value, true);
    return shell_special_vars_std_update(name, value, shell);
}

char *shell_special_vars_std_get(shell_t *shell, char *name, bool copy)
{
    if (!shell)
        return NULL;
    return var_list_get_value(shell->vars, name, copy);
}
