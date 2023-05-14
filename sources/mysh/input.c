/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** input
*/

#include <stdio.h>
#include "utils/utils.h"
#include "parsing/parsing.h"
#include "types/shell/shell.h"
#include "types/history/history.h"

char *mysh_get_input(shell_t *shell)
{
    char *input = NULL;
    bool success = shell_get_input(shell, &input);

    if (!str_is_empty(input))
        history_append_entry(shell->history, input);
    return success ? input : NULL;
}
