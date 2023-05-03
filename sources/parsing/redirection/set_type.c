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

void parsing_redirection_set_type(int index, inst_t *instruction)
{
    if (index == PARSING_SIMPLE_LEFT)
        instruction->ios.input.type = IOT_SIMPLE;
    if (index == PARSING_DOUBLE_LEFT)
        instruction->ios.input.type = IOT_DOUBLE;
    if (index == PARSING_DOUBLE_RIGHT)
        instruction->ios.output.type = IOT_DOUBLE;
    if (index == PARSING_SIMPLE_RIGHT)
        instruction->ios.output.type = IOT_SIMPLE;
}
