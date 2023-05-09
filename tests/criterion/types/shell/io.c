/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** get_input
*/

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "builtins/defs.h"
#include "types/inst/inst.h"
#include "types/shell/shell.h"
#include "execution/execution.h"
#include "execution/redirections.h"

Test(shell_io_tests, basic_init, .init=cr_redirect_stdout)
{
    shell_t shell;

    cr_assert(shell_init_io(&shell));
    cr_assert(fcntl(shell.io.stdin, F_GETFD) != -1);
    cr_assert(fcntl(shell.io.stdout, F_GETFD) != -1);
    write(shell.io.stdout, "hello\nworld\n", 12);
    cr_assert_stdout_eq_str("hello\nworld\n");
}

Test(shell_io_tests, null_shell_init)
{
    cr_assert_not(shell_init_io(NULL));
}


Test(shell_io_tests, basic_restore)
{
    shell_t shell;

    cr_assert(shell_init_io(&shell));
    cr_assert(fcntl(shell.io.stdin, F_GETFD) != -1);
    cr_assert(fcntl(shell.io.stdout, F_GETFD) != -1);
    cr_assert(shell_restore_io(&shell));
}

Test(shell_io_tests, restore_with_null_shell)
{
    cr_assert_not(shell_restore_io(NULL));
}
