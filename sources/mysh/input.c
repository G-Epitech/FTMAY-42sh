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
    if (!success)
        shell_set_exit_code(shell, SHELL_EXIT_ERROR);
    return success ? input : NULL;
}
