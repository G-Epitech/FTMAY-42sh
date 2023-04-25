/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** append
*/

#include "types/list/list.h"
#include "types/node/node.h"
#include "types/inst/defs.h"

void inst_block_append(inst_block_t *inst_block, inst_t *instruction)
{
    node_t *node = node_new(NODE_DATA_FROM_PTR(instruction));

    if (inst_block && inst_block->instructions && node)
        list_append(inst_block->instructions, node);
}
