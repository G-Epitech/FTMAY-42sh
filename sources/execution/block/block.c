/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** block
*/

#include "unistd.h"
#include "types/inst/defs.h"
#include "execution/execution.h"

static node_t *get_last_node(node_t *node)
{
    node_t *tmp = node;
    inst_t *inst = NULL;
    bool running = true;

    while (tmp && running) {
        inst = NODE_DATA_TO_PTR(tmp->data, inst_t *);
        running = inst->ios.output.type == IOT_PIPED;
        tmp = tmp->next;
    }
    return tmp;
}

static void fork_node(node_t *node, int level)
{
    inst_t *instruction = NULL;

    if (!node)
        return;
    instruction = NODE_DATA_TO_PTR(node->data, inst_t *);
    if (instruction->type == INS_CMD && level > 0)
        instruction->value.cmd->forked = true;
}

void execution_block(node_t *node, int level)
{
    
}
