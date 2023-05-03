/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** replace
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "parsing/defs.h"
#include "parsing/parsing.h"
#include "types/inst/inst.h"
#include "types/shell/shell.h"
#include "utils/asprintf2.h"
#include "types/parsing_utils/parsing_utils.h"

static void concat_no_var(index_word_t *index, char *input,
int parsing_index, char **input_replace)
{
    char *tmp = NULL;

    index->end = parsing_index;
    asprintf2(&tmp, "%s%s", *input_replace, get_no_var(input, index->start, index->end));
    free(*input_replace);
    *input_replace = tmp;
}

static void concat_var(shell_t *shell, char *input,
int *parsing_index, char **input_replace)
{
    char *tmp = NULL;

    asprintf2(&tmp, "%s%s", *input_replace, get_var(input, shell, parsing_index));
    free(*input_replace);
    *input_replace = tmp;
}

char *parsing_var_replace(char *input, shell_t *shell)
{
    index_word_t index = {
        .start = 0,
        .end = 0
    };
    char *input_replace = malloc(sizeof(char));
    int parsing_index = 0;

    input_replace[0] = '\0';
    while (input[parsing_index] != '\0') {
        if (input[parsing_index] == PARSING_VAR_PREFIX) {
            concat_no_var(&index, input, parsing_index, &input_replace);
            concat_var(shell, input, &parsing_index, &input_replace);
            index.start = parsing_index;
        }
        parsing_index++;
    }
    parsing_index++;
    concat_no_var(&index, input, parsing_index, &input_replace);
    return input_replace;
}
