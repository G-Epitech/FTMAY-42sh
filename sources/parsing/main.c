/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** main
*/

#include "types/inst/defs.h"
#include "types/parsing_utils/parsing_utils.h"
#include "types/inst/inst.h"

static inst_t *recursivity(parsing_utils_t *utils)
{
    inst_t *instruction = inst_new();
    inst_block_t *actual_block = inst_block_new();
    inst_block_t *child_block = NULL;
    cmd_t *cmd = NULL;
    char *data = utils->input;

    instruction->type = INS_BLOCK;
    while (data[utils->index_parsing] != '\0') {
        if (data[utils->index_parsing] == '(') {
            utils->index_parsing++;
            child_block = recursivity(utils);
            inst_block_append(actual_block, child_block);
        }
        if (data[utils->index_parsing] == ')') {
            utils->index_parsing++;
            return instruction;
        }
    }
    return instruction;
}

inst_t *parsing_get_main_block(char *input)
{
    parsing_utils_t *utils = utils_new(input);
    inst_t *main = NULL;

    main = recursivity(utils);
    utils_free(utils);
    return main;
}
