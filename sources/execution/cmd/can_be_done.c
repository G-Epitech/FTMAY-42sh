/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** can_be_done
*/

#include <errno.h>
#include <unistd.h>
#include <stdbool.h>
#include "types/cmd/cmd.h"

static int check_target(char *target)
{
    if (!target)
        return ENOENT;
    return access(target, X_OK) == 0 ? 0 : errno;
}

static int get_status(cmd_t *cmd)
{
    if (cmd->type == CMD_EMPTY || cmd->type == CMD_BUILTIN)
        return 0;
    else if (cmd->type != CMD_SYSTEM && cmd->type != CMD_ABSOLUTE)
        return ENOENT;
    else
        return check_target(cmd->target);
}

bool execution_cmd_can_be_done(cmd_t *cmd, int *status)
{
    if (!status)
        return false;
    *status = get_status(cmd);
    return (*status == 0);
}
