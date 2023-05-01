/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** new
*/

#include <stdlib.h>
#include "types/inst/defs.h"

inst_t *inst_new(void)
{
    inst_t *instruction = malloc(sizeof(inst_t));
    io_t empty_io = {NULL, IOT_DEFAULT};

    if (!instruction)
        return NULL;
    instruction->value.cmd = NULL;
    instruction->value.block = NULL;
    instruction->type = INS_NONE;
    instruction->separator = SP_BREAK;
    instruction->exit_code = 0;
    instruction->ios.input = empty_io;
    instruction->ios.output = empty_io;
    return instruction;
}
