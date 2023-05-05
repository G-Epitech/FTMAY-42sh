/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** set
*/

#include <string.h>
#include "types/var/var.h"
#include "types/shell/defs.h"

static const var_special_t *get_special_var(char *name)
{
    if (!name)
        return NULL;
    for (size_t i = 0; i < SHELL_SPECIAL_VARS_LEN; i++) {
        if (strcmp(shell_special_vars[i].name, name) == 0)
            return &(shell_special_vars[i]);
    }
    return NULL;
}

void shell_unset_var(shell_t *shell, char *name)
{
    list_t *vars = shell ? shell->vars : NULL;

    var_list_unset(vars, name);
}

bool shell_set_var(shell_t *shell, char *name, char *value)
{
    list_t *vars = shell ? shell->vars : NULL;
    const var_special_t *special = get_special_var(name);

    if (!special)
        return var_list_set(vars, name, value);
    if (special->setter)
        return special->setter(name, value, special->dependency, shell);
    return true;
}

char *shell_get_var(shell_t *shell, char *name, bool copy)
{
    list_t *vars = shell ? shell->vars : NULL;
    const var_special_t *special = get_special_var(name);

    if (!special)
        return var_list_get_value(vars, name, copy);
    if (special->getter)
        return special->getter(shell, name, copy);
    return NULL;
}
