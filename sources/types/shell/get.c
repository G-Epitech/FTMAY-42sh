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
    char *input_user = NULL;
    size_t len = 0;
    int out = 0;

    out = getline(&input_user, &len, stdin);
    if (out == -1)
        shell_exit(shell);
    return input_user;
}
