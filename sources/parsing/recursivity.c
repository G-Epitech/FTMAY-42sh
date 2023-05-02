/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** recursivity
*/

#include <stdio.h>
#include "parsing/utils.h"
#include "types/list/list.h"
#include "types/inst/inst.h"
#include "parsing/parsing.h"
#include "types/parsing_utils/parsing_utils.h"

static void set_block(inst_t *instruction, inst_block_t *block)
{
    inst_t *pending = inst_new();

    inst_append(block, pending);
    instruction->type = INS_BLOCK;
    instruction->value.block = block;
}

static bool close_block(parsing_utils_t *utils,
inst_t *instruction, inst_block_t *block)
{
    char *data = utils->input;

    if (data[INDEX_PARSING(utils)] == ')') {
        instruction->value.block = block;
        INDEX_PARSING(utils)++;
        return false;
    }
    return true;
}

inst_t *recursivity(parsing_utils_t *utils)
{
    inst_t *instruction = inst_new();
    inst_t *last = NULL;
    inst_block_t *block = inst_block_new();

    set_block(instruction, block);
    while (USER_INPUT(utils)[INDEX_PARSING(utils)] != '\0') {
        if (!close_block(utils, instruction, block))
            return instruction;
        last = NODE_DATA_TO_PTR(block->instructions->last->data, inst_t *);
        if (!analyse_data(utils, block, last))
            return NULL;
    }
    if (!parsing_break_separator(instruction))
        return NULL;
    return instruction;
}
