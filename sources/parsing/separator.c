/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** separator
*/

#include <unistd.h>
#include "types/inst/inst.h"
#include "types/parsing_utils/parsing_utils.h"

void set_separator(inst_t *instruction, int separator)
{
    if (separator == 0)
        instruction->separator = SP_OR;
    else if (separator == 1)
        instruction->separator = SP_AND;
}

bool check_error(inst_t *instruction)
{
    if (instruction->separator == SP_OR)
        return false;
    if (instruction->separator == SP_AND)
        return false;
    return true;
}

bool parsing_separator_handler(parsing_utils_t *utils, inst_t *instruction)
{
    char *separator[2] = {"||", "&&"};
    char *data = utils->input + utils->index_parsing;
    int index = 0;

    for (int i = 0; i < 2; i++) {
        if (strncmp(separator[i], data, strlen(separator[i])) == 0) {
            index = i;
            utils->index_parsing += strlen(separator[i]);
            break;
        }
    }
    if (!check_error(instruction)) {
        write(1, "Invalid null command.\n", 23);
        return false;
    }
    set_separator(instruction, index);
}
