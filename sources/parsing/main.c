/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** main
*/

#include "parsing/utils.h"
#include "types/list/list.h"
#include "types/inst/inst.h"
#include "parsing/parsing.h"
#include "types/parsing_utils/parsing_utils.h"

static void append_inst(inst_block_t *block, inst_t *instruction)
{
    inst_t *data = NODE_DATA_TO_PTR(block->instructions->last->data, inst_t *);

    if (data->type == INS_NONE) {
        instruction->ios = data->ios;
        list_remove(block->instructions, block->instructions->last);
    }
    inst_append(block, instruction);
}

static void analyse_data(parsing_utils_t *utils, inst_block_t *actual_block,
                        inst_t *instruction)
{
    char *data = utils->input;
    inst_t *child = NULL;

    if (data[utils->index_parsing] == '(') {
        utils->index_parsing++;
        child = recursivity(utils);
        append_inst(actual_block, child);
        return;
    }
    if (maybe_redirection(utils))
        return parsing_redirection_handler(utils, instruction);
    utils->index_parsing++;
}

inst_t *recursivity(parsing_utils_t *utils)
{
    inst_t *instruction = inst_new();
    inst_block_t *actual_block = inst_block_new();
    inst_t *pending = inst_new();
    char *data = utils->input;

    inst_append(actual_block, pending);
    instruction->type = INS_BLOCK;
    while (data[utils->index_parsing] != '\0') {
        if (data[utils->index_parsing] == ')') {
            instruction->value.block = actual_block;
            utils->index_parsing++;
            return instruction;
        }
        analyse_data(utils, actual_block, instruction);
    }
    instruction->value.block = actual_block;
    return instruction;
}

inst_t *parsing_get_main_block(char *input)
{
    parsing_utils_t *utils = parsing_utils_new(input);
    inst_t *main = NULL;

    main = recursivity(utils);
    parsing_utils_free(utils);
    return main;
}
