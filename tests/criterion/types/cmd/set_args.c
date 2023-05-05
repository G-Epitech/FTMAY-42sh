/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** separator
*/

#include <stdio.h>
#include <string.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "types/cmd/cmd.h"
#include "utils/malloc2.h"
#include "builtins/defs.h"
#include "parsing/parsing.h"
#include "types/inst/inst.h"
#include "types/shell/shell.h"
#include "types/parsing_utils/parsing_utils.h"

Test(parsing_set_cmd_args, test_with_guillemet)
{
    cmd_t *command = cmd_new();

    command->input = "echo \"super $PWD\"";
    cmd_set_args(command);
    cr_assert_eq(command->args.argc, 2);
    cr_assert_str_eq(command->args.argv[0], "echo");
    cr_assert_str_eq(command->args.argv[1], "super $PWD");
}

Test(parsing_set_cmd_args, test_without_innibiteur)
{
    cmd_t *command = cmd_new();

    command->input = "echo super";
    cmd_set_args(command);
    cr_assert_eq(command->args.argc, 2);
    cr_assert_str_eq(command->args.argv[0], "echo");
    cr_assert_str_eq(command->args.argv[1], "super");
}

Test(parsing_set_cmd_args, test_without_innibiteur_separed_by_space)
{
    cmd_t *command = cmd_new();

    command->input = "echo\t\tsuper";
    cmd_set_args(command);
    cr_assert_eq(command->args.argc, 2);
    cr_assert_str_eq(command->args.argv[0], "echo");
    cr_assert_str_eq(command->args.argv[1], "super");
}

Test(parsing_set_cmd_args, malloc_failed)
{
    cmd_t *command = cmd_new();
    bool test_return = false;

    command->input = "echo\t\tsuper";
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_FAIL);
    test_return = cmd_set_args(command);
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_NORMAL);
    cr_assert_eq(test_return, false);
}

Test(parsing_set_cmd_args, cmd_is_null)
{
    cmd_t *command = cmd_new();
    bool test_return = false;

    command->input = NULL;
    test_return = cmd_set_args(command);
    cr_assert_eq(test_return, false);
}

Test(parsing_set_cmd_args, put_space_at_end)
{
    cmd_t *command = cmd_new();
    bool test_return = false;

    command->input = "echo super ";
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_FAIL);
    test_return = cmd_set_args(command);
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_NORMAL);
    cr_assert_eq(test_return, false);
}

Test(cmd_get_args_get_len_input_string, test_int_return)
{
    cr_assert_eq(cmd_set_args_get_len_input_string("test", 0), 4);
}
