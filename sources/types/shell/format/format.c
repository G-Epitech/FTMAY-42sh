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

static void concat_no_var(index_word_t *indexes, char *input,
int index, char **replace)
{
    char *tmp = NULL;
    char *no_var = NULL;

    indexes->end = index;
    no_var = shell_format_string_get_no_var(input, indexes->start,
    indexes->end);
    asprintf2(&tmp, "%s%s", *replace, no_var);
    free(*replace);
    *replace = tmp;
}

static int concat_var(shell_t *shell, char *input,
int *index, char **replace)
{
    char *tmp = NULL;
    char *var = NULL;

    var = shell_format_string_get_var(input, shell, index);
    if (!var)
        return SHELL_VAR_NOT_FOUND;
    asprintf2(&tmp, "%s%s", *replace, var);
    free(*replace);
    *replace = tmp;
    return SHELL_VAR_FOUND;
}

char *shell_format_string(char *string, shell_t *shell)
{
    index_word_t indexes = {0};
    char *replace = malloc2(sizeof(char));
    int index = 0;
    int var_exist = 0;

    if (!replace)
        return NULL;
    replace[0] = '\0';
    while (string[index] != '\0') {
        if (string[index] == PARSING_VAR_PREFIX) {
            concat_no_var(&indexes, string, index, &replace);
            var_exist = concat_var(shell, string, &index, &replace);
            indexes.start = index;
        }
        if (var_exist == SHELL_VAR_NOT_FOUND)
            return NULL;
        index++;
    }
    concat_no_var(&indexes, string, index++, &replace);
    return replace;
}
