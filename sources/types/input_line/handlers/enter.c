/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** cursor
*/

#include <stdio.h>
#include <string.h>
#include "types/input_line/defs.h"

void input_line_keypress_enter(shell_t *shell, input_line_t *line)
{
    (void) shell;
    line->status = IL_EXITED;
}
