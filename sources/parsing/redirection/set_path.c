/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** parsing
*/

#include <stdio.h>
#include <string.h>
#include "parsing/utils.h"
#include "types/inst/inst.h"
#include "parsing/parsing.h"
#include "types/parsing_utils/parsing_utils.h"

static bool maybe_redirection(parsing_utils_t *utils)
{
    char *data = utils->input;
    int index = utils->index_parsing;

    if (data[index] == '>')
        return true;
    if (data[index] == '<')
        return true;
    return false;
}

static bool maybe_path(parsing_utils_t *utils)
{
    char *data = utils->input;
    int index = utils->index_parsing;

    if (data[index] == '\0' || data[index] == ' ')
        return false;
    if (data[index] == '(' || data[index] == ')')
        return false;
    if (data[index] == ';' || data[index] == '|')
        return false;
    if (maybe_redirection(utils))
        return false;
    return true;
}

void parsing_redirection_set_path(parsing_utils_t *utils, inst_t *instruction,
int index_redirection)
{
    char *data = utils->input;
    char *path = NULL;
    int index = 0;

    while (data[PARSING_INDEX(utils)] == ' ' ||
    data[PARSING_INDEX(utils)] == '\t') {
        PARSING_INDEX(utils)++;
    }
    index = utils->index_parsing;
    while (maybe_path(utils))
        utils->index_parsing++;
    path = parsing_get_word(utils, index, utils->index_parsing);
    if (index_redirection <= 1)
        instruction->ios.input.path = path;
    else
        instruction->ios.output.path = path;
}
