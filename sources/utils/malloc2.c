/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** malloc2
*/

#include <stdlib.h>
#include <stdbool.h>
#include "utils/malloc2.h"

int malloc2_mode(int action, int new_mode)
{
    static int mode = MALLOC2_MODE_NORMAL;

    if (action == MALLOC2_SET_MODE)
        mode = new_mode;
    return mode;
}

void *malloc2(size_t size)
{
    int mode = malloc2_mode(MALLOC2_GET_MODE, MALLOC2_MODE_NORMAL);

    if (mode == MALLOC2_MODE_FAIL)
        return NULL;
    else
        return malloc(size);
}
