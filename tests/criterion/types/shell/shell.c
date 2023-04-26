/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** shell
*/

#include <unistd.h>
#include <criterion/criterion.h>
#include "types/list/list.h"
#include "types/shell/shell.h"

Test(types_shell, new_valid_shell)
{
    shell_t *shell = shell_new();

    cr_assert_not_null(shell);
    cr_assert_not_null(shell->owd);
    cr_assert_not_null(shell->pwd);
    cr_assert_not_null(shell->vars);
    cr_assert_eq(shell->exit_code, SHELL_EXIT_SUCCESS);
    cr_assert_eq(shell->is_tty, isatty(STDIN_FILENO));
    cr_assert_eq(shell->status, SH_RUNNING);
}

Test(types_shell, free_valid_shell)
{
    shell_t *shell = shell_new();

    shell_free(shell);
}

Test(types_shell, free_bad_shell)
{
    shell_t *shell = NULL;

    shell_free(shell);
}
