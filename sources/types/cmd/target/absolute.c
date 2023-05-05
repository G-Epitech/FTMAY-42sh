/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** target
*/

#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "types/cmd/cmd.h"

static bool is_absolute(char *path)
{
    struct stat target;

    if (!path)
        return false;
    return (stat(path, &target) == 0);
}

bool cmd_determine_target_is_absolute(cmd_t *cmd)
{
    if (!is_absolute(cmd->name))
        return false;
    cmd->target.path = strdup(cmd->name);
    cmd->type = CMD_ABSOLUTE;
    return true;
}
