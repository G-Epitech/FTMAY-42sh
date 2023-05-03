/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** errors criterion tests
*/

#include <string.h>
#include <criterion/criterion.h>
#include "errors/errors.h"

Test(errors_signal, errors_strsignal_basic)
{
    char *msg = errors_strsignal(SIGSEGV);

    cr_assert_str_eq(msg, "Segmentation fault");
}

Test(errors_signal, errors_strsignal_unknwon)
{
    char *msg = errors_strsignal(1000);

    cr_assert_str_eq(msg, "Unknown signal");
}
