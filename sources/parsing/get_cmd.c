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
#include "utils/malloc2.h"

static void append_cmd(cmd_t *command, char *data)
{
    char *total = NULL;
    int size = 0;

    if (command->input) {
        size = strlen(command->input) + strlen(data) + 3;
        total = malloc2(sizeof(char) * (size));
        if (!total)
            return;
        memset(total, '\0', size);
        strcpy(total, command->input);
        strcat(total, " ");
        strcat(total, data);
        command->input = total;
    } else {
        command->input = data;
    }
}

static int maybe_cmd(parsing_utils_t *utils, inst_t *instruction,
int *index_start, cmd_t *command)
{
    char *data = utils->input;
    char *word = NULL;
    int index = utils->index_parsing;

    if (parsing_maybe_redirection(utils)) {
        word = parsing_get_word(utils, *index_start, utils->index_parsing);
        append_cmd(command, word);
        if (!parsing_redirection_handler(utils, instruction))
            return PARSING_ERROR_CMD;
        *index_start = utils->index_parsing;
        index = utils->index_parsing;
    }
    if (data[index] == '\0')
        return PARSING_STOP_CMD;
    if (data[index] == '(' || data[index] == ')')
        return PARSING_STOP_CMD;
    if (data[index] == ';' || data[index] == '|')
        return PARSING_STOP_CMD;
    return PARSING_NO_ERROR_CMD;
}

inst_t *parsing_get_cmd(parsing_utils_t *utils)
{
    int index = utils->index_parsing;
    inst_t *instruction = inst_new();
    cmd_t *command = cmd_new();
    char *data = NULL;
    int running = 0;

    while (running == PARSING_NO_ERROR_CMD) {
        PARSING_INDEX(utils)++;
        running = maybe_cmd(utils, instruction, &index, command);
    }
    if (running == PARSING_ERROR_CMD)
        return NULL;
    data = parsing_get_word(utils, index, utils->index_parsing);
    if (!data || !instruction || !command)
        return NULL;
    append_cmd(command, data);
    instruction->type = INS_CMD;
    instruction->value.cmd = command;
    return instruction;
}
