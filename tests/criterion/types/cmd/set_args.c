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
    shell_t *shell = shell_new(builtins_cmds);
    cmd_t *command = cmd_new();

    command->input = strdup("echo \"super HELLO\"");
    cr_assert(cmd_set_args(command, shell));
    cr_assert_eq(command->args.argc, 2);
    cr_assert_str_eq(command->args.argv[0], "echo");
    cr_assert_str_eq(command->args.argv[1], "super HELLO");
}

Test(parsing_set_cmd_args, test_without_innibiteur)
{
    shell_t *shell = shell_new(builtins_cmds);
    cmd_t *command = cmd_new();

    command->input = strdup("echo super");
    cr_assert(cmd_set_args(command, shell));
    cr_assert_eq(command->args.argc, 2);
    cr_assert_str_eq(command->args.argv[0], "echo");
    cr_assert_str_eq(command->args.argv[1], "super");
    shell_free(shell);
    cmd_free(command);
}

Test(parsing_set_cmd_args, test_without_innibiteur_separed_by_space)
{
    shell_t *shell = shell_new(builtins_cmds);
    cmd_t *command = cmd_new();

    command->input = strdup("echo\t\tsuper");
    cr_assert(cmd_set_args(command, shell));
    cr_assert_eq(command->args.argc, 2);
    cr_assert_str_eq(command->args.argv[0], "echo");
    cr_assert_str_eq(command->args.argv[1], "super");
    shell_free(shell);
    cmd_free(command);
}

Test(parsing_set_cmd_args, malloc_failed)
{
    shell_t *shell = shell_new(builtins_cmds);
    cmd_t *command = cmd_new();

    command->input = strdup("echo\t\tsuper");
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_FAIL);
    cr_assert_not(cmd_set_args(command, shell));
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_NORMAL);
    shell_free(shell);
    cmd_free(command);
}

Test(parsing_set_cmd_args, cmd_is_null)
{
    shell_t *shell = shell_new(builtins_cmds);
    cmd_t *command = cmd_new();

    command->input = NULL;
    cr_assert_not(cmd_set_args(command, shell));
    shell_free(shell);
    cmd_free(command);
}

Test(parsing_set_cmd_args, put_space_at_end)
{
    shell_t *shell = shell_new(builtins_cmds);
    cmd_t *command = cmd_new();

    command->input = strdup("echo super ");
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_FAIL);
    cr_assert_not(cmd_set_args(command, shell));
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_NORMAL);
    shell_free(shell);
    cmd_free(command);
}

Test(cmd_get_args_get_len_input_string, test_int_return)
{
    cr_assert_eq(cmd_set_args_get_len_input_string("test", 0), 4);
}
