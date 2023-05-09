/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** cursor
*/

#include "types/input_line/defs.h"

void input_line_cursor_backward(shell_t *shell, input_line_t *line)
{
    (void) shell;
    if (line->buffer->cursor <= 0)
        return;
    printf("\033[1D");
    line->buffer->cursor--;
}

void input_line_cursor_forward(shell_t *shell, input_line_t *line)
{
    (void) shell;
    if (line->buffer->cursor >= line->buffer->len)
        return;
    printf("\033[1C");
    line->buffer->cursor++;
}
