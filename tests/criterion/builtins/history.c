/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** history
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "builtins/defs.h"
#include "builtins/builtins.h"
#include "types/shell/shell.h"
#include "types/history/history.h"

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(builtins_history, simple, .init=redirect_all_stdout) {
    int commands_size = 1;
    char **commands = malloc(sizeof(char*) * commands_size);
    commands[0] = "history";
    args_t args = {
        .argc = commands_size,
        .argv = commands
    };
    shell_t *shell = shell_new(builtins_cmds);
    int exit_status = 0;

    history_append_entry(shell->history, "ls");
    history_append_entry(shell->history, "pwd");
    history_append_entry(shell->history, "echo j'en");
    history_append_entry(shell->history, "echo ai");
    history_append_entry(shell->history, "echo marre");
    exit_status = builtin_history(&args, shell);
    cr_assert_eq(exit_status, 0);
    shell_free(shell);
    free(commands);
}

Test(builtins_history, option_c, .init=redirect_all_stdout) {
    int commands_size = 2;
    char **commands = malloc(sizeof(char*) * commands_size);
    commands[0] = "history";
    commands[1] = "-c";
    args_t args = {
        .argc = commands_size,
        .argv = commands
    };
    shell_t *shell = shell_new(builtins_cmds);
    int exit_status = 0;
    
    history_append_entry(shell->history, "ls");
    history_append_entry(shell->history, "pwd");
    history_append_entry(shell->history, "echo j'en");
    history_append_entry(shell->history, "echo ai");
    history_append_entry(shell->history, "echo marre");
    exit_status = builtin_history(&args, shell);
    cr_assert_eq(exit_status, 0);
    cr_assert(shell->history->selected == NULL);
    cr_assert(shell->history->entries->len == 0);
    shell_free(shell);
    free(commands);
}

Test(builtins_history, option_h, .init=redirect_all_stdout) {
    int commands_size = 2;
    char **commands = malloc(sizeof(char*) * commands_size);
    commands[0] = "history";
    commands[1] = "-h";
    args_t args = {
        .argc = commands_size,
        .argv = commands
    };
    shell_t *shell = shell_new(builtins_cmds);
    int exit_status = 0;

    history_append_entry(shell->history, "ls");
    history_append_entry(shell->history, "pwd");
    history_append_entry(shell->history, "echo j'en");
    history_append_entry(shell->history, "echo ai");
    history_append_entry(shell->history, "echo marre");
    exit_status = builtin_history(&args, shell);
    cr_assert_eq(exit_status, 0);
    shell_free(shell);
    free(commands);
}

Test(builtins_history, option_r, .init=redirect_all_stdout) {
    int commands_size = 2;
    char **commands = malloc(sizeof(char*) * commands_size);
    commands[0] = "history";
    commands[1] = "-r";
    args_t args = {
        .argc = commands_size,
        .argv = commands
    };
    shell_t *shell = shell_new(builtins_cmds);
    int exit_status = 0;

    history_append_entry(shell->history, "ls");
    history_append_entry(shell->history, "pwd");
    history_append_entry(shell->history, "echo j'en");
    history_append_entry(shell->history, "echo ai");
    history_append_entry(shell->history, "echo marre");
    exit_status = builtin_history(&args, shell);
    cr_assert_eq(exit_status, 0);
    shell_free(shell);
    free(commands);
}

Test(builtins_history, option_S, .init=redirect_all_stdout) {
    int commands_size = 2;
    char **commands = malloc(sizeof(char*) * commands_size);
    commands[0] = "history";
    commands[1] = "-S";
    args_t args = {
        .argc = commands_size,
        .argv = commands
    };
    shell_t *shell = shell_new(builtins_cmds);
    int exit_status = 0;
    
    history_append_entry(shell->history, "ls");
    history_append_entry(shell->history, "pwd");
    history_append_entry(shell->history, "echo j'en");
    history_append_entry(shell->history, "echo ai");
    history_append_entry(shell->history, "echo marre");
    exit_status = builtin_history(&args, shell);
    cr_assert_eq(exit_status, 0);
    shell_free(shell);
    free(commands);
}

Test(builtins_history, option_L, .init=redirect_all_stdout) {
    int commands_size = 2;
    char **commands = malloc(sizeof(char*) * commands_size);
    commands[0] = "history";
    commands[1] = "-L";
    args_t args = {
        .argc = commands_size,
        .argv = commands
    };
    shell_t *shell = shell_new(builtins_cmds);
    int exit_status = 0;
    
    history_append_entry(shell->history, "ls");
    history_append_entry(shell->history, "pwd");
    history_append_entry(shell->history, "echo j'en");
    history_append_entry(shell->history, "echo ai");
    history_append_entry(shell->history, "echo marre");
    exit_status = builtin_history(&args, shell);
    cr_assert_eq(exit_status, 0);
    shell_free(shell);
    free(commands);
}

Test(builtins_history, option_M, .init=redirect_all_stdout) {
    int commands_size = 2;
    char **commands = malloc(sizeof(char*) * commands_size);
    commands[0] = "history";
    commands[1] = "-M";
    args_t args = {
        .argc = commands_size,
        .argv = commands
    };
    shell_t *shell = shell_new(builtins_cmds);
    int exit_status = 0;
    
    history_append_entry(shell->history, "ls");
    history_append_entry(shell->history, "pwd");
    history_append_entry(shell->history, "echo j'en");
    history_append_entry(shell->history, "echo ai");
    history_append_entry(shell->history, "echo marre");
    exit_status = builtin_history(&args, shell);
    cr_assert_eq(exit_status, 0);
    shell_free(shell);
    free(commands);
}

Test(builtins_history, option_T, .init=redirect_all_stdout) {
    int commands_size = 2;
    char **commands = malloc(sizeof(char*) * commands_size);
    commands[0] = "history";
    commands[1] = "-T";
    args_t args = {
        .argc = commands_size,
        .argv = commands
    };
    shell_t *shell = shell_new(builtins_cmds);
    int exit_status = 0;
    
    history_append_entry(shell->history, "ls");
    history_append_entry(shell->history, "pwd");
    history_append_entry(shell->history, "echo j'en");
    history_append_entry(shell->history, "echo ai");
    history_append_entry(shell->history, "echo marre");
    exit_status = builtin_history(&args, shell);
    cr_assert_eq(exit_status, 0);
    shell_free(shell);
    free(commands);
}
