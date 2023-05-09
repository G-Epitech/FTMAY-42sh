/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** execution
*/

#include "execution/defs.h"
#include "types/inst/inst.h"
#include "types/shell/shell.h"
#include "execution/execution.h"

void execution_inst_previous_piped(node_t *node_inst,
shell_t *shell, exec_utils_t *utils)
{
    inst_t *inst = EXECUTION_NODE_TO_INST(node_inst);
    inst_t *prev = EXECUTION_GET_INST(node_inst->prev);

    if (!prev)
        return;
    if (inst->ios.input.type == IOT_PIPED)
        execution_inst(node_inst->prev, shell, utils, EXEC_SIBLING);
}
