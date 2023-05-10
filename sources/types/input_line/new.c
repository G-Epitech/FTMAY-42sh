/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** mode
*/

#include <stdlib.h>
#include <stddef.h>
#include "utils/malloc2.h"
#include "types/input_line/input_line.h"

static char *malloc_new_buffer_content(void)
{
    char *string = malloc2(sizeof(char));

    if (!string)
        return NULL;
    string[0] = '\0';
    return string;
}

input_line_t *input_line_new(void)
{
    input_line_t *new = malloc2(sizeof(input_line_t));

    if (!new)
        return NULL;
    new->buffer = malloc2(sizeof(input_line_buffer_t));
    if (new->buffer == NULL)
        return NULL;
    new->buffer->content = malloc_new_buffer_content();
    new->buffer->history_content = malloc_new_buffer_content();
    new->buffer->len = 0;
    new->buffer->cursor = 0;
    new->buffer->history_cursor = 0;
    return new;
}

void input_line_free(input_line_t *line)
{
    free(line->buffer);
    free(line);
}
