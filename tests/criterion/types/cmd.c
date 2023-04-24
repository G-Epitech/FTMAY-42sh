/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** cmd
*/

#include <string.h>
#include <criterion/criterion.h>
#include "types/cmd/cmd.h"

Test(types_cmd, new_cmd)
{
    cmd_t *command = cmd_new();

    cr_assert(command != NULL);
}

Test(types_cmd, new_field_cmd)
{
    cmd_t *command = cmd_new();

    cr_assert(command->input == NULL);
    cr_assert(command->name == NULL);
    cr_assert(command->type == CMD_NULL);
    cr_assert(command->target.path == NULL);
    cr_assert(command->target.builtin == NULL);
    cr_assert(command->args.argv == NULL);
    cr_assert(command->args.argc == 0);
    cr_assert(command->forked == false);
    cr_assert(command != NULL);
}

Test(types_cmd, free_cmd)
{
    cmd_t *command = cmd_new();

    command->name = strdup("ls");
    command->input = strdup("ls -la");
    cmd_free(command);
}

Test(types_cmd, free_null_cmd)
{
    cmd_free(NULL);
}
