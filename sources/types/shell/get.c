/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** get user input
*/

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

char *shell_get_input(void)
{
    char *input_user = NULL;
    size_t len = 0;
    int out = 0;

    while (out <= 0)
        out = getline(&input_user, &len, stdin);
    return input_user;
}

void shell_free_input(char *input)
{
    if (input)
        free(input);
}

