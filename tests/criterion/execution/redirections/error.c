/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** error
*/

#include <errno.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "utils/malloc2.h"
#include "execution/redirections.h"

Test(redirections_error, forbidden_access, .init=cr_redirect_stderr)
{
    execution_redirections_error("tests/utils/sh/fobidden.sh", EACCES);
    fflush(stderr);
    cr_assert_stderr_eq_str("tests/utils/sh/fobidden.sh: Permission denied.\n");
}
