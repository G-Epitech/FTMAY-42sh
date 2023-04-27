/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** parsing
*/

#include "types/inst/inst.h"
#include "types/parsing_utils/parsing_utils.h"

void set_type(int index, inst_t *instruction)
{
    if (index == 0)
        instruction->ios.input.type = IOT_SIMPLE;
    if (index == 1)
        instruction->ios.input.type = IOT_DOUBLE;
    if (index == 2)
        instruction->ios.output.type = IOT_DOUBLE;
    if (index == 3)
        instruction->ios.output.type = IOT_SIMPLE;
}
