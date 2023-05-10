/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** history
*/

#include <stdio.h>
#include <string.h>
#include "types/input_line/defs.h"

static void replace_buffer_content(input_line_t *line, char *str)
{
    int len = strlen(str);

    line->buffer->cursor = len;
}

void input_line_history_prev(shell_t *shell, input_line_t *line)
{
    char *str = "Yann, always on the back";

    (void) shell;
    printf("\033[%ldD", line->buffer->cursor);
    line_clear_after_cursor;
    printf("%s", str);
    replace_buffer_content(line, str);
}

void input_line_history_next(shell_t *shell, input_line_t *line)
{
    char *str = "Yann,                  always on the front";

    (void) shell;
    printf("\033[%ldD", line->buffer->cursor);
    line_clear_after_cursor;
    printf("%s", str);
    replace_buffer_content(line, str);
}
