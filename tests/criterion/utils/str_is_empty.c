/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** str_is_string
*/

#include <unistd.h>
#include <string.h>
#include <criterion/criterion.h>
#include "utils/utils.h"

Test(utils_str_is_empty, with_null_arg) {
    cr_assert(str_is_empty(NULL));
}

Test(utils_str_is_empty, with_empty_string) {
    cr_assert(str_is_empty("           "));
}

Test(utils_str_is_empty, with_empty_string_containing_tabs) {
    cr_assert(str_is_empty("   \t    \t\t\t    "));
}

Test(utils_str_is_empty, no_empty) {
    cr_assert_not(str_is_empty(" &  \t  e \t\t\t e   "));
}
