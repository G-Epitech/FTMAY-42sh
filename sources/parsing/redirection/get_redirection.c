/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** parsing
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "parsing/parsing.h"
#include "types/inst/inst.h"
#include "types/parsing_utils/parsing_utils.h"

static bool check_ambiguous(inst_t *instruction, int index,
parsing_utils_t *utils)
{
    bool right = index == PARSING_SIMPLE_RIGHT || index == PARSING_DOUBLE_RIGHT;
    bool left = index == PARSING_SIMPLE_LEFT || index == PARSING_DOUBLE_LEFT;

    if (index == PARSING_DOUBLE_LEFT && utils->level != 0) {
        write(2, "Can't << within ()'s.\n", 23);
        return false;
    }
    if (instruction->ios.input.type != IOT_DEFAULT && left) {
        write(2, "Ambiguous input redirect.\n", 26);
        return false;
    }
    if (instruction->ios.output.type != IOT_DEFAULT && right) {
        write(2, "Ambiguous output redirect.\n", 27);
        return false;
    }
    return true;
}

static bool check_name(inst_t *instruction, int index)
{
    if ((index <= 1 && instruction->ios.input.path[0] == '\0') ||
        (index >= 2 && instruction->ios.output.path[0] == '\0')) {
        write(2, "Missing name for redirect.\n", 27);
        return false;
    }
    return true;
}

bool parsing_redirection_handler(parsing_utils_t *utils, inst_t *instruction)
{
    char *redirections[4] = {"<<", "<", ">>", ">"};
    char *data = utils->input + utils->index_parsing;
    int index = 0;

    if (!instruction)
        return false;
    for (int i = 0; i < 4; i++) {
        if (strncmp(redirections[i], data, strlen(redirections[i])) == 0) {
            index = i;
            utils->index_parsing += strlen(redirections[i]);
            break;
        }
    }
    if (!check_ambiguous(instruction, index, utils))
        return false;
    parsing_redirection_set_type(index, instruction);
    parsing_redirection_set_path(utils, instruction, index);
    return check_name(instruction, index);
}
