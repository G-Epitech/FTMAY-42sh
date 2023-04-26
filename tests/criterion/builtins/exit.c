/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** exit
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "builtins/builtins.h"
#include "types/args/args.h"
#include "types/shell/shell.h"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(builtins_exit, simple_exit) {
    char **commands = malloc(sizeof(char) * 1);
    commands[0] = "Exit";
    args_t args = {
        .argc = 1,
        .argv = commands
    };
    shell_t *shell = shell_new();
    unsigned char exit_status = builtin_exit(&args, shell);

    cr_assert_eq(exit_status, SHELL_EXIT_SUCCESS);
    cr_assert_eq(shell->status, SH_EXITED);
}

Test(builtins_exit, number_exit) {
    int commands_size = 2;
    char **commands = malloc(sizeof(char) * commands_size);
    commands[0] = "Exit";
    commands[1] = "100";
    args_t args = {
        .argc = commands_size,
        .argv = commands
    };
    shell_t *shell = shell_new();
    unsigned char exit_status = builtin_exit(&args, shell);

    cr_assert_eq(exit_status, 100);
    cr_assert_eq(shell->status, SH_EXITED);
}

Test(builtins_exit, multiple_args, .init=redirect_all_stdout) {
    int commands_size = 3;
    char **commands = malloc(sizeof(char) * commands_size);
    commands[0] = "Exit";
    commands[1] = "100";
    commands[2] = "2";
    args_t args = {
        .argc = commands_size,
        .argv = commands
    };
    shell_t *shell = shell_new();
    unsigned char exit_status = builtin_exit(&args, shell);

    cr_assert_eq(exit_status, 1);
    cr_assert_stderr_eq_str("exit: Expression Syntax.\n");
}

Test(builtins_exit, invalid_string_args, .init=redirect_all_stdout) {
    int commands_size = 2;
    char **commands = malloc(sizeof(char) * commands_size);
    commands[0] = "Exit";
    commands[1] = "test_string";
    args_t args = {
        .argc = commands_size,
        .argv = commands
    };
    shell_t *shell = shell_new();
    unsigned char exit_status = builtin_exit(&args, shell);

    cr_assert_eq(exit_status, 1);
    cr_assert_stderr_eq_str("exit: Expression Syntax.\n");
}
