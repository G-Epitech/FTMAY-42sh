/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** prepare
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "builtins/defs.h"
#include "utils/malloc2.h"
#include "execution/defs.h"
#include "parsing/parsing.h"
#include "types/node/node.h"
#include "types/inst/inst.h"
#include "types/shell/shell.h"
#include "execution/execution.h"

Test(execution_cmd_prepare_tests, basic)
{
    shell_t *shell = shell_new(builtins_cmds);
    cmd_t *command = cmd_new();
    inst_t *inst = inst_new();
    node_t *node = NULL;

    inst->type = INS_CMD;
    inst->value.cmd = command;
    command->input = strdup("echo \"super $PWD\"");
    node = node_new(NODE_DATA_FROM_PTR(inst));
    cr_assert(execution_cmd_prepare(node, shell));
    inst_free(inst);
    node_free(node, NULL);
    shell_free(shell);
}

Test(execution_cmd_prepare_tests, null_inst)
{
    shell_t *shell = shell_new(builtins_cmds);

    cr_assert_not(execution_cmd_prepare(NULL, shell));
    shell_free(shell);
}

Test(execution_cmd_prepare_tests, null_shell)
{
    cmd_t *command = cmd_new();
    inst_t *inst = inst_new();
    node_t *node = NULL;

    inst->type = INS_CMD;
    inst->value.cmd = command;
    command->input = strdup("echo \"super $PWD\"");
    cr_assert_not(execution_cmd_prepare(node, NULL));
    inst_free(inst);
    node_free(node, NULL);
}

Test(execution_cmd_prepare_tests, inst_not_cmd)
{
    shell_t *shell = shell_new(builtins_cmds);
    inst_t *inst = inst_new();
    node_t *node = NULL;

    inst->type = INS_BLOCK;
    node = node_new(NODE_DATA_FROM_PTR(inst));
    cr_assert_not(execution_cmd_prepare(node, shell));
    inst_free(inst);
    node_free(node, NULL);
    shell_free(shell);
}

Test(execution_cmd_prepare_tests, inst_null_cmd)
{
    shell_t *shell = shell_new(builtins_cmds);
    inst_t *inst = inst_new();
    node_t *node = NULL;

    inst->type = INS_CMD;
    inst->value.cmd = NULL;
    node = node_new(NODE_DATA_FROM_PTR(inst));
    cr_assert_not(execution_cmd_prepare(node, shell));
    inst_free(inst);
    node_free(node, NULL);
    shell_free(shell);
}

Test(execution_cmd_prepare_tests, set_args_fail)
{
    shell_t *shell = shell_new(builtins_cmds);
    cmd_t *command = cmd_new();
    inst_t *inst = inst_new();
    node_t *node = NULL;

    inst->type = INS_CMD;
    inst->value.cmd = command;
    command->input = strdup("echo \"super $PWD\"");
    node = node_new(NODE_DATA_FROM_PTR(inst));
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_FAIL);
    cr_assert_not(execution_cmd_prepare(node, shell));
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_NORMAL);
    inst_free(inst);
    node_free(node, NULL);
    shell_free(shell);
}

Test(execution_cmd_prepare_tests, determine_target_fail, .init=cr_redirect_stderr)
{
    shell_t *shell = shell_new(builtins_cmds);
    cmd_t *command = cmd_new();
    inst_t *inst = inst_new();
    node_t *node = NULL;

    inst->type = INS_CMD;
    inst->value.cmd = command;
    command->input = strdup("bonjour5342");
    node = node_new(NODE_DATA_FROM_PTR(inst));
    cr_assert_not(execution_cmd_prepare(node, shell));
    fflush(stderr);
    cr_assert_stderr_eq_str("bonjour5342: Command not found.\n");
    inst_free(inst);
    node_free(node, NULL);
    shell_free(shell);
}

Test(execution_cmd_prepare_tests, can_be_done_fail, .init=cr_redirect_stderr)
{
    shell_t *shell = shell_new(builtins_cmds);
    cmd_t *command = cmd_new();
    inst_t *inst = inst_new();
    node_t *node = NULL;

    inst->type = INS_CMD;
    inst->value.cmd = command;
    command->input = strdup("./tests/utils/sh/forbidden.sh");
    node = node_new(NODE_DATA_FROM_PTR(inst));
    cr_assert_not(execution_cmd_prepare(node, shell));
    fflush(stderr);
    cr_assert_stderr_eq_str("./tests/utils/sh/forbidden.sh: Permission denied.\n");
    inst_free(inst);
    node_free(node, NULL);
    shell_free(shell);
}
