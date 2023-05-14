/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** which
*/

#include <stdlib.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "builtins/defs.h"
#include "types/cmd/cmd.h"
#include "utils/malloc2.h"
#include "types/cmd/defs.h"
#include "types/args/defs.h"
#include "types/shell/defs.h"
#include "builtins/builtins.h"
#include "types/shell/shell.h"

Test(builtins_which, unvalid_args, .init=cr_redirect_stderr) {
    char *argv[] = {"which"};
    args_t args = {.argc = 1, .argv = argv};
    shell_t *shell = shell_new(builtins_cmds);

    builtin_which(&args, shell);
    cr_assert_stderr_eq_str("which: Too few arguments.\n");
    shell_free(shell);
}

Test(builtins_which, one_args, .init=cr_redirect_stdout) {
    char *argv[] = {"which", "ls"};
    args_t args = {.argc = 2, .argv = argv};
    shell_t *shell = shell_new(builtins_cmds);
    int status = SHELL_EXIT_SUCCESS;

    status = builtin_which(&args, shell);
    cr_assert_eq(status, SHELL_EXIT_SUCCESS);
    shell_free(shell);
}

Test(builtins_which, multi_args, .init=cr_redirect_stdout) {
    char *argv[] = {"which", "ls", "env", "cd"};
    args_t args = {.argc = 4, .argv = argv};
    shell_t *shell = shell_new(builtins_cmds);
    int status = SHELL_EXIT_SUCCESS;

    status = builtin_which(&args, shell);
    cr_assert_eq(status, SHELL_EXIT_SUCCESS);
    shell_free(shell);
}

Test(builtins_which, bad_args_not_command, .init=cr_redirect_stdout) {
    char *argv[] = {"which", "not_command"};
    args_t args = {.argc = 2, .argv = argv};
    shell_t *shell = shell_new(builtins_cmds);
    int status = SHELL_EXIT_SUCCESS;

    status = builtin_which(&args, shell);
    cr_assert_eq(status, SHELL_EXIT_ERROR);
    fflush(stdout);
    shell_free(shell);
}

Test(builtins_which, bad_malloc, .init=cr_redirect_stdout) {
    char *argv[] = {"which", "ls"};
    args_t args = {.argc = 2, .argv = argv};
    shell_t *shell = shell_new(builtins_cmds);
    int status = SHELL_EXIT_SUCCESS;

    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_FAIL);
    status = builtin_which(&args, shell);
    cr_assert_eq(status, SHELL_EXIT_ERROR);
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_NORMAL);
    fflush(stdout);
    shell_free(shell);
}

Test(builtins_which, bad_args, .init=cr_redirect_stdout) {
    char *argv[] = {"which", "ls"};
    args_t args = {.argc = 2, .argv = argv};
    shell_t *shell = shell_new(builtins_cmds);
    int status = SHELL_EXIT_SUCCESS;

    status = builtin_which(NULL, shell);
    cr_assert_eq(status, SHELL_EXIT_ERROR);
    status = builtin_which(&args, NULL);
    cr_assert_eq(status, SHELL_EXIT_ERROR);
    fflush(stdout);
    shell_free(shell);
}
