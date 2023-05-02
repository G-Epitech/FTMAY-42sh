/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** separator
*/

#include <string.h>
#include <criterion/criterion.h>
#include "types/inst/inst.h"
#include "parsing/parsing.h"
#include "types/parsing_utils/parsing_utils.h"

Test(parsing_separator, and_separator)
{
    parsing_utils_t *utils = parsing_utils_new("ls && ls");
    inst_block_t *test_inst_block = inst_block_new();
    inst_t *test_inst = inst_new();

    inst_append(test_inst_block, test_inst);
    utils->index_parsing = 3;
    parsing_separator_handler(utils, NODE_DATA_TO_PTR(test_inst_block->instructions->first->data, inst_t *));
    cr_assert_eq(test_inst->separator, SP_AND);
}

Test(parsing_separator, ou_separator)
{
    parsing_utils_t *utils = parsing_utils_new("ls || ls");
    inst_block_t *test_inst_block = inst_block_new();
    inst_t *test_inst = inst_new();

    inst_append(test_inst_block, test_inst);
    utils->index_parsing = 3;
    parsing_separator_handler(utils, NODE_DATA_TO_PTR(test_inst_block->instructions->first->data, inst_t *));
    cr_assert_eq(test_inst->separator, SP_OR);
}

Test(parsing_separator, good_return_ou_separator)
{
    parsing_utils_t *utils = parsing_utils_new("ls || ls");
    inst_block_t *test_inst_block = inst_block_new();
    inst_t *test_inst = inst_new();
    bool test = false;

    inst_append(test_inst_block, test_inst);
    utils->index_parsing = 3;
    test = parsing_separator_handler(utils, NODE_DATA_TO_PTR(test_inst_block->instructions->first->data, inst_t *));
    cr_assert_eq(test, true);
}

Test(parsing_separator, bad_return_ou_separator)
{
    parsing_utils_t *utils = parsing_utils_new("ls || || ls");
    inst_block_t *test_inst_block = inst_block_new();
    inst_t *test_inst = inst_new();
    bool test = false;

    inst_append(test_inst_block, test_inst);
    utils->index_parsing = 3;
    parsing_separator_handler(utils, NODE_DATA_TO_PTR(test_inst_block->instructions->first->data, inst_t *));
    utils->index_parsing = 6;
    test = parsing_separator_handler(utils, NODE_DATA_TO_PTR(test_inst_block->instructions->first->data, inst_t *));
    cr_assert_eq(test, false);
}

Test(parsing_separator, good_return_and_separator)
{
    parsing_utils_t *utils = parsing_utils_new("ls && ls");
    inst_block_t *test_inst_block = inst_block_new();
    inst_t *test_inst = inst_new();
    bool test = false;

    inst_append(test_inst_block, test_inst);
    utils->index_parsing = 3;
    test = parsing_separator_handler(utils, NODE_DATA_TO_PTR(test_inst_block->instructions->first->data, inst_t *));
    cr_assert_eq(test, true);
}

Test(parsing_separator, bad_return_and_separator)
{
    parsing_utils_t *utils = parsing_utils_new("ls && && ls");
    inst_block_t *test_inst_block = inst_block_new();
    inst_t *test_inst = inst_new();
    bool test = false;

    inst_append(test_inst_block, test_inst);
    utils->index_parsing = 3;
    parsing_separator_handler(utils, NODE_DATA_TO_PTR(test_inst_block->instructions->first->data, inst_t *));
    utils->index_parsing = 6;
    test = parsing_separator_handler(utils, NODE_DATA_TO_PTR(test_inst_block->instructions->first->data, inst_t *));
    cr_assert_eq(test, false);
}

