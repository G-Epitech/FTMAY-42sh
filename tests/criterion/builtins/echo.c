/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** cd
*/

#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "utils/malloc2.h"
#include "builtins/defs.h"
#include "types/var/var.h"
#include "types/args/defs.h"
#include "types/shell/shell.h"
#include "builtins/builtins.h"

Test(builtins_echo, simple_echo, .init=cr_redirect_stdout) {
    int commands_size = 3;
    char *argv[3] = {"echo", "hello", "world"};
    args_t args = {
        .argc = commands_size,
        .argv = argv
    };
    shell_t *shell = shell_new(builtins_cmds);

    cr_assert(builtin_echo(&args, shell) == SHELL_EXIT_SUCCESS);
   fflush(stdout);
    cr_assert_stdout_eq_str("hello world\n");
}

Test(builtins_echo, simple_echo_with_no_args, .init=cr_redirect_stdout) {
    int commands_size = 1;
    char *argv[1] = {"echo"};
    args_t args = {
        .argc = commands_size,
        .argv = argv
    };
    shell_t *shell = shell_new(builtins_cmds);

    cr_assert(builtin_echo(&args, shell) == SHELL_EXIT_SUCCESS);
   fflush(stdout);
    cr_assert_stdout_eq_str("\n");
}

Test(builtins_echo, simple_echo_with_no_new_line, .init=cr_redirect_stdout) {
    int commands_size = 4;
    char *argv[4] = {"echo", "-n", "hello", "world"};
    args_t args = {
        .argc = commands_size,
        .argv = argv
    };
    shell_t *shell = shell_new(builtins_cmds);

    cr_assert(builtin_echo(&args, shell) == SHELL_EXIT_SUCCESS);
    fflush(stdout);
    cr_assert_stdout_eq_str("hello world");
}

Test(builtins_echo, simple_echo_with_no_new_line_no_args, .init=cr_redirect_stdout) {
    int commands_size = 2;
    char *argv[2] = {"echo", "-n"};
    args_t args = {
        .argc = commands_size,
        .argv = argv
    };
    shell_t *shell = shell_new(builtins_cmds);

    cr_assert(builtin_echo(&args, shell) == SHELL_EXIT_SUCCESS);
    fflush(stdout);
    cr_assert_stdout_eq_str("");
}
