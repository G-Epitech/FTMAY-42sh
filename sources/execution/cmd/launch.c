/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** launch
*/

#include "types/cmd/cmd.h"
#include "parsing/utils.h"
#include "execution/defs.h"
#include "types/node/defs.h"
#include "types/inst/inst.h"
#include "execution/execution.h"

bool execution_cmd_launch(node_t *node_inst, shell_t *shell,
exec_utils_t *utils)
{
    cmd_t *cmd = EXECUTION_NODE_TO_INST(node_inst)->value.cmd;

    if (cmd->type == CMD_ABSOLUTE || cmd->type == CMD_SYSTEM)
        execution_cmd_launch_absolute(cmd);
    else
        utils->status = execution_cmd_launch_builtin(cmd, shell);
    return (utils->status == 0);
}
