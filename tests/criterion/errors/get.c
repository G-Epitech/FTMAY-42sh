/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** errors criterion tests
*/

#include <string.h>
#include <criterion/criterion.h>
#include "errors/errors.h"

Test(errors_get, errors_get_message_sig_return_sigint)
{
    char *ptr = NULL;

    ptr = errors_get_message_of_code(errors_sig_msg, SIGINT);
    cr_assert(ptr == NULL);
}

Test(errors_get, errors_get_message_sig_return_sigquit)
{
    char *ptr = NULL;

    ptr = errors_get_message_of_code(errors_sig_msg, SIGQUIT);
    cr_assert(!strcmp(ptr, "Quit"));
}

Test(errors_get, errors_get_message_sig_return_null)
{
    char *ptr = NULL;

    ptr = errors_get_message_of_code(errors_sig_msg, 999);
    cr_assert_str_eq(ptr, "Unknown signal");
}

Test(errors_get, errors_get_message_errno_return_eacces)
{
    char *ptr = NULL;

    ptr = errors_get_message_of_code(errors_errno_msg, EACCES);
    cr_assert(!strcmp(ptr, "Permission denied."));
}

Test(errors_get, errors_get_message_errno_return_null)
{
    char *ptr = NULL;

    ptr = errors_get_message_of_code(errors_sig_msg, 999);
    cr_assert_str_eq(ptr, "Unknown signal");
}

Test(errors_get, errors_get_message_null)
{
    char *ptr = NULL;

    ptr = errors_get_message_of_code(NULL, 999);
    cr_assert(ptr == NULL);
}
