/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** execution
*/

#include "execution/defs.h"
#include "types/inst/inst.h"
#include "types/shell/shell.h"
#include "execution/execution.h"
#include "execution/redirections.h"

static bool prevent_errors(inst_t *inst, shell_t *shell)
{
    if (!inst)
        shell->exit_code = SHELL_EXIT_ERROR;
    else if (inst->type != INS_BLOCK && inst->type != INS_CMD)
        shell->exit_code = SHELL_EXIT_ERROR;
    return shell->exit_code == SHELL_EXIT_ERROR;
}

void execution_inst(node_t *node_inst, shell_t *shell, exec_utils_t *herited,
exec_caller_t caller)
{
    inst_t *inst = EXECUTION_GET_INST(node_inst);
    bool launch = true;
    exec_utils_t utils;

    if (prevent_errors(inst, shell))
        return;
    execution_utils_init(&utils, herited, caller);
    if (inst->type == INS_CMD)
        launch = execution_cmd_prepare(node_inst, shell);
    execution_inst_get_redirections(inst, &utils);
    execution_inst_previous_piped(node_inst, shell, &utils);
    if (launch)
        execution_inst_launch(node_inst, shell, &utils);
    else
        utils.status = W_EXITCODE(SHELL_EXIT_ERROR, 0);
    execution_inst_handle_status(inst, &utils);
}
