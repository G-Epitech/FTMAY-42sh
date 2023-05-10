/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** block
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "builtins/defs.h"
#include "execution/defs.h"
#include "parsing/parsing.h"
#include "types/node/node.h"
#include "types/inst/inst.h"
#include "types/shell/shell.h"
#include "execution/execution.h"

static void redirect_all_stdout(void)
{
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(execution_block_tests, simple_block, .init=redirect_all_stdout)
{
    shell_t *shell = shell_new(builtins_cmds);
    inst_t *block = parsing_get_main_block("echo try");
    node_t *node = node_new(NODE_DATA_FROM_PTR(block));
    exec_utils_t utils;
    
    execution_utils_init(&utils, NULL, EXEC_MAIN);
    cr_assert(execution_block(node, shell, &utils));
    cr_assert_stdout_eq_str("try\n");
    node_free(node, NULL);
    inst_free(block);
    shell_free(shell);
}

Test(execution_block_tests, simple_block_with_pipe, .init=redirect_all_stdout)
{
    shell_t *shell = shell_new(builtins_cmds);
    inst_t *block = parsing_get_main_block("echo try | cat -e");
    node_t *node = node_new(NODE_DATA_FROM_PTR(block));
    exec_utils_t utils;
    
    execution_utils_init(&utils, NULL, EXEC_MAIN);
    cr_assert(execution_block(node, shell, &utils));
    cr_assert_stdout_eq_str("try$\n");
    node_free(node, NULL);
    inst_free(block);
    shell_free(shell);
}

Test(execution_block_tests, simple_block_empty, .init=redirect_all_stdout)
{
    shell_t *shell = shell_new(builtins_cmds);
    inst_block_t *block = inst_block_new();
    inst_t *inst = inst_new();
    node_t *node = node_new(NODE_DATA_FROM_PTR(inst));
    exec_utils_t utils;
    
    inst->type = INS_BLOCK;
    inst->value.block = block;
    execution_utils_init(&utils, NULL, EXEC_MAIN);
    cr_assert_not(execution_block(node, shell, &utils));
    node_free(node, NULL);
    inst_free(inst);
    shell_free(shell);
}

Test(execution_block_tests, simple_block_with_null_shell, .init=redirect_all_stdout)
{
    inst_t *block = parsing_get_main_block("echo try | cat -e");
    node_t *node = node_new(NODE_DATA_FROM_PTR(block));
    exec_utils_t utils;
    
    execution_utils_init(&utils, NULL, EXEC_MAIN);
    cr_assert_not(execution_block(node, NULL, &utils));
    node_free(node, NULL);
    inst_free(block);
}

Test(execution_block_tests, simple_block_consecutive, .init=redirect_all_stdout)
{
    shell_t *shell = shell_new(builtins_cmds);
    inst_t *block = parsing_get_main_block("echo try; echo salut");
    node_t *node = node_new(NODE_DATA_FROM_PTR(block));
    exec_utils_t utils;
    
    execution_utils_init(&utils, NULL, EXEC_MAIN);
    cr_assert(execution_block(node, shell, &utils));
    cr_assert_stdout_eq_str("try\nsalut\n");
    node_free(node, NULL);
    inst_free(block);
    shell_free(shell);
}

Test(execution_block_tests, simple_block_with_null_utils, .init=redirect_all_stdout)
{
    shell_t *shell = shell_new(builtins_cmds);
    inst_t *block = parsing_get_main_block("echo try | cat -e");
    node_t *node = node_new(NODE_DATA_FROM_PTR(block));
    
    cr_assert_not(execution_block(node, shell, NULL));
    node_free(node, NULL);
    inst_free(block);
    shell_free(shell);
}

Test(execution_block_tests, simple_block_with_null_node, .init=redirect_all_stdout)
{
    shell_t *shell = shell_new(builtins_cmds);
    exec_utils_t utils;

    execution_utils_init(&utils, NULL, EXEC_MAIN);
    cr_assert_not(execution_block(NULL, shell, &utils));
    shell_free(shell);
}
