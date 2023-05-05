/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** asprintf2
*/

#include <stdio.h>
#include <assert.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include "utils/malloc2.h"

ssize_t asprintf2(char **strp, const char *format, ...)
{
    va_list args1;
    va_list args2;
    ssize_t size = 0;

    va_start(args1, format);
    va_start(args2, format);
    size = vsnprintf(NULL, 0, format, args1) + 1;
    *strp = malloc2(size);
    if (*strp)
        vsprintf(*strp, format, args2);
    else
        size = -1;
    va_end(args1);
    va_end(args2);
    return size;
}
