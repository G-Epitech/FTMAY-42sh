/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** analyse_data
*/

#include <stdio.h>
#include <string.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "utils/malloc2.h"
#include "parsing/parsing.h"
#include "types/inst/inst.h"
#include "types/parsing_utils/parsing_utils.h"
#include "parsing/utils.h"

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(parsing_main, analyse_data, .init=redirect_all_stdout)
{
    inst_t *main = parsing_get_main_block(">tmp ls >> hello ; cat -e");

    cr_assert_stderr_eq_str("Ambiguous input redirect.\n");
    inst_free(main);
}

Test(parsing_main, failed_child_block, .init=redirect_all_stdout)
{
    inst_t *main = parsing_get_main_block("(ls > tmp | cat -e)");

    cr_assert_stderr_eq_str("Ambiguous input redirect.\n");
    inst_free(main);
}

Test(parsing_main, failed_cmd, .init=redirect_all_stdout)
{
    inst_t *main = parsing_get_main_block("(ls >>> | cat -e)");

    cr_assert_stderr_eq_str("Missing name for redirect.\n");
    inst_free(main);
}

Test(parsing_main, too_many_open, .init=redirect_all_stdout)
{
    inst_t *main = parsing_get_main_block("(((((ls | cat -e)");

    cr_assert_stderr_eq_str("Too many ('s.\n");
    inst_free(main);
}

Test(parsing_main, too_many_close, .init=redirect_all_stdout)
{
    inst_t *main = parsing_get_main_block("(ls >>> | cat -e)))))");

    cr_assert_stderr_eq_str("Too many )'s.\n");
    inst_free(main);
}

Test(parsing_main, failed_malloc_recursivity)
{
    parsing_utils_t *utils = parsing_utils_new("ls -la");
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_FAIL);
    inst_t *main = parsing_recursivity(utils);

    cr_assert_null(main);
    inst_free(main);
    parsing_utils_free(utils);
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_NORMAL);
}

Test(parsing_main, invalid_null_cmd_recursivity, .init=redirect_all_stdout)
{
    parsing_utils_t *utils = parsing_utils_new("ls ||");
    inst_t *main = parsing_recursivity(utils);

    cr_assert_null(main);
    inst_free(main);
    parsing_utils_free(utils);
}

Test(parsing_main, invalid_null_cmd_separator, .init=redirect_all_stdout)
{
    inst_t *main = parsing_get_main_block("ls && ; cat -e");

    cr_assert_stderr_eq_str("Invalid null command.\n");
    cr_assert_null(main);
    inst_free(main);
}

Test(parsing_main, invalid_null_cmd_separator_two, .init=redirect_all_stdout)
{
    inst_t *main = parsing_get_main_block("ls && &&");

    cr_assert_stderr_eq_str("Invalid null command.\n");
    cr_assert_null(main);
    inst_free(main);
}