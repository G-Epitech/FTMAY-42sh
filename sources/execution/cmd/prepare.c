/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** cmd
*/

#include <stdio.h>
#include "types/cmd/cmd.h"
#include "parsing/utils.h"
#include "errors/errors.h"
#include "execution/defs.h"
#include "types/node/defs.h"
#include "types/inst/inst.h"
#include "execution/execution.h"

static bool init_execution(inst_t *inst, cmd_t **cmd)
{
    if (!inst)
        return false;
    if (inst->type != INS_CMD)
        return false;
    *cmd = inst->value.cmd;
    if (!(*cmd))
        return false;
    return true;
}

bool execution_cmd_prepare(node_t *node_inst, shell_t *shell)
{
    inst_t *inst = EXECUTION_GET_INST(node_inst);
    cmd_t *cmd = NULL;

    if (!init_execution(inst, &cmd))
        return false;
    if (!cmd_set_args(cmd))
        return false;
    if (!cmd_determine_target(cmd, shell)) {
        execution_cmd_display_error(cmd, ENOENT);
        return false;
    }
    if (!execution_cmd_can_be_done(cmd))
        return false;
    return true;
}
