/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** exit
*/

#include <stdlib.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "builtins/defs.h"
#include "builtins/builtins.h"
#include "types/shell/shell.h"

Test(builtins_unsetenv, simple_unsetenv) {
    char *argv[] = {"unsetenv", "HELLO"};
    args_t args = {.argc = 2, .argv = argv};
    shell_t *shell = shell_new(builtins_cmds);

    setenv("HELLO", "test", true);
    cr_assert_str_eq(getenv("HELLO"), "test");
    cr_assert(builtin_unsetenv(&args, shell) == SHELL_EXIT_SUCCESS);
    cr_assert_null(getenv("HELLO"), "test");
    shell_free(shell);
}

Test(builtins_unsetenv, several_unsetenv) {
    char *argv[] = {"unsetenv", "HELLO", "SUPER"};
    args_t args = {.argc = 3, .argv = argv};
    shell_t *shell = shell_new(builtins_cmds);

    setenv("HELLO", "test", true);
    setenv("SUPER", "test2", true);
    cr_assert_str_eq(getenv("HELLO"), "test");
    cr_assert_str_eq(getenv("SUPER"), "test2");
    cr_assert(builtin_unsetenv(&args, shell) == SHELL_EXIT_SUCCESS);
    cr_assert_null(getenv("HELLO"));
    cr_assert_null(getenv("SUPER"));
    shell_free(shell);
}

Test(builtins_unsetenv, unsetenv_bad_args) {
    shell_t *shell = shell_new(builtins_cmds);

    cr_assert(builtin_unsetenv(NULL, shell) == SHELL_EXIT_ERROR);
    shell_free(shell);
}

Test(builtins_unsetenv, unsetenv_too_few_args, .init=cr_redirect_stderr) {
    char *argv[] = {"unsetenv"};
    args_t args = {.argc = 1, .argv = argv};
    shell_t *shell = shell_new(builtins_cmds);

    cr_assert(builtin_unsetenv(&args, shell) == SHELL_EXIT_ERROR);
    cr_assert_stderr_eq_str("unsetenv: Too few arguments.\n");
    shell_free(shell);
}
