/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** parsing
*/

#include <stdio.h>
#include "types/inst/inst.h"
#include "parsing/parsing.h"
#include "types/parsing_utils/parsing_utils.h"

void set_type(int index, inst_t *instruction)
{
    if (index == SIMPLE_LEFT_REDIRECTION)
        instruction->ios.input.type = IOT_SIMPLE;
    if (index == DOUBLE_LEFT_REDIRECTION)
        instruction->ios.input.type = IOT_DOUBLE;
    if (index == DOUBLE_RIGHT_REDIRECTION)
        instruction->ios.output.type = IOT_DOUBLE;
    if (index == SIMPLE_RIGHT_REDIRECTION)
        instruction->ios.output.type = IOT_SIMPLE;
}
