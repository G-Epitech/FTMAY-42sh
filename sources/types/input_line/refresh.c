/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** delete_char
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "types/input_line/input_line.h"

void refresh_screen(input_line_t *line)
{
    printf("\x1b[%dG\x1b[0J", PROMPT_LEN);
    printf("%s", line->buffer->content);
    printf("\x1b[%ldG", line->buffer->cursor + PROMPT_LEN);
}