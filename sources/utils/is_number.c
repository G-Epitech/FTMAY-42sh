/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** is_number
*/

#include <stdlib.h>
#include <stdbool.h>

bool is_number(char *string)
{
    size_t index = 0;

    if (!string)
        return false;
    if (string[0] == '-')
        index++
    for (index; string[index] != '\0'; index++) {
        if (string[index] < '0' || string[index] > '9')
            return false;
    }
    return true;
}
