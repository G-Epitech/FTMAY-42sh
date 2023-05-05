/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** shell
*/

#include <unistd.h>
#include <criterion/criterion.h>
#include "builtins/defs.h"
#include "utils/malloc2.h"
#include "types/list/list.h"
#include "types/shell/shell.h"

Test(types_shell, new_valid_shell)
{
    shell_t *shell = shell_new(builtins_cmds);

    cr_assert_not_null(shell);
    cr_assert_not_null(shell->owd);
    cr_assert_not_null(shell->pwd);
    cr_assert_not_null(shell->vars);
    cr_assert_eq(shell->exit_code, SHELL_EXIT_SUCCESS);
    cr_assert_eq(shell->is_tty, isatty(STDIN_FILENO));
    cr_assert_eq(shell->status, SH_RUNNING);
}

Test(types_shell, new_shell_with_malloc_fail)
{
    shell_t *shell = NULL;

    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_FAIL);
    shell = shell_new(builtins_cmds);
    cr_assert_null(shell);
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_NORMAL);
    shell_free(shell);
}

Test(types_shell, free_valid_shell)
{
    shell_t *shell = shell_new(builtins_cmds);

    shell_free(shell);
}

Test(types_shell, free_bad_shell)
{
    shell_t *shell = NULL;

    shell_free(shell);
}
