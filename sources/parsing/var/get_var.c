/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** get var
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "parsing/defs.h"
#include "parsing/parsing.h"
#include "utils/asprintf2.h"
#include "types/shell/shell.h"

static char *get_name(char *input, int start, int end)
{
    char *word = malloc(sizeof(char) * end - start + 1);
    int index = 0;

    memset(word, '\0', end - start + 1);
    while (start < end) {
        word[index] = input[start];
        index++;
        start++;
    }
    return word;
}

static void display_error(char *name)
{
    fprintf(stderr, "%s: Undefined variable.\n", name);
    fflush(stderr);
}

char *get_var(char *input, shell_t *shell, int *parsing_index)
{
    index_word_t index = {
        .start = (*parsing_index) + 1,
        .end = 0
    };
    char *name = NULL;
    char *value = NULL;

    (*parsing_index)++;
    while (ALPHA_NUMERIC(input[*parsing_index]))
        (*parsing_index)++;
    index.end = *parsing_index;
    name = get_name(input, index.start, index.end);
    value = shell_get_var(shell, name, true);
    if (value == NULL)
        value = getenv(name);
    if (value == NULL)
        display_error(name);
    return value;
}
