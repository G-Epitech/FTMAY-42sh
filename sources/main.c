/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** Main file of project
*/

#include <stdio.h>
#include <stddef.h>
#include "parsing/utils.h"
#include "parsing/parsing.h"
#include "types/node/node.h"
#include "types/inst/inst.h"
#include "types/parsing_utils/parsing_utils.h"

int main(void)
{
    inst_t *instruction = NULL;

    instruction = parsing_get_main_block("(ls | grep l); cat Makefile > test");
    if (instruction == NULL)
        return 84;
    parsing_display(instruction);
}
