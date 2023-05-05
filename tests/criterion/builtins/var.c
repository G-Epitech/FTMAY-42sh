/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** var
*/

#include <stdlib.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "utils/malloc2.h"
#include "builtins/defs.h"
#include "builtins/builtins.h"
#include "types/shell/shell.h"

Test(builtins_var, simple_display, .init=cr_redirect_stdout) {
    shell_t *shell = shell_new(builtins_cmds);
    char *argv[] = {"var"};
    args_t args = {.argc = 1, .argv = argv};
    char *argv_set[] = {"set", "super=2", "arthur=1"};
    args_t args_set = {.argc = 3, .argv = argv_set};

    builtin_set(&args_set, shell);
    cr_assert(builtin_var(&args, shell) == SHELL_EXIT_SUCCESS);
    shell_free(shell);
}

Test(builtins_var, invalid_pointer) {
    shell_t *shell = shell_new(builtins_cmds);
    char *argv[] = {"var"};
    args_t args = {.argc = 1, .argv = argv};

    cr_assert(builtin_var(NULL, shell) == SHELL_EXIT_ERROR);
    cr_assert(builtin_var(&args, NULL) == SHELL_EXIT_ERROR);
    shell_free(shell);
}

Test(builtins_var, invalid_var_list) {
    shell_t *shell = shell_new(builtins_cmds);
    char *argv[] = {"var"};
    args_t args = {.argc = 1, .argv = argv};

    shell->vars = NULL;
    cr_assert(builtin_var(&args, shell) == SHELL_EXIT_ERROR);
}

Test(builtins_var, invalid_new_list) {
    shell_t *shell = shell_new(builtins_cmds);
    char *argv[] = {"var"};
    args_t args = {.argc = 1, .argv = argv};

    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_FAIL);
    cr_assert(builtin_var(&args, shell) == SHELL_EXIT_ERROR);
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_NORMAL);
}
