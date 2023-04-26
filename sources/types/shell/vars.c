/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** set
*/

#include "types/var/var.h"
#include "types/shell/defs.h"

void shell_unset_var(shell_t *shell, char *name)
{
    list_t *vars = shell ? shell->vars : NULL;

    var_list_unset(vars, name);
}

bool shell_set_var(shell_t *shell, char *name, char *value)
{
    list_t *vars = shell ? shell->vars : NULL;

    return var_list_set(vars, name, value);
}

char *shell_get_var(shell_t *shell, char *name, bool copy)
{
    list_t *vars = shell ? shell->vars : NULL;

    return var_list_get_value(vars, name, copy);
}
