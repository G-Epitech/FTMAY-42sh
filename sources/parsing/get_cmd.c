/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** get_cmd
*/

#include <stdio.h>
#include <string.h>
#include "parsing/parsing.h"

static bool maybe_redirection(parsing_utils_t *utils)
{
    char *redirection[4] = {"<", "<<", ">>", ">"};

    for (int i = 0; i < 4; i++) {
        if (strncmp(redirection[i], utils->input, strlen(redirection[i])) == 0) {
            return true;
        }
    }
    return false;
}

static bool maybe_cmd(parsing_utils_t *utils)
{
    char *data = utils->input;
    int index= utils->index_parsing;

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

static void manage_cmd(parsing_utils_t *utils, int *index)
{
    char *data = utils->input;

    if (data[utils->index_parsing + 1] == '\0')
        utils->index_parsing++;
    printf("Word: %s\n", parsing_get_word(utils, *index, utils->index_parsing));
    *index = utils->index_parsing + 1;
}

void parsing_get_cmd(parsing_utils_t *utils, cmd_t *cmd)
{
    int index = utils->index_parsing;
    char *data = utils->input;

    (void)cmd;
    while (maybe_cmd(utils)) {
        if (data[utils->index_parsing] == ' ' || data[utils->index_parsing + 1] == '\0') {
            manage_cmd(utils, &index);
        }
        utils->index_parsing++;
    }
}
