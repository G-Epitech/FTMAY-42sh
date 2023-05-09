/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** asprintf2
*/

#include <criterion/criterion.h>
#include "utils/malloc2.h"
#include "utils/asprintf2.h"

Test(utils_asprintf2, simple_command) {
    bool status = false;
    char *new_value = NULL;

    status = asprintf2(&new_value, "test: %s", "Yes!") >= 0;
    cr_assert(status);
    cr_assert_str_eq(new_value, "test: Yes!");
}

Test(utils_asprintf2, invalid_malloc) {
    bool status = false;
    char *new_value = NULL;

    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_FAIL);
    status = asprintf2(&new_value, "test: %s", "Yes!") >= 0;
    cr_assert_null(new_value);
    cr_assert(!status);
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_NORMAL);
}
