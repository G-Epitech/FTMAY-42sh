/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** history
*/

#include <stdio.h>
#include <string.h>
#include "types/input_line/defs.h"
#include "types/history/history.h"

static void replace_buffer_content(input_line_t *line, char *str)
{
    int len = strlen(str);

    line->buffer->cursor = len;
}

void input_line_history_prev(shell_t *shell, input_line_t *line)
{
    history_entry_t *selected = NULL;

    selected = history_prev(shell->history);
    if (!selected)
        return;
    printf("\033[%ldD", line->buffer->cursor);
    line_clear_after_cursor;
    printf("%s", selected->input);
    replace_buffer_content(line, selected->input);
}

void input_line_history_next(shell_t *shell, input_line_t *line)
{
    history_entry_t *selected = NULL;

    selected = history_next(shell->history);
    if (!selected)
        return;
    printf("\033[%ldD", line->buffer->cursor);
    line_clear_after_cursor;
    printf("%s", selected->input);
    replace_buffer_content(line, selected->input);
}
