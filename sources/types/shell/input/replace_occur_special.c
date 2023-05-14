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

bool shell_input_replace_history_entry_special(hist_replace_utils_t *utils,
shell_t *shell)
{
    char *final = utils->final;
    size_t i = utils->i;

    if (final[i + 1] == '?')
        return shell_input_replace_history_entry_last(utils, shell);
    utils->i = i + 1;
    return true;
}
