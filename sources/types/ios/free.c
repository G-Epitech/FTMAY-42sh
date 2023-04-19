/*
** EPITECH PROJECT, 2023
** G-42sh-1 [WSL: Ubuntu]
** File description:
** free
*/

#include "types/io/io.h"

void ios_free(ios_t *ios)
{
    if (!ios)
        return;
    io_free(&ios->input);
    io_free(&ios->output);
}
