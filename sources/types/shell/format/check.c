/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** check
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

static void display_error(void)
{
    fprintf(stderr, "Illegal variable name.\n");
}

static bool check_var(char *input, int *index_start_var)
{
    if (input[(*index_start_var)] == '$') {
        (*index_start_var)++;
        if (!CHAR_IS_ALPHA_EXT(input[(*index_start_var)])
        && input[*index_start_var] != '?')
            return false;
        else
            return true;
    }
    return true;
}

bool shell_format_check(shell_t *shell, char *input)
{
    for (int index = 0; input[index] != '\0'; index++) {
        if (!check_var(input, &index)) {
            shell->exit_code = SHELL_EXIT_ERROR;
            display_error();
            return false;
        }
    }
    return true;
}
