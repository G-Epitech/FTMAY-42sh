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
#include <sys/ioctl.h>
#include "utils/utils.h"
#include "types/input_line/handlers.h"
#include "types/input_line/input_line.h"

void display_cursor(input_line_t *line)
{
    int pos_rows_cursor = 0;
    int pos_col_cursor = 0;

    pos_rows_cursor = line->buffer->rows_start_cursor + ((line->buffer->cursor
    + PROMPT_LEN) / (line->buffer->term_size->nb_cols + 1));
    pos_rows_cursor = line->buffer->rows_start_cursor + ((line->buffer->cursor
    + PROMPT_LEN + (pos_rows_cursor - line->buffer->rows_start_cursor)) /
    (line->buffer->term_size->nb_cols + 1));
    pos_col_cursor = (line->buffer->cursor + PROMPT_LEN + (pos_rows_cursor -
    line->buffer->rows_start_cursor)) % (line->buffer->term_size->nb_cols + 1);
    printf("\x1b[%i;%iH", pos_rows_cursor, pos_col_cursor + 0);
}
