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
#include "utils/malloc2.h"
#include "parsing/parsing.h"
#include "types/inst/inst.h"
#include "utils/asprintf2.h"
#include "types/shell/shell.h"
#include "types/parsing_utils/parsing_utils.h"

static void concat_no_var(index_word_t *index, char *input,
int parsing_index, char **input_replace)
{
    char *tmp = NULL;

    index->end = parsing_index;
    asprintf2(&tmp, "%s%s", *input_replace,
    shell_format_string_get_no_var(input, index->start, index->end));
    free(*input_replace);
    *input_replace = tmp;
}

static int concat_var(shell_t *shell, char *input,
int *parsing_index, char **input_replace)
{
    char *tmp = NULL;
    char *var = NULL;

    var = shell_format_string_get_var(input, shell, parsing_index);
    if (!var)
        return SHELL_VAR_NOT_FOUND;
    asprintf2(&tmp, "%s%s", *input_replace, var);
    free(*input_replace);
    *input_replace = tmp;
    return SHELL_VAR_FOUND;
}

char *shell_format_string(char *string, shell_t *shell)
{
    index_word_t index = {0};
    char *input_replace = malloc2(sizeof(char));
    int parsing_index = 0;
    int var_exist = 0;

    if (!input_replace)
        return NULL;
    while (string[parsing_index] != '\0') {
        if (string[parsing_index] == PARSING_VAR_PREFIX) {
            concat_no_var(&index, string, parsing_index, &input_replace);
            var_exist = concat_var(shell, string,
            &parsing_index, &input_replace);
            index.start = parsing_index;
        }
        if (var_exist == SHELL_VAR_NOT_FOUND)
            return NULL;
        parsing_index++;
    }
    concat_no_var(&index, string, parsing_index++, &input_replace);
    return input_replace;
}
