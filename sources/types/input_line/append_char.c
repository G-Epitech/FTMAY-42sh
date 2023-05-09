/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** iscntrl
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "types/input_line/input_line.h"

bool append_char(input_line_t *line, int c)
{
    char *user_input = line->buffer->content;

    char *new_input = realloc(user_input, sizeof(char) * (strlen(user_input) + 2));
    if (!new_input)
        return false;
    new_input[strlen(new_input)] = c;
    new_input[strlen(new_input)] = '\0';
    line->buffer->content = new_input;
    line->buffer->cursor++;
    line->buffer->len++;
    return true;
}
