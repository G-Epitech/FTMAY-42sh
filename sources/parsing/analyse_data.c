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

static int separator_or_pipe(parsing_utils_t *utils, inst_t *instruction,
inst_block_t *block)
{
    char *data = utils->input;

    if (parsing_maybe_separator(utils)) {
        if (parsing_separator_handler(utils, instruction))
            return 1;
        return 2;
    }
    if (data[PARSING_INDEX(utils)] == '|') {
        if (parsing_pipes_handler(utils, block))
            return 1;
        return 2;
    }
    return 0;
}

static bool append_inst(inst_block_t *block, inst_t *instruction)
{
    inst_t *last = NODE_DATA_TO_PTR(block->instructions->last->data, inst_t *);
    bool inst_ios = instruction->ios.input.type == IOT_DEFAULT;
    bool last_ios = last->ios.input.type != IOT_DEFAULT;

    inst_ios = inst_ios && instruction->ios.output.type == IOT_DEFAULT;
    last_ios = last_ios || last->ios.output.type != IOT_DEFAULT;
    if (last->type == INS_NONE) {
        if (inst_ios)
            instruction->ios = last->ios;
        if (!inst_ios && last_ios) {
            write(2, "Ambiguous input redirect.\n", 26);
            return false;
        }
        list_remove(block->instructions, block->instructions->last);
    }
    inst_append(block, instruction);
    return true;
}

static int open_new_block(parsing_utils_t *utils, inst_block_t *block,
inst_t *child)
{
    char *data = utils->input;

    if (data[PARSING_INDEX(utils)] == '(') {
        PARSING_INDEX(utils)++;
        utils->level++;
        child = parsing_recursivity(utils);
        if (child == NULL || !append_inst(block, child))
            return PARSING_ERROR_RECURSIVITY;
        return PARSING_NO_ERROR_RECURSIVITY;
    }
    return PARSING_NO_OPEN_BLOCK;
}

static int handle_space_semicolon(parsing_utils_t *utils, inst_t *instruction)
{
    char *data = utils->input;

    if (data[PARSING_INDEX(utils)] == ' ') {
        PARSING_INDEX(utils)++;
        return PARSING_NO_ERROR_SEPARATOR;
    }
    if (data[PARSING_INDEX(utils)] == ';') {
        PARSING_INDEX(utils)++;
        if (!parsing_break_separator(instruction))
            return PARSING_ERROR_SEPARATOR;
        return PARSING_NO_ERROR_SEPARATOR;
    }
    return PARSING_NO_SPACE_SEMICOLON;
}

bool parsing_analyse_data(parsing_utils_t *utils, inst_block_t *block,
                    inst_t *instruction)
{
    int result = 0;
    inst_t *child = NULL;

    result = open_new_block(utils, block, child);
    if (result != PARSING_NO_OPEN_BLOCK)
        return result == PARSING_NO_ERROR_RECURSIVITY;
    if (parsing_maybe_redirection(utils))
        return parsing_redirection_handler(utils, instruction);
    result = separator_or_pipe(utils, instruction, block);
    if (result != 0)
        return result == 1;
    result = handle_space_semicolon(utils, instruction);
    if (result != PARSING_NO_SPACE_SEMICOLON)
        return result == PARSING_NO_ERROR_SEPARATOR;
    child = parsing_get_cmd(utils);
    if (!child)
        return false;
    return append_inst(block, child);
}
