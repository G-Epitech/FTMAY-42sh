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

Test(builtins_env, simple_env, .init=cr_redirect_stdout) {
    char *argv[] = {"env"};
    args_t args = {.argc = 1, .argv = argv};
    shell_t *shell = shell_new();

    cr_assert(builtin_env(&args, shell) == SHELL_EXIT_SUCCESS);
    shell_free(shell);
}

Test(builtins_env, simple_env_with_bad_args, .init=cr_redirect_stdout) {
    shell_t *shell = shell_new();

    cr_assert(builtin_env(NULL, shell) == SHELL_EXIT_ERROR);
    shell_free(shell);
}
