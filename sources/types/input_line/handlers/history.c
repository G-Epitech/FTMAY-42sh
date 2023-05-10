/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** history
*/

#include <stdio.h>
#include <string.h>
#include "types/history/history.h"
#include "types/input_line/input_line.h"

static void replace_buffer_content(input_line_t *line, char *str)
{
    int len = strlen(str);

    line->buffer->cursor = len;
    line->buffer->len = len;
}

void input_line_history_prev(shell_t *shell, input_line_t *line)
{
    history_entry_t *selected = history_current(shell->history);
    
    if (!selected)
        return;
    if (line->buffer->history_cursor == 0 && !line->buffer->history_content)
        line->buffer->history_content = line->buffer->content;
    if (line->buffer->history_cursor > 0)
        selected = history_prev(shell->history);
    if (!selected)
        return;
    line->buffer->history_cursor++;
    line->buffer->content = selected->input;
    replace_buffer_content(line, selected->input);
    refresh_screen(line);
}

void input_line_history_next(shell_t *shell, input_line_t *line)
{
    history_entry_t *selected = history_next(shell->history);

    if (line->buffer->history_cursor == 0 && line->buffer->history_content) {
        line->buffer->content = line->buffer->history_content;
        replace_buffer_content(line, line->buffer->content);
        refresh_screen(line);
        line->buffer->history_content = NULL;
    }
    if (!selected)
        return;
    line->buffer->content = selected->input;
    line->buffer->history_cursor--;
    replace_buffer_content(line, selected->input);
    refresh_screen(line);
}
