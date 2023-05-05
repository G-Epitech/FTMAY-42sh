/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** exit
*/

#include <stdlib.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "builtins/builtins.h"
#include "types/shell/shell.h"

Test(builtins_unset, unvalid_unset, .init=cr_redirect_stderr) {
    char *argv[] = {"unsetenv"};
    args_t args = {.argc = 1, .argv = argv};
    shell_t *shell = shell_new();

    builtin_unset(&args, shell);
    cr_assert_stderr_eq_str("unset: Too few arguments.\n");
    shell_free(shell);
}

Test(builtins_unset, invalid_pointer, .init=cr_redirect_stderr) {
    shell_t *shell = shell_new();

    cr_assert(builtin_unset(NULL, shell) == SHELL_EXIT_ERROR);
    shell_free(shell);
}

Test(builtins_unset, simple_unsetenv) {
    char *argv[] = {"unsetenv", "super"};
    args_t args = {.argc = 2, .argv = argv};
    char *argv_set[] = {"set", "super"};
    args_t args_set = {.argc = 2, .argv = argv_set};
    shell_t *shell = shell_new();

    builtin_set(&args_set, shell);
    cr_assert_str_eq(NODE_DATA_TO_PTR(shell->vars->last->data, var_t *)->name, "super");
    cr_assert_str_eq(NODE_DATA_TO_PTR(shell->vars->last->data, var_t *)->value, "");
    int len = shell->vars->len;
    builtin_unset(&args, shell);
    shell->vars->len = len - 1;
    shell_free(shell);
}

Test(builtins_unset, multi_unsetenv) {
    char *argv[] = {"unsetenv", "super", "cool"};
    args_t args = {.argc = 3, .argv = argv};
    char *argv_set[] = {"set", "super", "test", "cool"};
    args_t args_set = {.argc = 4, .argv = argv_set};
    shell_t *shell = shell_new();

    builtin_set(&args_set, shell);
    cr_assert_str_eq(NODE_DATA_TO_PTR(shell->vars->last->data, var_t *)->name, "cool");
    cr_assert_str_eq(NODE_DATA_TO_PTR(shell->vars->last->data, var_t *)->value, "");
    cr_assert_str_eq(NODE_DATA_TO_PTR(shell->vars->last->prev->data, var_t *)->name, "test");
    cr_assert_str_eq(NODE_DATA_TO_PTR(shell->vars->last->prev->data, var_t *)->value, "");
    cr_assert_str_eq(NODE_DATA_TO_PTR(shell->vars->last->prev->prev->data, var_t *)->name, "super");
    cr_assert_str_eq(NODE_DATA_TO_PTR(shell->vars->last->prev->prev->data, var_t *)->value, "");
    int len = shell->vars->len;
    builtin_unset(&args, shell);
    shell->vars->len = len - 2;
    cr_assert_str_eq(NODE_DATA_TO_PTR(shell->vars->last->data, var_t *)->name, "test");
    cr_assert_str_eq(NODE_DATA_TO_PTR(shell->vars->last->data, var_t *)->value, "");
    shell_free(shell);
}
