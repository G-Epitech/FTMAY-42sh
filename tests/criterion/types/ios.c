/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** ios criterion tests
*/

#include <stdio.h>
#include <criterion/criterion.h>
#include "types/io/io.h"
#include "types/io/defs.h"

Test(types_ios, free_valid_ios)
{
    io_t input = {NULL, IOT_DEFAULT};
    io_t output = {NULL, IOT_DEFAULT};
    ios_t ios = {input, output};

    ios.input.path = strdup("input | empty path");
    ios.output.path = strdup("output | empty path");
    ios_free(&ios);
    cr_assert(ios.input.path == NULL);
    cr_assert(ios.output.path == NULL);
}

Test(types_ios, free_input_valide_and_output_null_ios)
{
    io_t input = {NULL, IOT_DEFAULT};
    io_t output = {NULL, IOT_DEFAULT};
    ios_t ios = {input, output};

    ios.input.path = strdup("input | empty path");
    ios_free(&ios);
    cr_assert(ios.input.path == NULL);
    cr_assert(ios.output.path == NULL);
}

Test(types_ios, free_input_null_and_output_valide_ios)
{
    io_t input = {NULL, IOT_DEFAULT};
    io_t output = {NULL, IOT_DEFAULT};
    ios_t ios = {input, output};

    ios.output.path = strdup("output | empty path");
    ios_free(&ios);
    cr_assert(ios.input.path == NULL);
    cr_assert(ios.output.path == NULL);
}

Test(types_ios, free_null_ios)
{
    ios_free(NULL);
}
