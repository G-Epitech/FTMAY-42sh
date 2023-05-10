/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** pipes
*/

#include <stdio.h>
#include <unistd.h>
#include "types/inst/inst.h"
#include "types/parsing_utils/parsing_utils.h"

static bool check_errors(inst_t *last)
{
    if (last->type == INS_NONE) {
        fprintf(stderr, "Invalid null command.\n");
        return false;
    }
    if (last->ios.output.type != IOT_DEFAULT) {
        fprintf(stderr, "Ambiguous output redirect.\n");
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
