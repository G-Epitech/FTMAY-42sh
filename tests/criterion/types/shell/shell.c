/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** shell
*/

#include <unistd.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "builtins/defs.h"
#include "utils/malloc2.h"
#include "types/list/list.h"
#include "types/shell/shell.h"

Test(types_shell, new_valid_shell)
{
    shell_t *shell = shell_new(builtins_cmds);

    cr_assert_not_null(shell);
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

Test(prompt_shell, default_prompt, .init=cr_redirect_stdout)
{
    shell_t *shell = shell_new(builtins_cmds);

    shell->is_tty = true;
    shell_display_prompt(shell);
    fflush(stdout);
    cr_assert_stdout_eq_str("42sh> ");
    shell_free(shell);
}

Test(exit_shell, shell_exit_default, .init=cr_redirect_stdout)
{
    shell_t *shell = shell_new(builtins_cmds);

    shell->is_tty = true;
    shell_exit(shell);
    fflush(stdout);
    cr_assert_stdout_eq_str("exit\n");
    cr_assert_eq(shell->status, SH_EXITED);
    shell_free(shell);
}

Test(exit_shell, shell_exit_tty_off, .init=cr_redirect_stdout)
{
    shell_t *shell = shell_new(builtins_cmds);

    shell->is_tty = false;
    shell_exit(shell);
    fflush(stdout);
    cr_assert_stdout_eq_str("exit\n");
    cr_assert_eq(shell->status, SH_EXITED);
    shell_free(shell);
}

Test(exit_shell, shell_exit_tty_on_exited, .init=cr_redirect_stdout)
{
    shell_t *shell = shell_new(builtins_cmds);

    shell->is_tty = true;
    shell->status = SH_EXITED;
    shell_exit(shell);
    fflush(stdout);
    cr_assert_stdout_eq_str("exit\n");
    cr_assert_eq(shell->status, SH_EXITED);
    shell_free(shell);
}

Test(exit_shell, shell_exit_tty_on_status_running, .init=cr_redirect_stdout)
{
    shell_t *shell = shell_new(builtins_cmds);

    shell->is_tty = true;
    shell->status = SH_RUNNING;
    shell_set_var(shell, "ignoreeof", "1");
    shell->exit_in = 0;
    shell_exit(shell);
    fflush(stdout);
    cr_assert_stdout_eq_str("exit\n");
    shell_free(shell);
}

Test(exit_shell, shell_exit_tty_on_exited_exit_in_sup_to_zero, .init=cr_redirect_stdout)
{
    shell_t *shell = shell_new(builtins_cmds);

    shell->is_tty = true;
    shell->status = SH_EXITED;
    shell->exit_in = 3;
    shell_exit(shell);
    fflush(stdout);
    cr_assert_stdout_eq_str("exit\n");
    cr_assert_eq(shell->status, SH_EXITED);
    shell_free(shell);
}

Test(ignoreeof_shell, shell_exit_tty_on_with_ignoreeof_var)
{
    shell_t *shell = shell_new(builtins_cmds);

    shell->is_tty = true;
    shell->status = SH_EXITED;
    shell_set_var(shell, "ignoreeof", "2");
    cr_assert_eq(shell->exit_in, 2);
    shell_exit(shell);
    fflush(stdout);
    cr_assert_eq(shell->status, SH_RUNNING);
    cr_assert_eq(shell->exit_in, 1);
    shell_free(shell);
}
