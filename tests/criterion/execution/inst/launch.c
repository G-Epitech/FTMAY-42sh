/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** fd
*/

#include <stdlib.h>
#include <limits.h>
#include <string.h>
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

Test(execution_inst_launch_tests, launch_direct_non_fork, .init=cr_redirect_stdout)
{
    shell_t *shell = shell_new(builtins_cmds);
    char *pwd = malloc(PATH_MAX);
    char *test = malloc(PATH_MAX);
    inst_t *block = parsing_get_main_block("cd /");
    inst_t *inst = NODE_DATA_TO_PTR(block->value.block->instructions->first->data, inst_t *);
    node_t *node = node_new(NODE_DATA_FROM_PTR(inst));
    exec_utils_t utils;

    getcwd(pwd, PATH_MAX);
    execution_utils_init(&utils, NULL, EXEC_SUPERIOR);
    cr_assert(execution_cmd_prepare(node, shell));
    execution_inst_launch_non_fork(node, shell, &utils);
    cr_assert(inst->exit_code == SHELL_EXIT_SUCCESS);
    getcwd(test, PATH_MAX);
    cr_assert_str_eq(test, "/");
    inst_free(inst);
    node_free(node, NULL);
    shell_free(shell);
    chdir(pwd);
    free(pwd);
    free(test);
}

Test(execution_inst_launch_tests, launch_fork, .init=cr_redirect_stdout)
{
    shell_t *shell = shell_new(builtins_cmds);
    inst_t *block = parsing_get_main_block("/bin/echo HELLO_IN_UPPER");
    inst_t *inst = NODE_DATA_TO_PTR(block->value.block->instructions->first->data, inst_t *);
    node_t *node = node_new(NODE_DATA_FROM_PTR(inst));
    exec_utils_t utils;

    execution_utils_init(&utils, NULL, EXEC_SUPERIOR);
    cr_assert(execution_cmd_prepare(node, shell));
    execution_inst_launch(node, shell, &utils);
    cr_assert(inst->exit_code == SHELL_EXIT_SUCCESS);
    cr_assert_stdout_eq_str("HELLO_IN_UPPER\n");
    inst_free(inst);
    node_free(node, NULL);
    shell_free(shell);
}

Test(execution_inst_launch_tests, launc_indirect_non_fork, .init=cr_redirect_stdout)
{
    shell_t *shell = shell_new(builtins_cmds);
    char *pwd = malloc(PATH_MAX);
    char *test = malloc(PATH_MAX);
    inst_t *block = parsing_get_main_block("cd /");
    inst_t *inst = NODE_DATA_TO_PTR(block->value.block->instructions->first->data, inst_t *);
    node_t *node = node_new(NODE_DATA_FROM_PTR(inst));
    exec_utils_t utils;

    getcwd(pwd, PATH_MAX);
    execution_utils_init(&utils, NULL, EXEC_SUPERIOR);
    cr_assert(execution_cmd_prepare(node, shell));
    execution_inst_launch(node, shell, &utils);
    cr_assert(inst->exit_code == SHELL_EXIT_SUCCESS);
    getcwd(test, PATH_MAX);
    cr_assert_str_eq(test, "/");
    inst_free(inst);
    node_free(node, NULL);
    shell_free(shell);
    chdir(pwd);
    free(pwd);
    free(test);
}
