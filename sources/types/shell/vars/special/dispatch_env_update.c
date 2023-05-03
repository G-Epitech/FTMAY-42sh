/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** dispatch_env_update
*/

#include <string.h>
#include "types/shell/shell.h"

void shell_special_vars_dispatch_env_update(shell_t *shell, char *name)
{
    const var_special_t *var = NULL;

    if (!shell || ! name)
        return;
    for (size_t i = 0; i < SHELL_SPECIAL_VARS_LEN; i++) {
        var = &(shell_special_vars[i]);
        if (!var->dependency || ! var->updater)
            continue;
        if (strcmp(var->dependency, name) == 0)
            var->updater(var->name, getenv(name), shell);
    }
}
