/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** free io
*/

#include <stdlib.h>
#include "types/io/defs.h"

void io_free(io_t *io)
{
    if (!io)
        return;
    free(io->path);
    io->path = NULL;
}
