/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** get_cmd
*/

#include <stdio.h>
#include <string.h>
#include "types/cmd/cmd.h"
#include "parsing/utils.h"
#include "parsing/parsing.h"
#include "types/inst/inst.h"

static bool maybe_cmd(parsing_utils_t *utils, inst_t *instruction)
{
    char *data = utils->input;
    int index = utils->index_parsing;

    (void)instruction;
    if (data[index] == '\0')
        return false;
    if (data[index] == '(' || data[index] == ')')
        return false;
    if (data[index] == ';' || data[index] == '|')
        return false;
    if (parsing_maybe_redirection(utils))
        return false;
    return true;
}

static char *manage_cmd(parsing_utils_t *utils, int index)
{
    char *data = utils->input;

    if (data[utils->index_parsing + 1] == '\0')
        utils->index_parsing++;
    return parsing_get_word(utils, index, utils->index_parsing);
}

inst_t *parsing_get_cmd(parsing_utils_t *utils)
{
    int index = utils->index_parsing;
    inst_t *instruction = inst_new();
    cmd_t *command = cmd_new();
    char *data = NULL;

    if (!utils)
        return NULL;
    while (maybe_cmd(utils, instruction)) {
        PARSING_INDEX(utils)++;
    }
    data = manage_cmd(utils, index);
    if (!data || !instruction || !command)
        return NULL;
    command->input = data;
    instruction->type = INS_CMD;
    instruction->value.cmd = command;
    return instruction;
}
