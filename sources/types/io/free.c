/*
** EPITECH PROJECT, 2023
** G-42sh-1
** File description:
** free io
*/

#include "types/io/defs.h"

void io_free(io_t *io)
{
    if (!io)
        return;
    free(io->path);
}
