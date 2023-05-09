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
    struct termios default_settings;
    char *input = NULL;

    (void) shell;
    if (!user_input)
        return NULL;
    input_line_enable_raw_mode(user_input, &default_settings);
    input_line_get_content(user_input, shell);
    input_line_disable_raw_mode(&default_settings);
    input = user_input->buffer->content;
    input_line_free(user_input);
    return input;
}

char *shell_get_input(shell_t *shell)
{
    if (!shell->is_tty)
        return shell_get_input_no_tty(shell);
    else
        return shell_get_input_tty(shell);
}
