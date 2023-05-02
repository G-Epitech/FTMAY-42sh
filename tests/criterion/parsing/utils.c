/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** utils
*/

#include <stdio.h>
#include <string.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "types/inst/inst.h"
#include "parsing/parsing.h"
#include "types/parsing_utils/parsing_utils.h"
#include "parsing/utils.h"

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(parsing_utils, redirection_left)
{
    parsing_utils_t *test = parsing_utils_new("<");
    bool result = false;

    result = parsing_maybe_redirection(test);
    cr_assert_eq(result, true);
    parsing_utils_free(test);
}

Test(parsing_utils, redirection_double_left)
{
    parsing_utils_t *test = parsing_utils_new("<<");
    bool result = false;

    result = parsing_maybe_redirection(test);
    cr_assert_eq(result, true);
    parsing_utils_free(test);
}

Test(parsing_utils, redirection_right)
{
    parsing_utils_t *test = parsing_utils_new(">");
    bool result = false;

    result = parsing_maybe_redirection(test);
    cr_assert_eq(result, true);
    parsing_utils_free(test);
}

Test(parsing_utils, redirection_double_right)
{
    parsing_utils_t *test = parsing_utils_new(">>");
    bool result = false;

    result = parsing_maybe_redirection(test);
    cr_assert_eq(result, true);
    parsing_utils_free(test);
}

Test(parsing_utils, redirection_failed)
{
    parsing_utils_t *test = parsing_utils_new("ls > tmp");
    bool result = false;

    result = parsing_maybe_redirection(test);
    cr_assert_eq(result, false);
    parsing_utils_free(test);
}

Test(parsing_utils, display, .init=redirect_all_stdout)
{
    inst_t *instruction = NULL;

    instruction = parsing_get_main_block("(ls | grep l); cat -e <Makefile");
    parsing_display(instruction);
    fflush(stdout);
    cr_assert_stdout_eq_str("===== BLOCK =====\n   ===== COMMAND =====\n   Input: ls \n   Type: 0\n   === REDIRECTIONS ===\n   Input Type: 0\n   Output Type: 1\n\n   ===== COMMAND =====\n   Input: grep l\n   Type: 0\n   === REDIRECTIONS ===\n   Input Type: 1\n   Output Type: 0\n\n=== REDIRECTIONS ===\nInput Type: 0\nOutput Type: 0\n\n===== COMMAND =====\nInput: cat -e \nType: 0\n=== REDIRECTIONS ===\nInput Type: 2\nInput Path: Makefile\nOutput Type: 0\n\n");
}
