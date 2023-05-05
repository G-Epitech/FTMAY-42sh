/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** get user input
*/

#include <stdio.h>
#include <stddef.h>
#include "types/shell/shell.h"

char *shell_get_input(shell_t *shell)
{
    char *input = NULL;
    size_t size = 0;
    ssize_t len = 0;

    len = getline(&input, &size, stdin);
    if (len == -1)
        shell_exit(shell);
    input[len - 1] = (input[len - 1] == '\n') ? '\0' : input[len - 1];
    return input;
}
