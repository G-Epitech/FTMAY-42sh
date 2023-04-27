/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** parsing
*/

#include <stdio.h>
#include "types/inst/inst.h"
#include "types/parsing_utils/parsing_utils.h"

void set_type(int index, inst_t *instruction)
{
    printf("0\n");
    if (index == 0)
        instruction->ios.input.type = IOT_SIMPLE;
    printf("1\n");
    if (index == 1)
        instruction->ios.input.type = IOT_DOUBLE;
    printf("2\n");
    if (index == 2)
        instruction->ios.output.type = IOT_DOUBLE;
    printf("3\n");
    if (index == 3)
        instruction->ios.output.type = IOT_SIMPLE;
    printf("4\n");
}
