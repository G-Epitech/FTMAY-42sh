/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** replace_occur
*/

#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>
#include "types/shell/shell.h"

static bool is_special(char *input, size_t i)
{
    if (input[i - 1] == '\\')
        return true;
    if (input[i + 1] == '?')
        return true;
    return false;
}

static bool replace_occur(hist_replace_utils_t *utils, shell_t *shell)
{
    history_entry_t *entry = NULL;
    char *ptrn = NULL;
    size_t ptrn_len = 0;
    size_t ptrn_start = utils->i + 1;

    shell_input_replace_history_get_pattern(utils->final, ptrn_start,
    &ptrn_len);
    if (ptrn_len == 0) {
        utils->i += 1;
        return true;
    }
    ptrn = strndup(utils->final + ptrn_start, ptrn_len);
    entry = shell_input_replace_history_get_entry(ptrn, ptrn_len, shell);
    shell_input_replace_history_check_entry(utils, ptrn, entry, shell);
    free(ptrn);
    return shell_input_replace_history_entry_occur(utils, ptrn_len, entry);
}

void shell_input_replace_history_check_entry(hist_replace_utils_t *utils,
char *pattern, history_entry_t *entry, shell_t *shell)
{
    if (!entry) {
        if (!utils->error)
            fprintf(stderr, "%s: Event not found.\n", pattern);
        utils->error = true;
    }
    if (shell) {
        free(shell->last_history_pattern);
        shell->last_history_pattern = strdup(pattern);
    }
}

bool shell_input_replace_history_handle_occur(hist_replace_utils_t *utils,
shell_t *shell)
{
    if (strlen(utils->final + utils->i) <= 1) {
        utils->i += 1;
        return true;
    }
    if (is_special(utils->final, utils->i)) {
        return shell_input_replace_history_entry_special(utils, shell);
    }
    return replace_occur(utils, shell);
}
