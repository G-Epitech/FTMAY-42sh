/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** Main file of project
*/

#include <stdio.h>
#include <stddef.h>
#include "parsing/parsing.h"
#include "types/parsing_utils/parsing_utils.h"
#include "types/node/node.h"
#include "types/inst/inst.h"

int main(void)
{
    parsing_utils_t *test = parsing_utils_new("ls -l -a > tmp");
    inst_t *instruction = NULL;

    instruction = parsing_get_cmd(test);
    if (instruction)
        printf("Input: [%s]\n", instruction->value.cmd->input);
    instruction = parsing_get_main_block("ls -l -a > tmp");
}
