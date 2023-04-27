/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** get_word
*/

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "types/parsing_utils/defs.h"

static bool handle_error(parsing_utils_t *utils, int start, int end)
{
    int len = strlen(utils->input);

    if (len < start || len < end)
        return false;
    if (start < 0 || end < 0)
        return false;
    return true;
}
static void init_char(char *word, int size)
{
    for (int i = 0; i < size; i++) {
        word[i] = '\0';
    }
}

char *parsing_get_word(parsing_utils_t *utils, int start, int end)
{
    char *word = malloc(sizeof(char) * end - start + 1);
    int index = 0;

    if (!word || !handle_error(utils, start, end))
        return NULL;
    init_char(word, end - start + 1);
    while (start < end) {
        word[index] = utils->input[start];
        index++;
        start++;
    }
    return word;
}
