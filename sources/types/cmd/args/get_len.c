/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** get_len
*/

#include <stdlib.h>
#include "parsing/defs.h"

int cmd_set_args_get_len_input_string(char *input, int start)
{
    size_t i = 0;

    while (input[i + start] != '\0') {
        if (input[i + start] == PARSING_STRING)
            return i;
        i++;
    }
    return i;
}

int cmd_set_args_get_len_input(char *input, int start)
{
    size_t i = 0;

    while (input[i + start] != '\0') {
        if (input[i + start] == PARSING_SPACE ||
        input[i + start] == PARSING_TAB) {
            return i;
        }
        i++;
    }
    return i;
}
