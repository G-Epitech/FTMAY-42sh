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
    if (!shell->is_tty)
        printf("42sh> ");
    else
        printf("\r42sh> ");
}
