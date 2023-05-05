/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** errors criterion tests
*/

#include <string.h>
#include <criterion/criterion.h>
#include "errors/errors.h"

Test(errors_error, errors_strerror_basic)
{
    char *msg = errors_strerror(ENOENT);

    cr_assert_str_eq(msg, "No such file or directory.");
}

Test(errors_error, errors_strerror_unknwon)
{
    char *msg = errors_strerror(1000);

    cr_assert_str_eq(msg, "Unknown error.");
}
