/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** prompt
*/

#include <stdio.h>
#include "types/shell/shell.h"

void shell_display_prompt(shell_t *shell)
{
    (void) shell;
    printf("42sh> ");
    fflush(stdout);
}
