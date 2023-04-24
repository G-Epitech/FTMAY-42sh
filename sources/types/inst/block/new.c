/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** new
*/

#include <stdlib.h>
#include "types/inst/defs.h"

inst_block_t *inst_block_new(void)
{
    inst_block_t *inst_block = malloc(sizeof(inst_block_t));

    if (!inst_block)
        return NULL;
    inst_block->instructions = NULL;
    return inst_block;
}
