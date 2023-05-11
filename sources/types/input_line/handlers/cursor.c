/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** cursor
*/

#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include "utils/malloc2.h"
#include "utils/asprintf2.h"
#include "types/input_line/input_line.h"

static void get_terminal_size(int *rows, int *columns)
{
    struct winsize size;

    ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
    *rows = size.ws_row;
    *columns = size.ws_col;
}

void input_line_cursor_backward(shell_t *shell, input_line_t *line)
{
    int x = 0;

    (void) shell;
    if (line->buffer->cursor <= 0)
        return;
    if (line->buffer->pos_col_cursor == 1 && line->buffer->pos_rows_cursor > 0) {
        line->buffer->pos_rows_cursor--;
        get_terminal_size(&x, &line->buffer->pos_col_cursor);
        printf("\x1b[%i;%iH", line->buffer->pos_rows_cursor, line->buffer->pos_col_cursor);
        line->buffer->cursor--;
        return;
    }
    printf("\033[1D");
    line->buffer->cursor--;
    line->buffer->pos_col_cursor--;
}

void input_line_cursor_forward(shell_t *shell, input_line_t *line)
{
    (void) shell;
    if (line->buffer->cursor >= line->buffer->len)
        return;
    printf("\033[1C");
    line->buffer->cursor++;
    line->buffer->pos_col_cursor++;
}
