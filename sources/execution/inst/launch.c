/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** launch
*/

#include "execution/defs.h"
#include "types/inst/inst.h"
#include "types/shell/shell.h"
#include "execution/execution.h"

void execution_inst_launch_non_fork(node_t *node_inst, shell_t *shell,
exec_utils_t *utils)
{
    execution_cmd_launch(node_inst, shell, utils);
}

void execution_inst_launch(node_t *node_inst, shell_t *shell,
exec_utils_t *utils)
{
    inst_t *inst = EXECUTION_NODE_TO_INST(node_inst);
    bool fork_needed = execution_inst_fork_needed(inst, utils);

    if (fork_needed)
        execution_inst_launch_fork(node_inst, shell, utils);
    else
        execution_inst_launch_non_fork(node_inst, shell, utils);
}
