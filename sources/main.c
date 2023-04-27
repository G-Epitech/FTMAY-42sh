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
    parsing_utils_t *test = parsing_utils_new(">      tmp_fic           (ls -l -a | cat -e)");
    inst_block_t *test_inst_block = inst_block_new();
    inst_t *test_inst = inst_new();

    inst_block_append(test_inst_block, test_inst);

    parsing_redirection_handler(test, NODE_DATA_TO_PTR(test_inst_block->instructions->first->data, inst_t *));
}
