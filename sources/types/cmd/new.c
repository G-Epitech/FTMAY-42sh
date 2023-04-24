/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** new
*/

#include <stdlib.h>
#include "types/cmd/defs.h"

cmd_t *cmd_new(void)
{
    cmd_t *command = malloc(sizeof(cmd_t));
    args_t cmd_args = { 0 };
    target_t cmd_target = { 0 };

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
