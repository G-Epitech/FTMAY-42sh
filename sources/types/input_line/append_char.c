/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** iscntrl
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils/malloc2.h"
#include "utils/asprintf2.h"
#include "types/input_line/input_line.h"

static char *get_word(char *user_input, int start, int end)
{
    char *word = malloc2(sizeof(char) * end - start + 1);
    int index = 0;

    if (!word)
        return NULL;
    memset(word, '\0', end - start + 1);
    while (start < end) {
        word[index] = user_input[start];
        index++;
        start++;
    }
    return word;
}

bool append_char(input_line_t *line, int c)
{
    char *user_input = line->buffer->content;
    char *begin = get_word(user_input, 0, line->buffer->cursor);
    char *end = get_word(user_input, line->buffer->cursor, strlen(user_input));
    char *new_input = realloc(begin, sizeof(char) * (strlen(begin) + 2));
    char *new_input_user = NULL;

    if (!new_input)
        return false;
    new_input[strlen(new_input)] = c;
    new_input[strlen(new_input)] = '\0';
    begin = new_input;
    if (asprintf2(&new_input_user, "%s%s", begin, end) == -1)
        return false;
    line->buffer->content = new_input_user;
    line->buffer->cursor++;
    line->buffer->len++;
    return true;
}
