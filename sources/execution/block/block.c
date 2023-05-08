/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** block
*/

#include <stdio.h>
#include <unistd.h>
#include "types/inst/defs.h"
#include "execution/execution.h"

static node_t *get_high_node(node_t *first)
{
    node_t *node = first;
    inst_t *inst = NULL;
    bool running = true;

    while (node && running) {
        inst = NODE_DATA_TO_PTR(node->data, inst_t *);
        running = inst->ios.output.type == IOT_PIPED;
        if (running)
            node = node->next;
    }
    return node;
}

bool execution_block(node_t *node_inst, shell_t *shell, exec_utils_t *utils)
{
    inst_t *inst = EXECUTION_GET_INST(node_inst);
    node_t *next = NULL;
    node_t *node = NULL;

    if (!inst || !shell || !utils)
        return false;
    else
        next = inst->value.block->instructions->first;
    do {
        node = get_high_node(next);
        if (!node)
            return false;
        execution_inst(node, shell, utils, EXEC_SUPERIOR);
        next = node->next;
    } while (next);
    return true;
}
