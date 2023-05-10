/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** ctrl
*/

#include <stdio.h>
#include <string.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "utils/utils.h"
#include "builtins/defs.h"
#include "utils/malloc2.h"
#include "types/input_line/handlers.h"
#include "types/input_line/input_line.h"

Test(test_get_key, test_key_del)
{
    int test_return = input_line_get_character(KEY_DEL);
    cr_assert_eq(test_return, CTRL_KEY_DEL);
}

Test(test_get_key, test_anykey)
{
    int test_return = input_line_get_character(1);
    cr_assert_eq(test_return, 1);
}

Test(test_get_ctrl, test_ctrl_a)
{
    int test_return = input_line_get_cntrls(KEY_CTRL_A);
    cr_assert_eq(test_return, CTRL_KEY_A);
}

Test(test_get_ctrl, test_ctrl_d)
{
    int test_return = input_line_get_cntrls(KEY_CTRL_D);
    cr_assert_eq(test_return, CTRL_KEY_D);
}

Test(test_get_ctrl, test_ctrl_enter)
{
    int test_return = input_line_get_cntrls(KEY_CTRL_ENTER);
    cr_assert_eq(test_return, CTRL_KEY_ENTER);
}
