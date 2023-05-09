/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** iscntrl
*/

#include <stdio.h>
#include "utils/utils.h"
#include "types/input_line/input_line.h"

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

int input_line_get_cntrl(void)
{
    int character = getchar();

    switch (character) {
        case KEY_CTRL_ENTER:
            character = CTRL_KEY_ENTER;
            break;
        case 'D':
            character = CTRL_KEY_D;
            break;
        default:
            break;
    }
    return character;
}

int input_line_get_cntrls(void)
{
    int character = getchar();

    switch (character) {
        case KEY_ARROWS:
            character = input_line_get_arrows();
            break;
        case KEY_CTRLS:
            character = input_line_get_cntrl();
            break;
        default:
            break;
    }
    return character;
}
