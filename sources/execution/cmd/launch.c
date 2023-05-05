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

bool execution_cmd_launch(node_t *node_inst, int *status)
{
    inst_t *inst = EXECUTION_GET_INST(node_inst);
    cmd_t *cmd = inst->value.cmd;

    if (!execution_cmd_can_be_done(cmd, status))
        return false;
    if (cmd->type == CMD_ABSOLUTE || cmd->type == CMD_SYSTEM)
        *status = execution_cmd_absolute(cmd);
    else
        *status = execution_cmd_builtin(cmd);
    return (*status == 0);
}
