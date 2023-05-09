/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** get user input
*/

#include <stdio.h>
#include <stddef.h>
#include "types/shell/shell.h"
#include "types/input_line/input_line.h"


static char *shell_get_input_no_tty(shell_t *shell)
{
    char *input = NULL;
    size_t size = 0;
    ssize_t len = 0;

    len = getline(&input, &size, stdin);
    if (len == -1)
        shell_exit(shell);
    else
        input[len - 1] = (input[len - 1] == '\n') ? '\0' : input[len - 1];
    return input;
}

static char *shell_get_input_tty(shell_t *shell)
{
    input_line_t *user_input = input_line_new();

    (void) shell;
    (void) user_input;
    return NULL;
}

char *shell_get_input(shell_t *shell)
{   
    if (shell->is_tty)
        return shell_get_input_no_tty(shell);
    else
        return shell_get_input_tty(shell);
}
