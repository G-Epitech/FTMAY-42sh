/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** iscntrl
*/

#include <stdio.h>
#include "utils/utils.h"
#include "types/input_line/input_line.h"

int input_line_get_cntrl(void)
{
    int character = getchar();

    switch (character) {
        case KEY_ARROWS:
            input_line_get_arrows();
            break;
        case KEY_CTRLS:
            printf("ctrl + %c\n", character);
            break;
        default:
            break;
    }
    return character;
}
