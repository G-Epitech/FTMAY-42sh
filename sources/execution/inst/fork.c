/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** fork
*/

#include <stdbool.h>
#include <sys/wait.h>
#include "execution/defs.h"
#include "types/inst/inst.h"
#include "types/shell/shell.h"
#include "execution/execution.h"

bool execution_inst_fork_needed(inst_t *inst, exec_utils_t *utils)
{
    if (!inst)
        return false;
    if (utils->level > 0)
        return true;
    if (inst->type == INS_BLOCK && utils->level >= 0)
        return true;
    if (inst->type == INS_CMD) {
        if (inst->value.cmd->type == CMD_ABSOLUTE ||
            inst->value.cmd->type == CMD_SYSTEM) {
            return true;
        }
    }
    return false;
}

static void handle_forked_processus(node_t *node_inst, shell_t *shell,
exec_utils_t *utils)
{
    inst_t *inst = EXECUTION_NODE_TO_INST(node_inst);

    execution_inst_set_fd(inst, utils);
    if (inst->type == INS_BLOCK) {
        execution_block(node_inst, shell, utils);
    } else if (inst->type == INS_CMD) {
        inst->value.cmd->forked = true;
        execution_cmd_launch(node_inst, shell, utils);
    }
    exit(utils->status);
}

void execution_inst_wait_main_fork(pid_t pid, exec_utils_t *utils)
{
    int status = 0;
    pid_t signaler = 0;

    while (pid != signaler) {
        signaler = wait(&status);
        if (signaler == pid)
            utils->status = status;
        if (signaler != pid && signaler != 0 && status)
            utils->sub_status = status;
    }
    if (utils->status == SHELL_EXIT_SUCCESS)
        utils->status = utils->sub_status;
}

void execution_inst_launch_fork(node_t *node_inst, shell_t *shell,
exec_utils_t *utils)
{
    inst_t *inst = EXECUTION_NODE_TO_INST(node_inst);
    pid_t pid = 0;

    pid = fork();
    if (pid == 0) {
        handle_forked_processus(node_inst, shell, utils);
    } else {
        execution_inst_set_parent_fd(inst, utils);
        if (utils->level == 0)
            execution_inst_wait_main_fork(pid, utils);
    }
    execution_inst_close_fd(utils);
}
