/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** replace
*/

#include <string.h>
#include <stddef.h>
#include "types/shell/shell.h"

static bool replace_all_from_history(char *original, char **export,
bool *updated, shell_t *shell)
{
    hist_replace_utils_t utils = {strdup(original), 0, false, false};
    size_t *i = &(utils.i);
    char *start = utils.final;
    char *occur = start ? strchr(start, '!') : NULL;

    *i = occur - start;
    while (utils.final && utils.final[*i] != '\0')
        shell_input_replace_history_handle_occur(&utils, shell);
    *export = utils.final;
    *updated = utils.updated;
    return !utils.error;
}

bool shell_input_replace_history(char *original, char **final, bool *updated,
shell_t *shell)
{
    *updated = false;
    if (!strchr(original, '!')) {
        *final = original;
        return true;
    }
    return replace_all_from_history(original, final, updated, shell);
}
