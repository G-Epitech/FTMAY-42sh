/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** replace_occur
*/

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "utils/asprintf2.h"
#include "types/shell/shell.h"

bool shell_input_replace_escape_char(hist_replace_utils_t *utils)
{
    char *tmp = NULL;
    char *left = strndup(utils->final, utils->i - 1);
    char *right = utils->final + utils->i + 1;

    utils->updated |= false;
    if (!left)
        return false;
    if (asprintf2(&tmp, "%s%s%s", left, "!", right) == -1)
        tmp = NULL;
    free(left);
    if (!tmp)
        return false;
    free(utils->final);
    utils->final = tmp;
    return true;
}
