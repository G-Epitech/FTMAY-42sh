/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** main
*/

#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>
#include "utils/utils.h"
#include "types/input_line/input_line.h"

int input_line_read_key(void)
{
    int character = getchar();

    if (iscntrl(character))
        return input_line_get_cntrls();
    else
        return character;
}

void input_line_get_content(input_line_t *line)
{
    int character = 0;

    (void) character;
    while (line->status == IL_RUNNING) {
        character = input_line_read_key();
        if (ARROW_KEY_LEFT == character)
            input_line_cursor_backward(NULL, line);
        if (ARROW_KEY_RIGHT == character)
            input_line_cursor_forward(NULL, line);
        if (character <= 127) {
            append_char(line, character);
            printf("%c", character);
        }
    }
}
