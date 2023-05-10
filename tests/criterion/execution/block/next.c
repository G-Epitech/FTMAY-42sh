/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** next
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

Test(execution_block_get_next_tests, basic_separator)
{
    inst_t *block = parsing_get_main_block("false; true; echo 12");
    node_t *node = block->value.block->instructions->first;

    node = execution_block_get_next(node, 1);
    cr_assert_not_null(node);
    node = execution_block_get_next(node, 0);
    cr_assert_not_null(node);
    node = execution_block_get_next(node, 0);
    cr_assert_null(node);
    inst_free(block);
}

Test(execution_block_get_next_tests, basic_separator_with_or)
{
    inst_t *block = parsing_get_main_block("false || echo try; echo 12");
    node_t *node = block->value.block->instructions->first;

    node = execution_block_get_next(node, 1);
    cr_assert_not_null(node);
    node = execution_block_get_next(node, 0);
    cr_assert_not_null(node);
    node = execution_block_get_next(node, 0);
    cr_assert_null(node);
    inst_free(block);
}

Test(execution_block_get_next_tests, basic_separator_with_and)
{
    inst_t *block = parsing_get_main_block("false && echo try; echo 12");
    node_t *node = block->value.block->instructions->first;

    node = execution_block_get_next(node, 1);
    cr_assert_not_null(node);
    node = execution_block_get_next(node, 0);
    cr_assert_null(node);
    inst_free(block);
    node_free(node, NULL);
}

Test(execution_block_get_next_tests, basic_separator_with_or_2)
{
    inst_t *block = parsing_get_main_block("true || echo try; echo 12");
    node_t *node = block->value.block->instructions->first;

    node = execution_block_get_next(node, 0);
    cr_assert_not_null(node);
    node = execution_block_get_next(node, 0);
    cr_assert_null(node);
    inst_free(block);
}

Test(execution_block_get_next_tests, basic_separator_with_successive_or)
{
    inst_t *block = parsing_get_main_block("true || echo try || echo 12");
    node_t *node = block->value.block->instructions->first;

    node = execution_block_get_next(node, 0);
    cr_assert_null(node);
    inst_free(block);
}

Test(execution_block_get_next_tests, need_next_basic_or)
{
    inst_t *block = parsing_get_main_block("true || echo try");
    node_t *node = block->value.block->instructions->first;
    inst_t *inst = EXECUTION_NODE_TO_INST(node);

    cr_assert_not(execution_block_need_next(inst, 0));
    inst_free(block);
}

Test(execution_block_get_next_tests, need_next_basic_and)
{
    inst_t *block = parsing_get_main_block("true && echo try");
    node_t *node = block->value.block->instructions->first;
    inst_t *inst = EXECUTION_NODE_TO_INST(node);

    cr_assert(execution_block_need_next(inst, 0));
    inst_free(block);
}

Test(execution_block_get_next_tests, need_next_basic_break)
{
    inst_t *block = parsing_get_main_block("true; echo try");
    node_t *node = block->value.block->instructions->first;
    inst_t *inst = EXECUTION_NODE_TO_INST(node);

    cr_assert(execution_block_need_next(inst, 0));
    inst_free(block);
}
