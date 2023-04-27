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
    shell_t *shell = shell_new();
    unsigned char exit_status = SHELL_EXIT_SUCCESS;
    char *owd = malloc(PATH_MAX);
    char *pwd = malloc(PATH_MAX);

    shell->home = "sources/";
    getcwd(owd, PATH_MAX);
    exit_status = builtin_cd(&args, shell);
    cr_assert_eq(exit_status, SHELL_EXIT_SUCCESS);
    getcwd(pwd, PATH_MAX);
    cr_assert_str_eq(shell->pwd, pwd);
    cr_assert_str_eq(shell->owd, owd);
    cr_assert_str_eq(shell->pwd, strcat(owd, "/sources"));
    free(owd);
    free(pwd);
}

Test(builtins_cd, simple_cd_with_malloc_fail) {
    char *argv[] = {"cd"};
    args_t args = {
        .argc = 1,
        .argv = argv
    };
    shell_t *shell = shell_new();
    char *owd = malloc(PATH_MAX);
    char *pwd = malloc(PATH_MAX);

    shell->home = "sources/";
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
    shell_t *shell = shell_new();
    unsigned char exit_status = SHELL_EXIT_SUCCESS;
    char *owd = malloc(PATH_MAX);
    char *pwd = malloc(PATH_MAX);

    getcwd(owd, PATH_MAX);
    exit_status = builtin_cd(&args, shell);
    cr_assert_eq(exit_status, SHELL_EXIT_SUCCESS);
    getcwd(pwd, PATH_MAX);
    cr_assert_str_eq(shell->pwd, pwd);
    cr_assert_str_eq(shell->owd, owd);
    cr_assert_str_eq(shell->pwd, strcat(owd, "/sources"));
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
    shell_t *shell = shell_new();
    unsigned char exit_status = SHELL_EXIT_SUCCESS;
    char *owd = malloc(PATH_MAX);
    char *pwd = malloc(PATH_MAX);

    shell->home = "sources/";
    getcwd(owd, PATH_MAX);
    exit_status = builtin_cd(&args, shell);
    cr_assert_eq(exit_status, SHELL_EXIT_SUCCESS);
    getcwd(pwd, PATH_MAX);
    cr_assert_str_eq(shell->pwd, pwd);
    cr_assert_str_eq(shell->owd, owd);
    cr_assert_str_eq(shell->pwd, strcat(owd, "/sources"));
    free(owd);
    free(pwd);
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
    shell_t *shell = shell_new();
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
    cr_assert_str_eq(shell->pwd, owd);
    cr_assert_str_eq(shell->owd, pwd);
    shell_free(shell);
    free(owd);
    free(pwd);
}

Test(builtins_cd, no_args) {
    shell_t *shell = shell_new();
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
    shell_t *shell = shell_new();
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
    shell_t *shell = shell_new();
    unsigned char exit_status = SHELL_EXIT_SUCCESS;

    exit_status = builtin_cd(&args, shell);
    cr_assert_eq(exit_status, SHELL_EXIT_ERROR);
    fflush(stderr);
    cr_assert_stderr_eq_str("cd: No such file or directory\n");
    shell_free(shell);
}
