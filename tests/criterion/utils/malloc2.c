/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** is_number
*/

#include <unistd.h>
#include <string.h>
#include <criterion/criterion.h>
#include "utils/malloc2.h"

Test(utils_malloc2, simple_malloc_string) {
    char *str = malloc2(6);

    cr_assert_not_null(str);
    strcpy(str, "hello");
    str[5] = '\0';
    cr_assert_str_eq(str, "hello");
    free(str);
}

Test(utils_malloc2, simple_malloc_fail) {
    char *str = NULL;

    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_FAIL);
    str = malloc2(6);
    cr_assert_null(str);
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_NORMAL);
}
