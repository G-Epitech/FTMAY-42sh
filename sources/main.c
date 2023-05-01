/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** Main file of project
*/

#include <stdio.h>
#include <stddef.h>
#include "parsing/parsing.h"
#include "parsing/utils.h"
#include "types/parsing_utils/parsing_utils.h"
#include "types/node/node.h"
#include "types/inst/inst.h"

int main(void)
{
    inst_t *instruction = NULL;

    instruction = parsing_get_main_block("((ls | grep l) | grep M) | cat -e");
    parsing_display(instruction);
}
