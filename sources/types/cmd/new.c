/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** new
*/

#include <stdlib.h>
#include "utils/malloc2.h"
#include "types/cmd/defs.h"

cmd_t *cmd_new(void)
{
    cmd_t *command = malloc2(sizeof(cmd_t));
    args_t cmd_args = {NULL, 0};
    target_t cmd_target = {NULL};

    if (!command)
        return NULL;
    command->input = NULL;
    command->name = NULL;
    command->type = CMD_NULL;
    command->target = cmd_target;
    command->args = cmd_args;
    command->forked = false;
    return command;
}
