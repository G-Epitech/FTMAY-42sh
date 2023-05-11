/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** delete_char
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include "types/input_line/input_line.h"

// static void get_terminal_size(int *rows, int *columns)
// {
//     struct winsize size;
//     ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
//     *rows = size.ws_row;
//     *columns = size.ws_col;
// }

void refresh_screen(input_line_t *line)
{
    int pos_col_cursor = line->buffer->pos_col_cursor;

    printf("\x1b[%d;%dH", line->buffer->rows_start_cursor, PROMPT_LEN);
    printf("\x1b[0J");
    printf("%s", line->buffer->content);
    printf("\x1b[%i;%iH", line->buffer->pos_rows_cursor, pos_col_cursor);
}

// void refresh_screen(input_line_t *line)
// {
//     printf("\x1b[%d;%dH", line->buffer->rows_start_cursor, PROMPT_LEN);
//     printf("\x1b[0J");
//     printf("%s", line->buffer->content);
//     printf("\x1b[%ldG", line->buffer->cursor + PROMPT_LEN);
// }
