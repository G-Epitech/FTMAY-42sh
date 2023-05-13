/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** fd
*/

#include <stdio.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/resource.h>
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

Test(execution_handle_status_tests, simple_command,
.init=cr_redirect_stdout)
{
    shell_t *shell = shell_new(builtins_cmds);
    inst_t *block = parsing_get_main_block("echo 12");
    inst_t *inst = NODE_DATA_TO_PTR(block->value.block->instructions->first->data, inst_t *);
    node_t *node = node_new(NODE_DATA_FROM_PTR(inst));
    exec_utils_t utils;

    execution_utils_init(&utils, NULL, EXEC_SUPERIOR);
    execution_inst_get_redirections(inst, &utils);
    execution_cmd_prepare(node, shell);
    execution_inst_launch(node, shell, &utils);
    cr_assert(execution_inst_handle_status(inst, &utils));
    cr_assert(inst->exit_code == SHELL_EXIT_SUCCESS);
    cr_assert_stdout_eq_str("12\n"); 
}

Test(execution_handle_status_tests, simple_command_exit1,
.init=cr_redirect_stdout)
{
    shell_t *shell = shell_new(builtins_cmds);
    inst_t *block = parsing_get_main_block("false");
    inst_t *inst = NODE_DATA_TO_PTR(block->value.block->instructions->first->data, inst_t *);
    node_t *node = node_new(NODE_DATA_FROM_PTR(inst));
    exec_utils_t utils;

    execution_utils_init(&utils, NULL, EXEC_SUPERIOR);
    execution_inst_get_redirections(inst, &utils);
    execution_cmd_prepare(node, shell);
    execution_inst_launch(node, shell, &utils);
    cr_assert(execution_inst_handle_status(inst, &utils));
    cr_assert(inst->exit_code == 1);
}

Test(execution_handle_status_tests, simple_signal, .init=cr_redirect_stderr)
{
    shell_t *shell = shell_new(builtins_cmds);
    inst_t *block = parsing_get_main_block("./tests/utils/my_sig.out 6");
    inst_t *inst = NODE_DATA_TO_PTR(block->value.block->instructions->first->data, inst_t *);
    node_t *node = node_new(NODE_DATA_FROM_PTR(inst));
    int sig = SIGABRT;
    exec_utils_t utils;

    execution_utils_init(&utils, NULL, EXEC_SUPERIOR);
    execution_inst_get_redirections(inst, &utils);
    execution_cmd_prepare(node, shell);
    execution_inst_launch(node, shell, &utils);
    cr_assert(execution_inst_handle_status(inst, &utils));
    cr_assert(inst->exit_code == EXECUTION_SIG_EXITCODE(sig));
}

Test(execution_handle_status_tests, with_core_dump, .init=cr_redirect_stderr)
{
    shell_t *shell = shell_new(builtins_cmds);
    inst_t *block = parsing_get_main_block("./tests/utils/my_sig.out 11 true");
    inst_t *inst = NODE_DATA_TO_PTR(block->value.block->instructions->first->data, inst_t *);
    node_t *node = node_new(NODE_DATA_FROM_PTR(inst));
    int sig = SIGSEGV;
    exec_utils_t utils;

    execution_utils_init(&utils, NULL, EXEC_SUPERIOR);
    execution_inst_get_redirections(inst, &utils);
    execution_cmd_prepare(node, shell);
    execution_inst_launch(node, shell, &utils);
    cr_assert(execution_inst_handle_status(inst, &utils));
    cr_assert(inst->exit_code == EXECUTION_SIG_EXITCODE(sig));
    cr_assert_stderr_eq_str("Segmentation fault (core dumped)\n");
}

Test(execution_handle_status_tests, with_null_inst, .init=cr_redirect_stderr)
{
    exec_utils_t utils;

    cr_assert_not(execution_inst_handle_status(NULL, &utils));
}

Test(execution_handle_status_tests, with_null_utils)
{
    shell_t *shell = shell_new(builtins_cmds);
    inst_t *block = parsing_get_main_block("./tests/utils/my_sig.out 11");
    inst_t *inst = NODE_DATA_TO_PTR(block->value.block->instructions->first->data, inst_t *);
    node_t *node = node_new(NODE_DATA_FROM_PTR(inst));
    exec_utils_t utils;

    execution_utils_init(&utils, NULL, EXEC_SUPERIOR);
    execution_inst_get_redirections(inst, &utils);
    execution_cmd_prepare(node, shell);
    execution_inst_launch(node, shell, &utils);
    cr_assert_not(execution_inst_handle_status(inst, NULL));
}


Test(execution_handle_status_tests, with_max_code, .init=cr_redirect_stderr)
{
    shell_t *shell = shell_new(builtins_cmds);
    inst_t *block = parsing_get_main_block("./tests/utils/my_sig.out 10");
    inst_t *inst = NODE_DATA_TO_PTR(block->value.block->instructions->first->data, inst_t *);
    node_t *node = node_new(NODE_DATA_FROM_PTR(inst));
    exec_utils_t utils;

    execution_utils_init(&utils, NULL, EXEC_SUPERIOR);
    execution_inst_get_redirections(inst, &utils);
    execution_cmd_prepare(node, shell);
    execution_inst_launch(node, shell, &utils);
    utils.status = 255;
    cr_assert(execution_inst_handle_status(inst, &utils));
}

Test(execution_handle_status_tests, with_null_args)
{
    cr_assert_not(execution_inst_handle_status(NULL, NULL));
}
