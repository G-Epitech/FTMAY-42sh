/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** get_len
*/

#include <stdlib.h>
#include <stdbool.h>
#include "parsing/defs.h"

int cmd_set_args_get_len_input_string(char *input, int start)
{
    int i = 0;

    while (input[i + start] != '\0') {
        if (input[i + start] == PARSING_STRING)
            return i;
        if (input[i + start] == PARSING_BACKSLASH) {
            start++;
            continue;
        }
        i++;
    }
    return i;
}

int cmd_set_args_get_len_input(char *input, int start)
{
    int i = 0;

    while (input[i + start] != '\0') {
        if (input[i + start] == PARSING_SPACE ||
        input[i + start] == PARSING_TAB) {
            return i;
        }
        if (input[i + start] == PARSING_BACKSLASH) {
            start++;
            continue;
        }
        i++;
    }
    return i;
}
