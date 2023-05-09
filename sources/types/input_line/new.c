/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** mode
*/

#include <stdlib.h>
#include <stddef.h>
#include "types/input_line/input_line.h"

input_line_t *input_line_new(void)
{
    input_line_t *new = malloc(sizeof(input_line_t));

    if (!new)
        return NULL;
    new->buffer = malloc(sizeof(input_line_buffer_t));
    if (new->buffer == NULL)
        return NULL;
    new->buffer->content = malloc(sizeof(char));
    new->buffer->content[0] = '\0';
    new->buffer->len = 0;
    new->buffer->cursor = 0;
    return new;
}

void input_line_free(input_line_t *line)
{
    free(line->buffer);
    free(line);
}
