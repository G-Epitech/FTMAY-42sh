/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** pipes
*/

#include <stdio.h>
#include <unistd.h>
#include "types/inst/inst.h"
#include "parsing/parsing.h"
#include "types/parsing_utils/parsing_utils.h"

static bool check_errors(inst_t *last)
{
    if (last->type == INS_NONE) {
        fprintf(stderr, "Invalid null command.\n");
        return false;
    }
    if (last->ios.output.type != IOT_DEFAULT) {
        write(2, "Ambiguous output redirect.\n", 27);
        return false;
    }
    return true;
}

bool parsing_pipes_handler(parsing_utils_t *utils, inst_block_t *block)
{
    inst_t *last = NULL;
    inst_t *new = NULL;

    if (!block->instructions->last)
        return false;
    last = NODE_DATA_TO_PTR(block->instructions->last->data, inst_t *);
    if (!check_errors(last))
        return false;
    last->ios.output.type = IOT_PIPED;
    new = inst_new();
    if (!new)
        return false;
    new->ios.input.type = IOT_PIPED;
    inst_append(block, new);
    utils->index_parsing++;
    return true;
}

bool parsing_last_inst_pipe(inst_t *instruction)
{
    bool input = instruction->ios.input.type != IOT_DEFAULT;
    bool output = instruction->ios.output.type != IOT_DEFAULT;

    if (instruction->type == INS_NONE && (input || output)) {
        fprintf(stderr, "Invalid null command.\n");
        return false;
    }
    (void) instruction;
    return true;
}
