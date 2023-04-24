/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** append
*/

#include "types/list/list.h"
#include "types/node/node.h"
#include "types/inst/defs.h"

void inst_block_append_block(inst_block_t *inst_block, inst_block_t *sub_block)
{
    node_t *node = node_new(NODE_DATA_FROM_PTR(sub_block));

    list_append(inst_block->instructions, node);
}

void inst_block_append_cmd(inst_block_t *inst_block, cmd_t *cmd)
{
    node_t *node = node_new(NODE_DATA_FROM_PTR(cmd));

    list_append(inst_block->instructions, node);
}
