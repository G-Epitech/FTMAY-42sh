/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** append
*/

#include <stdio.h>
#include "types/inst/inst.h"
#include "types/list/list.h"

static bool check_ambiguous(inst_block_t *block, inst_t *instruction)
{
    inst_t *last = NODE_DATA_TO_PTR(block->instructions->last->data, inst_t *);
    bool inst_ios_in = instruction->ios.input.type != IOT_DEFAULT;
    bool last_ios_in = last->ios.input.type != IOT_DEFAULT;
    bool inst_ios_out = instruction->ios.output.type != IOT_DEFAULT;
    bool last_ios_out = last->ios.output.type != IOT_DEFAULT;

    if (!inst_ios_in && last_ios_in)
        instruction->ios.input = last->ios.input;
    if (!inst_ios_out && last_ios_out)
        instruction->ios.output = last->ios.output;
    if (inst_ios_in && last_ios_in) {
        fprintf(stderr, "Ambiguous input redirect.\n");
        return false;
    }
    if (inst_ios_out && last_ios_out) {
        fprintf(stderr, "Ambiguous output redirect.\n");
        return false;
    }
    return true;
}

bool parsing_append_inst(inst_block_t *block, inst_t *instruction)
{
    inst_t *last = NODE_DATA_TO_PTR(block->instructions->last->data, inst_t *);

    if (last->type == INS_NONE) {
        if (!check_ambiguous(block, instruction))
            return false;
        list_remove(block->instructions, block->instructions->last);
    }
    inst_append(block, instruction);
    return true;
}
