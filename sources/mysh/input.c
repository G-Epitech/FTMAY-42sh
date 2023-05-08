/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** input
*/

#include "parsing/parsing.h"
#include "types/shell/shell.h"

char *mysh_get_input(shell_t *shell)
{
    char *typed = shell_get_input(shell);

    return typed;
}
