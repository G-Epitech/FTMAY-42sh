/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** where
*/

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "utils/utils.h"
#include "types/cmd/cmd.h"
#include "types/cmd/defs.h"
#include "utils/asprintf2.h"
#include "types/args/defs.h"
#include "types/shell/defs.h"
#include "types/shell/shell.h"
#include "builtins/builtins.h"
#include "builtins/defs.h"

Test(builtins_where_test, test_is_system, .init=cr_redirect_stdout)
{
    cr_assert_eq(is_system("/bin/ls"), true);
}

Test(builtins_where_test, bad_test_is_system, .init=cr_redirect_stdout)
{
    cr_assert_eq(is_system(NULL), false);
}

Test(builtins_where_test, bad_name_test_get_path, .init=cr_redirect_stdout)
{
    cr_assert_null(get_path(NULL, NULL));
}

Test(builtins_where_test, test_get_path_ls, .init=cr_redirect_stdout)
{
    cr_assert_str_eq(get_path("/bin", "ls"), "/bin/ls");
}

Test(builtins_where_test, test_get_path_ls_with_slash, .init=cr_redirect_stdout)
{
    cr_assert_str_eq(get_path("/bin", "/ls"), "/bin//ls");
}

Test(builtins_where_test, test_get_path_empty, .init=cr_redirect_stdout)
{
    cr_assert_str_eq(get_path("", "ls"), "/ls");
}

Test(builtins_where_test, args_null, .init=cr_redirect_stdout)
{
    shell_t *shell = shell_new(NULL);

    cr_assert_eq(builtin_where(NULL, shell), SHELL_EXIT_ERROR);
}

Test(builtins_where_test, shell_null, .init=cr_redirect_stdout)
{
    cmd_t *cmd = cmd_new();
    args_t *args = &cmd->args;

    cr_assert_eq(builtin_where(args, NULL), SHELL_EXIT_ERROR);
}

Test(builtins_where_test, test_simple_cmd, .init=cr_redirect_stdout)
{
    shell_t *shell = shell_new(NULL);
    args_t *args = malloc(sizeof(args_t));

    args->argv = malloc(sizeof(char *) * 2);
    args->argc = 2;
    args->argv[0] = malloc(sizeof(char) * strlen("where"));
    args->argv[0] = "where";
    args->argv[1] = malloc(sizeof(char) * strlen("wc"));
    args->argv[1] = "wc";
    builtin_where(args, shell);
    fflush(stdout);
    cr_assert_stdout_eq_str("/usr/bin/wc\n/bin/wc\n");
}

Test(builtins_where_test, not_enought_argument, .init=cr_redirect_stderr)
{
    shell_t *shell = shell_new(NULL);
    args_t *args = malloc(sizeof(args_t));

    args->argv = malloc(sizeof(char *) * 1);
    args->argc = 1;
    args->argv[0] = malloc(sizeof(char) * strlen("where"));
    args->argv[0] = "where";
    cr_assert_eq(builtin_where(args, shell), SHELL_EXIT_ERROR);
    fflush(stdout);
    cr_assert_stderr_eq_str("where: Too few arguments.\n");
}

Test(builtins_where_test, test_double_cmd_builtin, .init=cr_redirect_stdout)
{
    shell_t *shell = shell_new(builtins_cmds);
    args_t *args = malloc(sizeof(args_t));

    args->argv = malloc(sizeof(char *) * 3);
    args->argc = 3;
    args->argv[0] = strdup("where");
    args->argv[1] = strdup("cd");
    args->argv[2] = strdup("wc");
    fflush(stdout);
    cr_assert_eq(builtin_where(args, shell), SHELL_EXIT_SUCCESS);
    fflush(stdout);
    cr_assert_stdout_eq_str("cd is a shell built-in\n/usr/bin/cd\n/bin/cd\n/usr/bin/wc\n/bin/wc\n");
}

Test(builtins_where_test, arg_no_exist, .init=cr_redirect_stderr)
{
    shell_t *shell = shell_new(NULL);
    cmd_t *cmd = cmd_new();
    args_t *args = &cmd->args;

    args->argv = malloc(sizeof(char *) * 1);
    args->argc = 2;
    args->argv[0] = malloc(sizeof(char) * strlen("where"));
    args->argv[0] = "where";
    args->argv[1] = malloc(sizeof(char) * strlen("adxz"));
    args->argv[1] = "adxz";
    cr_assert_eq(builtin_where(args, shell), SHELL_EXIT_ERROR);
}

Test(builtins_where_test, arg_slash)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
    shell_t *shell = shell_new(builtins_cmds);
    args_t *args = malloc(sizeof(args_t));

    args->argv = malloc(sizeof(char *) * 3);
    args->argc = 4;
    args->argv[0] = strdup("where");
    args->argv[1] = strdup("wc");
    args->argv[2] = strdup("/");
    args->argv[3] = strdup("ss");
    fflush(stdout);
    fflush(stderr);
    cr_assert_eq(builtin_where(args, shell), SHELL_EXIT_ERROR);
    fflush(stdout);
    fflush(stderr);
    cr_assert_stderr_eq_str("where: / in command makes no sense\n");
    cr_assert_stdout_eq_str("/usr/bin/wc\n/bin/wc\nwhere: / in command makes no sense\n/usr/sbin/ss\n");
}
