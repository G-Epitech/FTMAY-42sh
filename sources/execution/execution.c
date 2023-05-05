/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** execution
*/

#include "types/inst/defs.h"
#include "types/node/defs.h"
#include "execution/execution.h"

void execution_inst(node_t *node, int fd[2], int level)
{
    inst_t *instruction = NODE_DATA_TO_PTR(node->data, inst_t *);

    (void)fd;
    if (instruction->type == INS_BLOCK)
        execution_block(node, level + 1);
}
