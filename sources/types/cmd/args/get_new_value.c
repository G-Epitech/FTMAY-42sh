/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** get_new_value
*/

#include <stdlib.h>
#include "parsing/defs.h"

char cmd_get_new_value(char character)
{
    size_t i = 0;

    while (PARSING_SPECIAL_CHAR[i] != '\0') {
        if (PARSING_SPECIAL_CHAR[i] == character)
            return PARSING_SPECIAL_REPLACE[i];
        i++;
    }
    return character;
}
