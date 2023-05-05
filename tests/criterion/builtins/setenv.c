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

Test(builtins_setenv, simple_setenv_without_args, .init=cr_redirect_stdout) {
    char *argv[] = {"setenv"};
    args_t args = {.argc = 1, .argv = argv};
    shell_t *shell = shell_new(builtins_cmds);

    cr_assert(builtin_setenv(&args, shell) == SHELL_EXIT_SUCCESS);
    shell_free(shell);
}

Test(builtins_setenv, simple_setenv_with_args) {
    char *argv[] = {"setenv", "var", "hello"};
    args_t args = {.argc = 3, .argv = argv};
    shell_t *shell = shell_new(builtins_cmds);

    cr_assert(builtin_setenv(&args, shell) == SHELL_EXIT_SUCCESS);
    shell_free(shell);
}

Test(builtins_setenv, simple_setenv_with_args_name_upper) {
    char *argv[] = {"setenv", "Var", "hello"};
    args_t args = {.argc = 3, .argv = argv};
    shell_t *shell = shell_new(builtins_cmds);

    cr_assert(builtin_setenv(&args, shell) == SHELL_EXIT_SUCCESS);
    shell_free(shell);
}

Test(builtins_setenv, simple_setenv_with_args_name_num) {
    char *argv[] = {"setenv", "var2", "hello"};
    args_t args = {.argc = 3, .argv = argv};
    shell_t *shell = shell_new(builtins_cmds);

    cr_assert(builtin_setenv(&args, shell) == SHELL_EXIT_SUCCESS);
    shell_free(shell);
}

Test(builtins_setenv, setenv_bad_var_name, .init=cr_redirect_stderr) {
    char *argv[] = {"setenv", "1var", "hello"};
    args_t args = {.argc = 3, .argv = argv};
    shell_t *shell = shell_new(builtins_cmds);

    cr_assert(builtin_setenv(&args, shell) == SHELL_EXIT_ERROR);
    cr_assert_stderr_eq_str("setenv: Variable name must begin with a letter.\n");
    shell_free(shell);
}

Test(builtins_setenv, setenv_bad_var_name2, .init=cr_redirect_stderr) {
    char *argv[] = {"setenv", "va-r", "hello"};
    args_t args = {.argc = 3, .argv = argv};
    shell_t *shell = shell_new(builtins_cmds);

    cr_assert(builtin_setenv(&args, shell) == SHELL_EXIT_ERROR);
    cr_assert_stderr_eq_str("setenv: Variable name must contain "
    "alphanumeric characters.\n");
    shell_free(shell);
}

Test(builtins_setenv, setenv_bad_var_name3, .init=cr_redirect_stderr) {
    char *argv[] = {"setenv", "va-r", "hello"};
    args_t args = {.argc = 3, .argv = argv};
    shell_t *shell = shell_new(builtins_cmds);

    cr_assert(builtin_setenv(&args, shell) == SHELL_EXIT_ERROR);
    cr_assert_stderr_eq_str("setenv: Variable name must contain "
    "alphanumeric characters.\n");
    shell_free(shell);
}

Test(builtins_setenv, setenv_bad_var_name4, .init=cr_redirect_stderr) {
    char *argv[] = {"setenv", "|hello", "salut"};
    args_t args = {.argc = 3, .argv = argv};
    shell_t *shell = shell_new(builtins_cmds);

    cr_assert(builtin_setenv(&args, shell) == SHELL_EXIT_ERROR);
    cr_assert_stderr_eq_str("setenv: Variable name must begin with a letter.\n");
    shell_free(shell);
}

Test(builtins_setenv, setenv_bad_var_name5, .init=cr_redirect_stderr) {
    char *argv[] = {"setenv", "$hello", "salut"};
    args_t args = {.argc = 3, .argv = argv};
    shell_t *shell = shell_new(builtins_cmds);

    cr_assert(builtin_setenv(&args, shell) == SHELL_EXIT_ERROR);
    cr_assert_stderr_eq_str("setenv: Variable name must begin with a letter.\n");
    shell_free(shell);
}

Test(builtins_setenv, setenv_bad_var_name6, .init=cr_redirect_stderr) {
    char *argv[] = {"setenv", "V\tr", "Hello"};
    args_t args = {.argc = 3, .argv = argv};
    shell_t *shell = shell_new(builtins_cmds);

    cr_assert(builtin_setenv(&args, shell) == SHELL_EXIT_ERROR);
    cr_assert_stderr_eq_str("setenv: Variable name must contain "
    "alphanumeric characters.\n");
    shell_free(shell);
}

Test(builtins_setenv, setenv_bad_var_name7, .init=cr_redirect_stderr) {
    char *argv[] = {"setenv", "V|r", "Hello"};
    args_t args = {.argc = 3, .argv = argv};
    shell_t *shell = shell_new(builtins_cmds);

    cr_assert(builtin_setenv(&args, shell) == SHELL_EXIT_ERROR);
    cr_assert_stderr_eq_str("setenv: Variable name must contain "
    "alphanumeric characters.\n");
    shell_free(shell);
}

Test(builtins_setenv, setenv_bad_var_name8, .init=cr_redirect_stderr) {
    char *argv[] = {"setenv", "he:l", "super"};
    args_t args = {.argc = 3, .argv = argv};
    shell_t *shell = shell_new(builtins_cmds);

    cr_assert(builtin_setenv(&args, shell) == SHELL_EXIT_ERROR);
    cr_assert_stderr_eq_str("setenv: Variable name must contain "
    "alphanumeric characters.\n");
    shell_free(shell);
}

Test(builtins_setenv, setenv_bad_var_name9, .init=cr_redirect_stderr) {
    char *argv[] = {"setenv", "he[l", "super"};
    args_t args = {.argc = 3, .argv = argv};
    shell_t *shell = shell_new(builtins_cmds);

    cr_assert(builtin_setenv(&args, shell) == SHELL_EXIT_ERROR);
    cr_assert_stderr_eq_str("setenv: Variable name must contain "
    "alphanumeric characters.\n");
    shell_free(shell);
}

Test(builtins_setenv, setenv_bad_var_name10, .init=cr_redirect_stderr) {
    char *argv[] = {"setenv", "V|\t$:", "super"};
    args_t args = {.argc = 3, .argv = argv};
    shell_t *shell = shell_new(builtins_cmds);

    cr_assert(builtin_setenv(&args, shell) == SHELL_EXIT_ERROR);
    cr_assert_stderr_eq_str("setenv: Variable name must contain "
    "alphanumeric characters.\n");
    shell_free(shell);
}

Test(builtins_setenv, setenv_with_bad_value, .init=cr_redirect_stderr) {
    char *argv[] = {"setenv", "var", "=hello"};
    args_t args = {.argc = 3, .argv = argv};
    shell_t *shell = shell_new(builtins_cmds);

    cr_assert(builtin_setenv(&args, shell) == SHELL_EXIT_ERROR);
    cr_assert_stderr_eq_str("Directory stack not that deep.\n");
    shell_free(shell);
}

Test(builtins_setenv, setenv_too_many_args, .init=cr_redirect_stderr) {
    char *argv[] = {"setenv", "var", "hello", "super3"};
    args_t args = {.argc = 4, .argv = argv};
    shell_t *shell = shell_new(builtins_cmds);

    cr_assert(builtin_setenv(&args, shell) == SHELL_EXIT_ERROR);
    cr_assert_stderr_eq_str("setenv: Too many arguments.\n");
    shell_free(shell);
}

Test(builtins_setenv, setenv_empty_var_name, .init=cr_redirect_stderr) {
    char *argv[] = {"setenv", ""};
    args_t args = {.argc = 2, .argv = argv};
    shell_t *shell = shell_new(builtins_cmds);

    cr_assert(builtin_setenv(&args, shell) == SHELL_EXIT_ERROR);
    cr_assert_stderr_eq_str("setenv: Variable name must begin with a letter.\n");
    shell_free(shell);
}

Test(builtins_setenv, setenv_null_args, .init=cr_redirect_stderr) {
    shell_t *shell = shell_new(builtins_cmds);

    cr_assert(builtin_setenv(NULL, shell) == SHELL_EXIT_ERROR);
    shell_free(shell);
}
