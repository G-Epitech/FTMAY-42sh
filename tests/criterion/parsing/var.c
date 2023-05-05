/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** pipe
*/

#include <stdio.h>
#include <string.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "types/inst/inst.h"
#include "parsing/parsing.h"
#include "types/shell/shell.h"

Test(replace_var, local_variable_not_exist, .init=cr_redirect_stderr)
{
    shell_t *shell = shell_new();
    shell_set_var(shell, "test_1", "axel");
    shell_set_var(shell, "test_2", "flav");
    shell_set_var(shell, "test_3", "yannou");

    char *replace = parsing_var_replace("first var : $test_4\t", shell);
    cr_assert_null(replace);
    cr_stderr_match_str("test_4: Undefined variable.");
}

Test(replace_var, multiple_local_variable_not_exist, .init=cr_redirect_stderr)
{
    shell_t *shell = shell_new();
    shell_set_var(shell, "test_1", "axel");
    shell_set_var(shell, "test_2", "flav");
    shell_set_var(shell, "test_3", "yannou");

    char *replace = parsing_var_replace("echo $a $b $c\t", shell);
    cr_assert_null(replace);
    cr_stderr_match_str("test_1: Undefined variable.");
}

Test(replace_var, multiple_variable_env_not_exist, .init=cr_redirect_stderr)
{
    shell_t *shell = shell_new();
    shell_set_var(shell, "test_1", "axel");
    shell_set_var(shell, "test_2", "flav");
    shell_set_var(shell, "test_3", "yannou");

    char *replace = parsing_var_replace("echo $HOM $USE \t", shell);
    cr_assert_null(replace);
    cr_stderr_match_str("HOM: Undefined variable.");
}

Test(replace_var, simple_local_variable)
{
    shell_t *shell = shell_new();
    shell_set_var(shell, "test1", "axel");

    char *replace = parsing_var_replace("first var : $test1\t", shell);
    cr_assert_str_eq(replace, "first var : axel\t");
}

Test(replace_var, triple_local_variable)
{
    shell_t *shell = shell_new();
    shell_set_var(shell, "test1", "axel");
    shell_set_var(shell, "test2", "flav");
    shell_set_var(shell, "test_3", "yannou");

    char *replace = parsing_var_replace("first var : $test1, $test2 , $test_3\t", shell);
    cr_assert_str_eq(replace, "first var : axel, flav , yannou\t");
}
