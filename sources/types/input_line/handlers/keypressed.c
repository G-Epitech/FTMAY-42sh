/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** cursor
*/

#include <stdio.h>
#include <string.h>
#include "types/input_line/defs.h"

void input_line_keypressed_enter(shell_t *shell, input_line_t *line)
{
    (void) shell;
    line->status = IL_EXITED;
}

void input_line_keypressed_d(shell_t *shell, input_line_t *line)
{
    line->status = IL_EXITED;
    shell->status = SH_EXITED;
}

void input_line_keypressed_c(shell_t *shell, input_line_t *line)
{
    (void) shell;
    (void) line;
    free(line->buffer->content);
    line->buffer->content = strdup("");
    line->status = IL_EXITED;
}

void input_line_keypressed_a(shell_t *shell, input_line_t *line)
{
    int y = 0;
    int x = 0;

    (void) shell;
    (void) line;
    printf("\033[6n");
    scanf("\033[%d;%dR", &y, &x);
    printf("Cursor position\t[y:%d\tx:%d)]\r\n", y, x);
}

void input_line_keypressed_tab(shell_t *shell, input_line_t *line)
{
    (void) shell;
    (void) line;
}
