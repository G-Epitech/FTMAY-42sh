/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** delete_char
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

void delete_char(shell_t *shell, input_line_t *line)
{
    char *user_input = line->buffer->content;
    char *begin = get_word(user_input, 0, line->buffer->cursor - 1);
    char *end = get_word(user_input, line->buffer->cursor, strlen(user_input));
    char *new_input_user = NULL;

    (void) shell;
    if (line->buffer->cursor <= 0)
        return;
    if (asprintf2(&new_input_user, "%s%s", begin, end) == -1)
        return;
    line->buffer->content = new_input_user;
    line->buffer->cursor--;
    line->buffer->len--;
    refresh_screen(line);
    return;
}
