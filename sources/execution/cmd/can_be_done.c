/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** can_be_done
*/

#include <errno.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/stat.h>
#include "utils/utils.h"
#include "types/cmd/cmd.h"
#include "types/shell/defs.h"
#include "execution/execution.h"

static bool check_target(cmd_t *cmd)
{
    char *target = cmd->target.path;
    struct stat check;

    if (!target) {
        execution_cmd_display_error(cmd, ENOENT);
        return false;
    }
    if (stat(target, &check) != 0) {
        execution_cmd_display_error(cmd, errno);
        return false;
    }
    if (!STAT_MODE_XOK(check.st_mode)) {
        execution_cmd_display_error(cmd, EACCES);
        return false;
    }
    return true;
}

bool execution_cmd_can_be_done(cmd_t *cmd)
{
    if (!cmd)
        return false;
    if (cmd->type == CMD_EMPTY || cmd->type == CMD_BUILTIN)
        return true;
    if (cmd->type != CMD_SYSTEM && cmd->type != CMD_ABSOLUTE)
        return false;
    return check_target(cmd);
}
