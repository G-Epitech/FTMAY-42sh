/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** history_entry
*/

#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>
#include "utils/utils.h"
#include "types/shell/defs.h"
#include "types/history/history.h"

static bool is_valid_char(char c)
{
    return CHAR_IS_ALPHANUM_EXT(c) || c == '@' || c == '?';
}

void shell_input_replace_history_get_pattern(char *input, size_t i,
size_t *pattern_len)
{
    size_t len = 0;
    bool valid = true;

    while (input[i] != '\0' && valid) {
        valid = is_valid_char(input[i]);
        len += valid ? 1 : 0;
        i += 1;
    }
    *pattern_len = len;
}
