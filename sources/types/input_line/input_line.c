/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** main
*/

#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include "utils/utils.h"
#include "types/input_line/input_line.h"

int input_line_read_key(void)
{
    int character = getchar();

    if (iscntrl(character))
        return input_line_get_cntrl();
    else
        return character;
}

void input_line_get_content(input_line_t *line)
{
    int character = 0;

    while (line->status == IL_RUNNING) {
        character = input_line_read_key();
    }
}
