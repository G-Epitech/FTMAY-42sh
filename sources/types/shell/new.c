/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** new
*/

#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include "utils/malloc2.h"
#include "types/var/var.h"
#include "types/list/list.h"
#include "types/shell/shell.h"

static bool shell_init_data(shell_t *shell, const builtin_t *builtins)
{
    shell->exit_code = SHELL_EXIT_SUCCESS;
    shell->is_tty = isatty(STDIN_FILENO);
    shell->status = SH_RUNNING;
    shell->vars = list_new();
    shell->builtins = builtins;
    shell_special_vars_init(shell);
    return true;
}

shell_t *shell_new(const builtin_t *builtins)
{
    shell_t *shell = malloc2(sizeof(shell_t));

    if (!shell)
        return NULL;
    if (!shell_init_data(shell, builtins))
        return NULL;
    return shell;
}
