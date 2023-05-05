/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** execution
*/

#include "types/inst/inst.h"
#include "types/shell/shell.h"

void execution_inst(node_t *node_inst, shell_t *shell, int level)
{
    inst_t *inst = EXECUTION_GET_INST(node_inst);

    if (!inst)
        shell->exit_code = SHELL_EXIT_ERROR;
    if (inst->type == INS_BLOCK)
        (void) 1; //EXEC BLOCK
    else if (inst->type == INS_CMD)
        (void) 1; //EXEC CMD
    else
        shell->exit_code = SHELL_EXIT_ERROR;
}
