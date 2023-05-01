/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** get_cmd
*/

#include <stdio.h>
#include <string.h>
#include "types/cmd/cmd.h"
#include "parsing/parsing.h"
#include "types/inst/inst.h"
#include "parsing/utils.h"

static bool maybe_cmd(parsing_utils_t *utils)
{
    char *data = utils->input;
    int index = utils->index_parsing;

    if (data[index] == '\0')
        return false;
    if (data[index] == '(' || data[index] == ')')
        return false;
    if (data[index] == ';' || data[index] == '|')
        return false;
    if (maybe_redirection(utils))
        return false;
    return true;
}

static char *manage_cmd(parsing_utils_t *utils, int *index)
{
    char *data = utils->input;

    if (data[utils->index_parsing + 1] == '\0')
        utils->index_parsing++;
    return parsing_get_word(utils, *index, utils->index_parsing);
}

inst_t *parsing_get_cmd(parsing_utils_t *utils)
{
    int index = utils->index_parsing;
    inst_t *instruction = inst_new();
    cmd_t *command = cmd_new();
    char *data = NULL;

    while (maybe_cmd(utils)) {
        utils->index_parsing++;
    }
    data = manage_cmd(utils, &index);
    if (!data || !instruction || !command)
        return NULL;
    command->input = data;
    instruction->type = INS_CMD;
    instruction->value.cmd = command;
    return instruction;
}
