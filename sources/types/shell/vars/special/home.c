/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** home
*/

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "types/var/var.h"
#include "utils/malloc2.h"
#include "utils/asprintf2.h"
#include "types/shell/shell.h"

static bool set_home_from_cwd(char *value, shell_t *shell)
{
    char *cwd = malloc2(PATH_MAX);
    char *new_value = NULL;
    bool status = false;

    if (!cwd)
        return false;
    getcwd(cwd, PATH_MAX);
    shell_set_var(shell, "cwd", cwd);
    free(cwd);
    cwd = shell_get_var(shell, "cwd", false);
    status = asprintf2(&new_value, "%s/%s", cwd, value) >= 0;
    if (status)
        status = var_list_set(shell->vars, "home", new_value);
    free(new_value);
    return status;
}

bool shell_special_vars_home_update(char *name, char *value, shell_t *shell)
{
    if (!shell || !value)
        return false;
    if (strlen(value) == 0)
        return false;
    if (value[0] == '/')
        return var_list_set(shell->vars, name, value);
    else
        return set_home_from_cwd(value, shell);
}

bool shell_special_vars_home_set(char *name, char *value, char *dependency,
shell_t *shell)
{
    bool status = shell_special_vars_home_update(name, value, shell);
    char *new_value = shell_get_var(shell, "home", false);

    if (status && dependency && new_value)
        setenv(dependency, new_value, true);
    return status;
}

char *shell_special_vars_home_get(shell_t *shell, char *name, bool copy)
{
    if (!shell)
        return NULL;
    return var_list_get_value(shell->vars, name, copy);
}
