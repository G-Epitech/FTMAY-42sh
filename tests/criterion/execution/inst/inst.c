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

Test(execution_inst_tests, simple_builtin, .init=cr_redirect_stdout)
{
    shell_t *shell = shell_new(builtins_cmds);
    inst_t *block = parsing_get_main_block("cd ..");
    inst_t *inst = NODE_DATA_TO_PTR(block->value.block->instructions->first->data, inst_t *);
    node_t *node = node_new(NODE_DATA_FROM_PTR(inst));

    execution_inst(node, shell, NULL, EXEC_SUPERIOR);
    cr_assert(shell->exit_code == SHELL_EXIT_SUCCESS);
    shell_free(shell);
    inst_free(block);
    node_free(node, NULL);
}

Test(execution_inst_tests, simple_blocks, .init=cr_redirect_stdout)
{
    shell_t *shell = shell_new(builtins_cmds);
    inst_t *block = parsing_get_main_block("(echo hello; echo world;) | cat -e");
    node_t *node = node_new(NODE_DATA_FROM_PTR(block));

    execution_inst(node, shell, NULL, EXEC_SUPERIOR);
    cr_assert(shell->exit_code == SHELL_EXIT_SUCCESS);
    cr_assert_stdout_eq_str("hello$\nworld$\n");
    shell_free(shell);
    inst_free(block);
    node_free(node, NULL);
}

Test(execution_inst_tests, null_node_inst, .init=cr_redirect_stdout)
{
    shell_t *shell = shell_new(builtins_cmds);

    execution_inst(NULL, shell, NULL, EXEC_SUPERIOR);
    cr_assert(shell->exit_code == SHELL_EXIT_ERROR);
    shell_free(shell);
}

Test(execution_inst_tests, node_with_null_inst, .init=cr_redirect_stdout)
{
    shell_t *shell = shell_new(builtins_cmds);
    node_t *node = node_new(NODE_DATA_FROM_PTR(NULL));

    execution_inst(node, shell, NULL, EXEC_SUPERIOR);
    cr_assert(shell->exit_code == SHELL_EXIT_ERROR);
    shell_free(shell);
    node_free(node, NULL);
}

Test(execution_inst_tests, node_with_none_inst, .init=cr_redirect_stdout)
{
    shell_t *shell = shell_new(builtins_cmds);
    inst_t *inst = inst_new();
    inst->type = INS_NONE;
    node_t *node = node_new(NODE_DATA_FROM_PTR(inst));

    execution_inst(node, shell, NULL, EXEC_SUPERIOR);
    cr_assert(shell->exit_code == SHELL_EXIT_ERROR);
    shell_free(shell);
    inst_free(inst);
    node_free(node, NULL);
}

Test(execution_inst_tests, simple_absolute_cmd, .init=cr_redirect_stdout)
{
    shell_t *shell = shell_new(builtins_cmds);
    inst_t *block = parsing_get_main_block("echo test");
    inst_t *inst = NODE_DATA_TO_PTR(block->value.block->instructions->first->data, inst_t *);
    node_t *node = node_new(NODE_DATA_FROM_PTR(inst));

    execution_inst(node, shell, NULL, EXEC_SUPERIOR);
    cr_assert(shell->exit_code == SHELL_EXIT_SUCCESS);
    cr_assert_stdout_eq_str("test\n");
    shell_free(shell);
    inst_free(block);
    node_free(node, NULL);
}

Test(execution_inst_tests, bad_absolute_cmd)
{
    shell_t *shell = shell_new(builtins_cmds);
    inst_t *block = parsing_get_main_block("echo test");
    inst_t *inst = NODE_DATA_TO_PTR(block->value.block->instructions->first->data, inst_t *);
    node_t *node = node_new(NODE_DATA_FROM_PTR(inst));

    cmd_free(inst->value.cmd);
    inst->value.cmd = NULL;
    execution_inst(node, shell, NULL, EXEC_SUPERIOR);
    cr_assert(inst->exit_code == SHELL_EXIT_ERROR);
    shell_free(shell);
    inst_free(block);
    node_free(node, NULL);
}
