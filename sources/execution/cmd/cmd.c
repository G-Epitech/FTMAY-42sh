/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** cmd
*/

#include <stdio.h>
#include "types/cmd/cmd.h"
#include "parsing/utils.h"
#include "execution/defs.h"
#include "types/node/defs.h"
#include "types/inst/inst.h"

static bool init_execution(inst_t *inst, cmd_t **cmd)
{
    if (!inst)
        return false;
    if (inst->type != INS_CMD)
        return false;
    *cmd = inst->value.cmd;
    if (!cmd)
        return false;
    return true;
}

int execution_cmd(node_t *node_inst, shell_t *shell)
{
    inst_t *inst = EXECUTION_GET_INST(node_inst);
    cmd_t *cmd = NULL;

    if (!init_execution(inst, &cmd))
        return EXECUTION_ERROR;
    parsing_set_command_args(cmd, shell);
    cmd_determine_target(cmd, shell);
    cmd_display(cmd);
    parsing_display(inst);
    return 0;
}
