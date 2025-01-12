/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** free
*/

#include <stdlib.h>
#include "types/cmd/cmd.h"
#include "types/inst/inst.h"

void inst_free(inst_t *inst)
{
    if (!inst)
        return;
    if (inst->type == INS_CMD)
        cmd_free(inst->value.cmd);
    if (inst->type == INS_BLOCK)
        inst_block_free(inst->value.block);
    free(inst);
}

void inst_node_freer(node_data_t data)
{
    inst_t *inst = NODE_DATA_TO_PTR(data, inst_t *);

    inst_free(inst);
}
