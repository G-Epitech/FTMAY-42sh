/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** io criterion tests
*/

#include <string.h>
#include <criterion/criterion.h>
#include "types/io/io.h"
#include "types/io/defs.h"

Test(types_io, free_valid_io)
{
    io_t io = {NULL, IOT_DEFAULT};

    io.path = strdup("empty path");
    io_free(&io);
    cr_assert(io.path == NULL);
}

Test(types_io, free_null_io)
{
    io_free(NULL);
}
