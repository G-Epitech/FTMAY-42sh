/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** arrow
*/

#include <stdio.h>
#include "utils/utils.h"
#include "types/input_line/defs.h"

int input_line_get_arrows(void)
{
    int character = getchar();

    switch (character) {
        case KEY_ARROW_UP:
            character = ARROW_KEY_UP;
            break;
        case KEY_ARROW_DOWN:
            character = ARROW_KEY_DOWN;
            break;
        case KEY_ARROW_RIGHT:
            character = ARROW_KEY_RIGHT;
            break;
        case KEY_ARROW_LEFT:
            character = ARROW_KEY_LEFT;
            break;
        default:
            break;
    }
    return character;
}
