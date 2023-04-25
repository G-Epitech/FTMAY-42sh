/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** is_number
*/

#include <unistd.h>
#include <string.h>
#include <criterion/criterion.h>
#include "utils/utils.h"

Test(utils_is_number, valid_simple_number) {
    cr_assert(is_number("0"));
}

Test(utils_is_number, valid_positiv_numbers) {
    cr_assert(is_number("1"));
    cr_assert(is_number("10"));
    cr_assert(is_number("1230987654"));
}

Test(utils_is_number, valid_negativ_numbers) {
    cr_assert(is_number("-1"));
    cr_assert(is_number("-10"));
    cr_assert(is_number("-1230987654"));
}

Test(utils_is_number, unvalid_numbers) {
    cr_assert(!is_number("b"));
    cr_assert(!is_number("123456a"));
    cr_assert(!is_number("--1"));
}

Test(utils_is_number, null_number) {
    cr_assert(!is_number(NULL));
}
