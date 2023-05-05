/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** target
*/

#include <string.h>
#include "types/cmd/cmd.h"

bool cmd_determine_target_is_empty(cmd_t *cmd)
{
    if (!cmd)
        return false;
    if (!cmd->name)
        return false;
    if (strlen(cmd->name) <= 0) {
        cmd->type = CMD_EMPTY;
        return true;
    }
    return false;
}
