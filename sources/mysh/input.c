/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** input
*/

#include <stdio.h>
#include "parsing/parsing.h"
#include "types/shell/shell.h"

char *mysh_get_input(shell_t *shell)
{
    char *c = shell_get_input(shell);

    printf("input [%s]\n", c);
    return c;
}
