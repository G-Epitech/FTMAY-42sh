/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** fd
*/

#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "builtins/defs.h"
#include "execution/defs.h"
#include "types/node/node.h"
#include "types/inst/inst.h"
#include "parsing/parsing.h"
#include "types/shell/shell.h"
#include "execution/execution.h"
#include "execution/redirections.h"

Test(execution_inst_fork_nedeed_tests, simple_builtin, .init=cr_redirect_stdout)
{
    shell_t *shell = shell_new(builtins_cmds);
    inst_t *block = parsing_get_main_block("cd ..");
    inst_t *inst = NODE_DATA_TO_PTR(block->value.block->instructions->first->data, inst_t *);
    node_t *node = node_new(NODE_DATA_FROM_PTR(inst));
    exec_utils_t utils;

    execution_cmd_prepare(node, shell);
    execution_utils_init(&utils, NULL, EXEC_MAIN);
    cr_assert_not(execution_inst_fork_needed(inst, &utils));
    shell_free(shell);
    inst_free(block);
}

Test(execution_inst_fork_nedeed_tests, simple_system, .init=cr_redirect_stdout)
{
    shell_t *shell = shell_new(builtins_cmds);
    inst_t *block = parsing_get_main_block("ls");
    inst_t *inst = NODE_DATA_TO_PTR(block->value.block->instructions->first->data, inst_t *);
    node_t *node = node_new(NODE_DATA_FROM_PTR(inst));
    exec_utils_t utils;

    execution_cmd_prepare(node, shell);
    execution_utils_init(&utils, NULL, EXEC_SUPERIOR);
    cr_assert(execution_inst_fork_needed(inst, &utils));
    shell_free(shell);
    inst_free(block);
    node_free(node, NULL);
}

Test(execution_inst_fork_nedeed_tests, simple_absolute, .init=cr_redirect_stdout)
{
    shell_t *shell = shell_new(builtins_cmds);
    inst_t *block = parsing_get_main_block("/bin/ls");
    inst_t *inst = NODE_DATA_TO_PTR(block->value.block->instructions->first->data, inst_t *);
    node_t *node = node_new(NODE_DATA_FROM_PTR(inst));
    exec_utils_t utils;

    execution_cmd_prepare(node, shell);
    execution_utils_init(&utils, NULL, EXEC_SUPERIOR);
    cr_assert(execution_inst_fork_needed(inst, &utils));
    shell_free(shell);
    inst_free(block);
    node_free(node, NULL);
}

Test(execution_inst_fork_nedeed_tests, null_node, .init=cr_redirect_stdout)
{
    exec_utils_t utils;

    execution_utils_init(&utils, NULL, EXEC_MAIN);
    cr_assert_not(execution_inst_fork_needed(NULL, &utils));
}

Test(execution_inst_fork_nedeed_tests, inst_level_sup_0, .init=cr_redirect_stdout)
{
    shell_t *shell = shell_new(builtins_cmds);
    inst_t *block = parsing_get_main_block("cd ..");
    inst_t *inst = NODE_DATA_TO_PTR(block->value.block->instructions->first->data, inst_t *);
    node_t *node = node_new(NODE_DATA_FROM_PTR(inst));
    exec_utils_t utils;

    execution_cmd_prepare(node, shell);
    execution_utils_init(&utils, NULL, EXEC_SUPERIOR);
    utils.level = 3;
    cr_assert(execution_inst_fork_needed(inst, &utils));
    shell_free(shell);
    inst_free(block);
    node_free(node, NULL);
}

Test(execution_inst_fork_nedeed_tests, inst_block, .init=cr_redirect_stdout)
{
    shell_t *shell = shell_new(builtins_cmds);
    inst_t *block = parsing_get_main_block("cd ..");
    node_t *node = node_new(NODE_DATA_FROM_PTR(block));
    exec_utils_t utils;

    execution_cmd_prepare(node, shell);
    execution_utils_init(&utils, NULL, EXEC_SUPERIOR);
    cr_assert(execution_inst_fork_needed(block, &utils));
    shell_free(shell);
    inst_free(block);
    node_free(node, NULL);
}

Test(execution_inst_fork_nedeed_tests, inst_main_block, .init=cr_redirect_stdout)
{
    shell_t *shell = shell_new(builtins_cmds);
    inst_t *block = parsing_get_main_block("cd ..");
    node_t *node = node_new(NODE_DATA_FROM_PTR(block));
    exec_utils_t utils;

    execution_cmd_prepare(node, shell);
    execution_utils_init(&utils, NULL, EXEC_MAIN);
    cr_assert_not(execution_inst_fork_needed(block, &utils));
    shell_free(shell);
    inst_free(block);
    node_free(node, NULL);
}

Test(execution_inst_fork_nedeed_tests, launch_fork_block, .init=cr_redirect_stdout)
{
    shell_t *shell = shell_new(builtins_cmds);
    inst_t *block = parsing_get_main_block("(echo SUPERCOOL)");
    inst_t *sub = NODE_DATA_TO_PTR(block->value.block->instructions->first->data, inst_t *);
    node_t *node = node_new(NODE_DATA_FROM_PTR(sub));
    exec_utils_t utils;

    execution_cmd_prepare(node, shell);
    execution_utils_init(&utils, NULL, EXEC_SUPERIOR);
    execution_inst_launch_fork(node, shell, &utils);
    cr_assert(WEXITSTATUS(utils.status) == 0);
    fflush(stdout);
    cr_assert_stdout_eq_str("SUPERCOOL\n");
    shell_free(shell);
    inst_free(block);
    node_free(node, NULL);
}

Test(execution_inst_fork_nedeed_tests, launch_fork_cmd, .init=cr_redirect_stdout)
{
    shell_t *shell = shell_new(builtins_cmds);
    inst_t *block = parsing_get_main_block("echo SUPERCOOL");
    inst_t *sub = NODE_DATA_TO_PTR(block->value.block->instructions->first->data, inst_t *);
    node_t *node = node_new(NODE_DATA_FROM_PTR(sub));
    exec_utils_t utils;

    execution_cmd_prepare(node, shell);
    execution_utils_init(&utils, NULL, EXEC_SUPERIOR);
    execution_inst_launch_fork(node, shell, &utils);
    cr_assert(WEXITSTATUS(utils.status) == 0);
    fflush(stdout);
    cr_assert_stdout_eq_str("SUPERCOOL\n");
    shell_free(shell);
    inst_free(block);
    node_free(node, NULL);
}
