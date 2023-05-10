/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** next
*/

#include <unistd.h>
#include <stdbool.h>
#include "types/inst/defs.h"
#include "execution/execution.h"

bool execution_block_need_next(inst_t *inst, int code)
{
    separator_t sep = inst->separator;

    if ((sep == SP_OR && code != 0) || (sep == SP_AND && code == 0)
        || (sep == SP_BREAK)) {
        return true;
    }
    return false;
}

node_t *execution_block_skip_not_needed(node_t *current)
{
    node_t *node = current;
    node_t *next = NULL;
    inst_t *next_inst = NULL;
    inst_t *current_inst = NULL;

    while (!next && node) {
        next_inst = EXECUTION_GET_INST(node->next);
        current_inst = EXECUTION_GET_INST(node);
        if (next_inst && current_inst->separator != SP_BREAK) {
            node = node->next;
        } else {
            next = node->next;
            node = NULL;
        }
    }
    return next;
}

node_t *execution_block_get_next(node_t *current, int code)
{
    inst_t *inst = EXECUTION_NODE_TO_INST(current);
    node_t *next = NULL;

    if (!execution_block_need_next(inst, code))
        next = execution_block_skip_not_needed(current);
    else
        next = current->next;
    return next;
}
