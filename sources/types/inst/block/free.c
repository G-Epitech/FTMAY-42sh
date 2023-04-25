/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** free
*/

#include <stdlib.h>
#include "types/inst/inst.h"
#include "types/list/list.h"

void inst_block_free(inst_block_t *inst_block)
{
    if (inst_block)
        list_free(inst_block->instructions, NULL);
    free(inst_block);
}
