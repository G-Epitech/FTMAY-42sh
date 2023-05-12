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

Test(builtins_where, test_is_system, .init=cr_redirect_stdout)
{
    cr_assert_eq(is_system("/bin/ls"), true);
}

Test(builtins_where, bad_test_is_system, .init=cr_redirect_stdout)
{
    cr_assert_eq(is_system(NULL), false);
}

Test(builtins_where, bad_name_test_get_path, .init=cr_redirect_stdout)
{
    cr_assert_null(get_path(NULL, NULL));
}

Test(builtins_where, test_get_path_ls, .init=cr_redirect_stdout)
{
    cr_assert_str_eq(get_path("/bin", "ls"), "/bin/ls");
}

Test(builtins_where, test_get_path_ls_with_slash, .init=cr_redirect_stdout)
{
    cr_assert_str_eq(get_path("/bin", "/ls"), "/bin//ls");
}

Test(builtins_where, test_get_path_empty, .init=cr_redirect_stdout)
{
    cr_assert_str_eq(get_path("", "ls"), "/ls");
}

Test(builtins_where, args_null, .init=cr_redirect_stdout)
{
    shell_t *shell = shell_new(NULL);

    cr_assert_eq(builtin_where(NULL, shell), SHELL_EXIT_ERROR);
}
