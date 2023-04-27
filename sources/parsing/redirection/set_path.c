/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** parsing
*/

#include <stdio.h>
#include <string.h>
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

void set_path(parsing_utils_t *utils, inst_t *instruction)
{
    char *data = utils->input;
    int index = 0;

    while (data[INDEX_PARSING(utils)] == ' ' || data[INDEX_PARSING(utils)] == '\t')
        INDEX_PARSING(utils)++;
    index = utils->index_parsing;
    while (maybe_path(utils))
        utils->index_parsing++;
    printf("index_utils : [%i]\n", utils->index_parsing);
    printf("file : [%s]\n", parsing_get_word(utils, index, utils->index_parsing));
    (void) instruction;
}
