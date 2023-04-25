/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** Main file of project
*/

#include "types/inst/inst.h"
#include "types/list/list.h"

int main(void)
{
    inst_block_t *instruction1 = inst_block_new();
    inst_t *instruction2 = inst_new();
    inst_t *instruction3 = NULL;
    node_data_t data = {NULL};

    inst_block_append(instruction1, instruction2);
    data = instruction1->instructions->first->data;
    instruction3 = NODE_DATA_TO_PTR(data, inst_t *);
    inst_block_free(instruction1);
    (void) instruction3;
}
