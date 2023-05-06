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

Test(builtins_cd, simple_cd) {
    int commands_size = 1;
    char **commands = malloc(sizeof(char) * commands_size);
    commands[0] = "cd";
    args_t args = {
        .argc = commands_size,
        .argv = commands
    };
    shell_t *shell = shell_new(builtins_cmds);
    unsigned char exit_status = SHELL_EXIT_SUCCESS;
    char *owd = malloc(PATH_MAX);
    char *pwd = malloc(PATH_MAX);

    getcwd(owd, PATH_MAX);
    exit_status = builtin_cd(&args, shell);
    cr_assert_eq(exit_status, SHELL_EXIT_SUCCESS);
    getcwd(pwd, PATH_MAX);
    char *var_cwd = var_list_get_value(shell->vars, "cwd", true);
    char *var_owd = var_list_get_value(shell->vars, "owd", true);
    cr_assert_str_eq(var_cwd, pwd);
    cr_assert_str_eq(var_owd, owd);
    cr_assert_str_eq(var_cwd, getenv("HOME"));
    free(owd);
    free(pwd);
}

Test(builtins_cd, simple_cd_with_malloc_fail) {
    char *argv[] = {"cd"};
    args_t args = {
        .argc = 1,
        .argv = argv
    };
    shell_t *shell = shell_new(builtins_cmds);
    char *owd = malloc(PATH_MAX);
    char *pwd = malloc(PATH_MAX);

    getcwd(owd, PATH_MAX);
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_FAIL);
    cr_assert_eq(builtin_cd(&args, shell), SHELL_EXIT_ERROR);
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_NORMAL);
    getcwd(pwd, PATH_MAX);
    free(owd);
    free(pwd);
}

Test(builtins_cd, with_arg) {
    int commands_size = 2;
    char **commands = malloc(sizeof(char) * commands_size);
    commands[0] = "cd";
    commands[1] = "sources";
    args_t args = {
        .argc = commands_size,
        .argv = commands
    };
    shell_t *shell = shell_new(builtins_cmds);
    unsigned char exit_status = SHELL_EXIT_SUCCESS;
    char *owd = malloc(PATH_MAX);
    char *pwd = malloc(PATH_MAX);

    getcwd(owd, PATH_MAX);
    exit_status = builtin_cd(&args, shell);
    cr_assert_eq(exit_status, SHELL_EXIT_SUCCESS);
    getcwd(pwd, PATH_MAX);
    char *var_cwd = var_list_get_value(shell->vars, "cwd", true);
    char *var_owd = var_list_get_value(shell->vars, "owd", true);
    cr_assert_str_eq(var_cwd, pwd);
    cr_assert_str_eq(var_owd, owd);
    cr_assert_str_eq(var_cwd, strcat(owd, "/sources"));
    shell_free(shell);
    free(owd);
    free(pwd);
}

Test(builtins_cd, tilde) {
    int commands_size = 2;
    char **commands = malloc(sizeof(char) * commands_size);
    commands[0] = "cd";
    commands[1] = BUILTIN_CD_TILDE;
    args_t args = {
        .argc = commands_size,
        .argv = commands
    };
    shell_t *shell = shell_new(builtins_cmds);
    unsigned char exit_status = SHELL_EXIT_SUCCESS;
    char *owd = malloc(PATH_MAX);
    char *pwd = malloc(PATH_MAX);

    getcwd(owd, PATH_MAX);
    exit_status = builtin_cd(&args, shell);
    cr_assert_eq(exit_status, SHELL_EXIT_SUCCESS);
    getcwd(pwd, PATH_MAX);
    char *var_cwd = var_list_get_value(shell->vars, "cwd", true);
    char *var_owd = var_list_get_value(shell->vars, "owd", true);
    cr_assert_str_eq(var_cwd, pwd);
    cr_assert_str_eq(var_owd, owd);
    cr_assert_str_eq(var_cwd, getenv("HOME"));
    free(owd);
    free(pwd);
}

Test(builtins_cd, tilde_with_no_home, .init=cr_redirect_stderr) {
    int commands_size = 2;
    char **commands = malloc(sizeof(char) * commands_size);
    commands[0] = "cd";
    commands[1] = BUILTIN_CD_TILDE;
    args_t args = {
        .argc = commands_size,
        .argv = commands
    };
    unsetenv("HOME");
    shell_t *shell = shell_new(builtins_cmds);
    unsigned char exit_status = SHELL_EXIT_SUCCESS;

    exit_status = builtin_cd(&args, shell);
    cr_assert_eq(exit_status, SHELL_EXIT_ERROR);
    fflush(stderr);
    cr_assert_stderr_eq_str("cd: No such file or directory.\n");
    shell_free(shell);
}

Test(builtins_cd, back) {
    int commands_size = 2;
    char **commands = malloc(sizeof(char) * commands_size);
    commands[0] = "cd";
    commands[1] = "sources";
    args_t args = {
        .argc = commands_size,
        .argv = commands
    };
    shell_t *shell = shell_new(builtins_cmds);
    unsigned char exit_status = SHELL_EXIT_SUCCESS;
    char *owd = malloc(PATH_MAX);
    char *pwd = malloc(PATH_MAX);

    getcwd(owd, PATH_MAX);
    exit_status = builtin_cd(&args, shell);
    cr_assert_eq(exit_status, SHELL_EXIT_SUCCESS);
    getcwd(pwd, PATH_MAX);
    commands[1] = BUILTIN_CD_DASH;
    exit_status = builtin_cd(&args, shell);
    cr_assert_eq(exit_status, SHELL_EXIT_SUCCESS);
    char *var_cwd = var_list_get_value(shell->vars, "cwd", true);
    char *var_owd = var_list_get_value(shell->vars, "owd", true);
    cr_assert_str_eq(var_cwd, owd);
    cr_assert_str_eq(var_owd, pwd);
    shell_free(shell);
    free(owd);
    free(pwd);
}

Test(builtins_cd, no_args) {
    shell_t *shell = shell_new(builtins_cmds);
    unsigned char exit_status = SHELL_EXIT_SUCCESS;

    exit_status = builtin_cd(NULL, shell);
    cr_assert_eq(exit_status, SHELL_EXIT_ERROR);
    shell_free(shell);
}

Test(builtins_cd, too_many_args, .init=cr_redirect_stderr) {
    int commands_size = 3;
    char **commands = malloc(sizeof(char) * commands_size);
    commands[0] = "cd";
    commands[1] = "sources";
    commands[2] = "sup";
    args_t args = {
        .argc = commands_size,
        .argv = commands
    };
    shell_t *shell = shell_new(builtins_cmds);
    unsigned char exit_status = SHELL_EXIT_SUCCESS;

    exit_status = builtin_cd(&args, shell);
    cr_assert_eq(exit_status, SHELL_EXIT_ERROR);
    fflush(stderr);
    cr_assert_stderr_eq_str("cd: Too many arguments.\n");
    shell_free(shell);
}

Test(builtins_cd, bad_path, .init=cr_redirect_stderr) {
    int commands_size = 2;
    char **commands = malloc(sizeof(char) * commands_size);
    commands[0] = "cd";
    commands[1] = "invalid_folder";
    args_t args = {
        .argc = commands_size,
        .argv = commands
    };
    shell_t *shell = shell_new(builtins_cmds);
    unsigned char exit_status = SHELL_EXIT_SUCCESS;

    exit_status = builtin_cd(&args, shell);
    cr_assert_eq(exit_status, SHELL_EXIT_ERROR);
    fflush(stderr);
    cr_assert_stderr_eq_str("cd: No such file or directory.\n");
    shell_free(shell);
}
