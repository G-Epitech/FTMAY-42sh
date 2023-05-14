/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** is_empty
*/

#include <stddef.h>
#include <stdbool.h>

bool str_is_empty(const char *str)
{
    size_t i = 0;
    bool empty = true;

    if (!str)
        return empty;
    while (str[i] != '\0' && empty) {
        if (str[i] != ' ' && str[i] != '\t')
            empty = false;
        i += 1;
    }
    return empty;
}
