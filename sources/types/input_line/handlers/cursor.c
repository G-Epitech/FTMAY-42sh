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
