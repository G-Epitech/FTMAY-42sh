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
#include "utils/malloc2.h"

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

Test(parsing_utils, input_is_null)
{
    cr_assert_null(parsing_utils_new(NULL));
}

Test(parsing_utils, malloc_failed)
{
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_FAIL);
    cr_assert_null(parsing_utils_new("ls"));
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_NORMAL);
}
