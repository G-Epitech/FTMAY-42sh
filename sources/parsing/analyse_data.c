/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** analyse_data
*/

#include <stdio.h>
#include "parsing/utils.h"
#include "types/list/list.h"
#include "types/inst/inst.h"
#include "parsing/parsing.h"
#include "types/parsing_utils/parsing_utils.h"

static bool separator_or_pipe(parsing_utils_t *utils, inst_t *instruction,
inst_block_t *block)
{
    char *data = utils->input;
    bool test_return = false;

    if (parsing_maybe_separator(utils)) {
        test_return = parsing_separator_handler(utils, instruction);
        INDEX_PARSING(utils)+= 2;
        return test_return;
    } else if (data[INDEX_PARSING(utils)] == '|') {
        return parsing_pipes_handler(utils, block);
    } else {
        return true;
    }

}

static void append_inst(inst_block_t *block, inst_t *instruction)
{
    inst_t *data = NODE_DATA_TO_PTR(block->instructions->last->data, inst_t *);

    if (data->type == INS_NONE) {
        instruction->ios = data->ios;
        list_remove(block->instructions, block->instructions->last);
    }
    inst_append(block, instruction);
}

static int open_new_block(parsing_utils_t *utils, inst_block_t *block,
inst_t *child)
{
    char *data = utils->input;

    if (data[INDEX_PARSING(utils)] == '(') {
        INDEX_PARSING(utils)++;
        child = recursivity(utils);
        if (child == NULL)
            return PARSING_ERROR_RECURSIVITY;
        append_inst(block, child);
        return PARSING_NO_ERROR_RECURSIVITY;
    }
    return PARSING_NO_OPEN_BLOCK;
}

static int handle_space_semicolon(parsing_utils_t *utils, inst_t *instruction)
{
    char *data = utils->input;

    if (data[INDEX_PARSING(utils)] == ' ') {
        INDEX_PARSING(utils)++;
        return PARSING_NO_ERROR_SEPARATOR;
    }
    if (data[INDEX_PARSING(utils)] == ';') {
        INDEX_PARSING(utils)++;
        if (!parsing_break_separator(instruction))
            return PARSING_ERROR_SEPARATOR;
        return PARSING_NO_ERROR_SEPARATOR;
    }
    return PARSING_NO_SPACE_SEMICOLON;
}

bool analyse_data(parsing_utils_t *utils, inst_block_t *block,
                    inst_t *instruction)
{
    int result_new_block = 0;
    int result_space_semicolon = 0;
    inst_t *child = NULL;

    result_new_block = open_new_block(utils, block, child);
    if (result_new_block != PARSING_NO_OPEN_BLOCK)
        return result_new_block == PARSING_NO_ERROR_RECURSIVITY;
    if (parsing_maybe_redirection(utils))
        return parsing_redirection_handler(utils, instruction);
    if (!separator_or_pipe(utils, instruction, block))
        return false;
    result_space_semicolon = handle_space_semicolon(utils, instruction);
    if (result_space_semicolon != PARSING_NO_SPACE_SEMICOLON)
        return result_space_semicolon == PARSING_NO_ERROR_SEPARATOR;
    child = parsing_get_cmd(utils);
    append_inst(block, child);
    return true;
}
