/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** utils
*/

#include <criterion/criterion.h>
#include "types/parsing_utils/parsing_utils.h"
#include "parsing/utils.h"

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

