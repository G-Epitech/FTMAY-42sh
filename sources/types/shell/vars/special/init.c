/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** init
*/

#include "types/shell/defs.h"

void shell_special_vars_init(shell_t *shell)
{
    char *from_env = NULL;

    if (!shell)
        return;
    for (size_t i = 0; i < SHELL_SPECIAL_VARS_LEN; i++) {
        if (shell_special_vars[i].dependency) {
            from_env = getenv(shell_special_vars[i].dependency);
            shell_special_vars[i].updater(
                shell_special_vars[i].name,
                from_env,
                shell
            );
        }
    }
}
