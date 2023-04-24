/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** free
*/

#include <stdlib.h>
#include "types/inst/defs.h"

void inst_block_free(inst_block_t *inst_block)
{
    if (!inst_block)
        return;
    free(inst_block);
}
