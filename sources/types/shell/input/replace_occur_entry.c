/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** replace_occur
*/

#include <stddef.h>
#include <string.h>
#include <stdbool.h>
#include "utils/asprintf2.h"
#include "types/shell/shell.h"

bool shell_input_replace_history_entry_occur(hist_replace_utils_t *utils,
size_t pattern_len, history_entry_t *entry)
{
    char *tmp = NULL;
    char *replace = entry ? entry->input : " ";
    char *left = strndup(utils->final, utils->i);
    char *right = utils->final + utils->i + 1 + pattern_len;

    if (!left)
        return false;
    if (asprintf2(&tmp, "%s%s%s", left, replace, right) == -1)
        tmp = NULL;
    utils->i += strlen(replace);
    free(left);
    if (!tmp)
        return false;
    free(utils->final);
    utils->final = tmp;
    return true;
}
