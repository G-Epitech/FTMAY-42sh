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

static bool shell_init_data(shell_t *shell)
{
    shell->exit_code = SHELL_EXIT_SUCCESS;
    shell->is_tty = isatty(STDIN_FILENO);
    shell->pwd = malloc2(PATH_MAX + 1);
    shell->owd = malloc2(PATH_MAX + 1);
    if (!shell->pwd || !shell->owd) {
        shell_free(shell);
        return false;
    }
    getcwd(shell->pwd, PATH_MAX);
    shell->owd[0] = '\0';
    shell->status = SH_RUNNING;
    shell->vars = list_new();
    return true;
}

shell_t *shell_new(void)
{
    shell_t *shell = malloc2(sizeof(shell_t));

    if (!shell)
        return NULL;
    if (!shell_init_data(shell))
        return NULL;
    return shell;
}
