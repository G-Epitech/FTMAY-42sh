/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** main
*/

#include <stdio.h>
#include "parsing/utils.h"
#include "types/list/list.h"
#include "types/inst/inst.h"
#include "parsing/parsing.h"
#include "types/parsing_utils/parsing_utils.h"

static bool append_inst(inst_block_t *block, inst_t *instruction)
{
    inst_t *data = NODE_DATA_TO_PTR(block->instructions->last->data, inst_t *);

    if (data->type == INS_NONE) {
        instruction->ios = data->ios;
        list_remove(block->instructions, block->instructions->last);
    }
    inst_append(block, instruction);
    return true;
}

static bool separator_or_pipe(parsing_utils_t *utils, inst_t *instruction,
inst_block_t *block)
{
    char *data = utils->input;

    if (parsing_maybe_separator(utils)) {
        return parsing_separator_handler(utils, instruction);
    } else if (data[INDEX_PARSING(utils)] == '|')
        return parsing_pipes_handler(utils, block);
    else
        return true;

}

static bool analyse_data(parsing_utils_t *utils, inst_block_t *block,
                        inst_t *instruction)
{
    char *data = utils->input;
    inst_t *child = NULL;

    if (data[INDEX_PARSING(utils)] == '(') {
        INDEX_PARSING(utils)++;
        child = recursivity(utils);
        return append_inst(block, child);
    }
    if (parsing_maybe_redirection(utils))
        return parsing_redirection_handler(utils, instruction);
    if (!separator_or_pipe(utils, instruction, block))
        return false;
    if (data[INDEX_PARSING(utils)] == ' ' ||
        data[INDEX_PARSING(utils)] == ';') {
        INDEX_PARSING(utils)++;
        return true;
    }
    child = parsing_get_cmd(utils);
    append_inst(block, child);
    return true;
}

inst_t *recursivity(parsing_utils_t *utils)
{
    inst_t *instruction = inst_new();
    inst_block_t *block = inst_block_new();
    inst_t *pending = inst_new();
    char *data = utils->input;
    inst_t *last = NULL;

    inst_append(block, pending);
    instruction->type = INS_BLOCK;
    instruction->value.block = block;
    while (data[INDEX_PARSING(utils)] != '\0') {
        if (data[INDEX_PARSING(utils)] == ')') {
            instruction->value.block = block;
            INDEX_PARSING(utils)++;
            return instruction;
        }
        last = NODE_DATA_TO_PTR(block->instructions->last->data, inst_t *);
        if (!analyse_data(utils, block, last))
            return instruction;
    }
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
