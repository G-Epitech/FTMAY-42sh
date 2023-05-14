/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** replace_occur
*/

#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>
#include "types/shell/shell.h"

static bool replace_last(hist_replace_utils_t *utils, size_t ptrn_len,
shell_t *shell)
{
    history_entry_t *entry = NULL;
    char *ptrn = NULL;
    size_t ptrn_real_len = 0;

    if (!shell->last_history_pattern) {
        fprintf(stderr, "No prev search.\n");
        utils->error = true;
    } else {
        ptrn = shell->last_history_pattern;
        ptrn_real_len = strlen(ptrn);
        entry = shell_input_replace_history_get_entry(ptrn, ptrn_real_len,
        shell);
        shell_input_replace_history_check_entry(utils, ptrn, entry, NULL);
    }
    return shell_input_replace_history_entry_occur(utils, ptrn_len, entry);
}

static bool replace_classic(hist_replace_utils_t *utils, size_t ptrn_len,
char *ptrn_real, shell_t *shell)
{
    history_entry_t *entry = NULL;
    size_t ptrn_real_len = strlen(ptrn_real);

    entry = shell_input_replace_history_get_entry(ptrn_real,
    ptrn_real_len, shell);
    shell_input_replace_history_check_entry(utils, ptrn_real, entry, shell);
    return shell_input_replace_history_entry_occur(utils, ptrn_len, entry);
}

bool shell_input_replace_escape_char(hist_replace_utils_t *utils,
shell_t *shell)
{
    char *ptrn = NULL;
    size_t ptrn_len = 0;
    size_t ptrn_start = utils->i + 1;
    size_t start_diff = 0;
    bool success = true;

    shell_input_replace_history_get_pattern(utils->final, ptrn_start,
    &ptrn_len);
    start_diff = get_start_diff(utils->final + ptrn_start, ptrn_len);
    if (start_diff == 0) {
        success = replace_last(utils, ptrn_len, shell);
    } else {
        ptrn_start += start_diff;
        ptrn = strndup(utils->final + ptrn_start, ptrn_len - start_diff);
        success = replace_classic(utils, ptrn_len, ptrn, shell);
        free(ptrn);
    }
    return success;
}
