/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** shell
*/

#include <unistd.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "utils/malloc2.h"
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

Test(types_shell, new_shell_with_malloc_fail)
{
    shell_t *shell = NULL;

    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_FAIL);
    shell = shell_new();
    cr_assert_null(shell);
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_NORMAL);
    shell_free(shell);
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

Test(prompt_shell, default_prompt, .init=cr_redirect_stdout)
{
    shell_t *shell = shell_new();

    shell_display_prompt(shell);
    cr_assert_stdout_eq_str("42sh> ");
    shell_free(shell);
}

Test(exit_shell, shell_exit_default, .init=cr_redirect_stdout)
{
    shell_t *shell = shell_new();

    shell->is_tty = true;
    shell_exit(shell);
    cr_assert_stdout_eq_str("exit\n");
    cr_assert_eq(shell->status, SH_EXITED);
    shell_free(shell);
}

Test(input_shell, shell_input_default) {
    char* test_input = "shell_input_default";
    shell_t *shell = shell_new();
    char reader[100];
    int p[2] = {0, 0};
    char *output = NULL;

    memset(reader, '\0', 100);
    cr_assert(pipe(p) != -1, "Failed to create pipe.");
    cr_assert(dup2(p[0], STDIN_FILENO) != -1, "Failed to redirect stdin to pipe.");
    write(p[1], test_input, strlen(test_input));
    close(p[1]);

    output = shell_get_input(shell);
    cr_assert_str_eq(output, test_input);

    close(p[0]);
    shell_free(shell);
}

Test(input_shell, shell_input_command) {
    char* test_input = "\0";
    shell_t *shell = shell_new();
    char reader[100];
    int p[2] = {0, 0};
    char *output = NULL;

    memset(reader, '\0', 100);
    cr_assert(pipe(p) != -1, "Failed to create pipe.");
    cr_assert(dup2(p[0], STDIN_FILENO) != -1, "Failed to redirect stdin to pipe.");
    write(p[1], test_input, strlen(test_input));
    close(p[1]);

    output = shell_get_input(shell);
    cr_assert_str_eq(output, test_input);

    close(p[0]);
    shell_free(shell);
}
