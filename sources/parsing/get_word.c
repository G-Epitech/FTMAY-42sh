/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** get_word
*/

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils/malloc2.h"
#include "types/parsing_utils/defs.h"

static bool handle_error(parsing_utils_t *utils, int start, int end)
{
    int len = strlen(utils->input);

    if (start < 0 || end < 0)
        return false;
    if (len < start || len < end - 1)
        return false;
    return true;
}

char *parsing_get_word(parsing_utils_t *utils, int start, int end)
{
    char *word = malloc2(sizeof(char) * end - start + 1);
    int index = 0;

    if (!word || !handle_error(utils, start, end))
        return NULL;
    memset(word, '\0', end - start + 1);
    while (start < end) {
        word[index] = utils->input[start];
        index++;
        start++;
    }
    return word;
}
