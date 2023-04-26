/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** set
*/

#include "types/var/var.h"
#include "types/shell/defs.h"

void shell_unset_env(shell_t *shell, char *name)
{
    list_t *env = shell ? shell->env : NULL;

    var_list_unset(env, name);
}

bool shell_set_env(shell_t *shell, char *name, char *value)
{
    list_t *env = shell ? shell->env : NULL;

    return var_list_set(env, name, value);
}

char *shell_get_env(shell_t *shell, char *name, bool copy)
{
    list_t *vars = shell ? shell->env : NULL;

    return var_list_get_value(vars, name, copy);
}

char **shell_env_serialize(shell_t *shell)
{
    list_t *env = shell ? shell->env : NULL;

    return var_list_serialize(env);
}
