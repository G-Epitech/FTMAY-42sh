/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** cmd
*/

#include <string.h>
#include <criterion/criterion.h>
#include "utils/malloc2.h"
#include "builtins/defs.h"
#include "types/cmd/cmd.h"
#include "types/shell/shell.h"

Test(types_cmd, new_cmd)
{
    cmd_t *command = cmd_new();

    cr_assert(command != NULL);
    cmd_free(command);
}

Test(types_cmd, new_cmd_with_malloc_fail)
{   
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_FAIL);
    cr_assert_null(cmd_new());
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_NORMAL);
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
    cmd_free(command);
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
