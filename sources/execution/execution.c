/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** execution
*/

#include <sys/wait.h>
#include "execution/defs.h"
#include "types/inst/inst.h"
#include "types/node/node.h"
#include "types/shell/shell.h"
#include "execution/execution.h"

bool execution_main_block(inst_t *block, shell_t *shell)
{
    exec_utils_t utils;
    node_t *node = node_new(NODE_DATA_FROM_PTR(block));

    if (!node)
        return false;
    execution_utils_init(&utils, NULL, EXEC_MAIN);
    execution_block(node, shell, &utils);
    node_free(node, NULL);
    shell_set_exit_code(shell, utils.status);
    return true;
}
