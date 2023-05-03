/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** get_word
*/

#include <stdio.h>
#include <string.h>
#include <criterion/criterion.h>
#include "types/inst/inst.h"
#include "parsing/parsing.h"
#include "types/parsing_utils/parsing_utils.h"

Test(get_word, test_get_simple_word)
{
    parsing_utils_t *utils = parsing_utils_new("ls < test");
    char *test = parsing_get_word(utils, 5, 9);

    cr_assert_str_eq(test, "test");
}

Test(get_word, bad_start)
{
    parsing_utils_t *utils = parsing_utils_new("ls < test");
    char *test = parsing_get_word(utils, -1, 9);

    cr_assert_null(test);
}

Test(get_word, bad_end)
{
    parsing_utils_t *utils = parsing_utils_new("ls < test");
    char *test = parsing_get_word(utils, 5, -1);

    cr_assert_null(test);
}

Test(get_word, to_high_end)
{
    parsing_utils_t *utils = parsing_utils_new("ls < test");
    char *test = parsing_get_word(utils, 5, 25);

    cr_assert_null(test);
}

Test(get_word, to_high_start)
{
    parsing_utils_t *utils = parsing_utils_new("ls < test");
    char *test = parsing_get_word(utils, 10, 5);

    cr_assert_null(test);
}

Test(get_word, to_high_start_and_end)
{
    parsing_utils_t *utils = parsing_utils_new("ls < test");
    char *test = parsing_get_word(utils, 90, 90);

    cr_assert_null(test);
}

Test(get_word, neg_start_end)
{
    parsing_utils_t *utils = parsing_utils_new("ls < test");
    char *test = parsing_get_word(utils, 0, -1);

    cr_assert_null(test);
}
