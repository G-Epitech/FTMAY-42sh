/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** separator
*/

#include <stdio.h>
#include <string.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "types/inst/inst.h"
#include "parsing/parsing.h"
#include "types/parsing_utils/parsing_utils.h"

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

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

Test(parsing_separator, bad_return_ou_separator, .init=redirect_all_stdout)
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

Test(parsing_separator, bad_return_and_separator, .init=redirect_all_stdout)
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

Test(parsing_separator, forgot_cmd_after_separator_and, .init=redirect_all_stdout)
{
    parsing_utils_t *utils = parsing_utils_new("ls && ");
    inst_block_t *test_inst_block = inst_block_new();
    inst_t *test_inst = inst_new();
    bool test = false;

    inst_append(test_inst_block, test_inst);
    utils->index_parsing = 3;
    parsing_separator_handler(utils, NODE_DATA_TO_PTR(test_inst_block->instructions->first->data, inst_t *));
    parsing_analyse_data(utils, test_inst_block, NODE_DATA_TO_PTR(test_inst_block->instructions->first->data, inst_t *));
    test = parsing_break_separator(NODE_DATA_TO_PTR(test_inst_block->instructions->first->data, inst_t *));
    cr_assert_eq(test, false);
}

Test(parsing_separator, forgot_cmd_after_separator_ou, .init=redirect_all_stdout)
{
    parsing_utils_t *utils = parsing_utils_new("ls || ");
    inst_block_t *test_inst_block = inst_block_new();
    inst_t *test_inst = inst_new();
    bool test = false;

    inst_append(test_inst_block, test_inst);
    utils->index_parsing = 3;
    parsing_separator_handler(utils, NODE_DATA_TO_PTR(test_inst_block->instructions->first->data, inst_t *));
    parsing_analyse_data(utils, test_inst_block, NODE_DATA_TO_PTR(test_inst_block->instructions->first->data, inst_t *));
    test = parsing_break_separator(NODE_DATA_TO_PTR(test_inst_block->instructions->first->data, inst_t *));
    cr_assert_eq(test, false);
}

Test(parsing_separator, semicolon_after_cmd)
{
    parsing_utils_t *utils = parsing_utils_new("ls;");
    inst_block_t *test_inst_block = inst_block_new();
    inst_t *test_inst = inst_new();

    inst_append(test_inst_block, test_inst);
    utils->index_parsing = 2;
    parsing_break_separator(NODE_DATA_TO_PTR(test_inst_block->instructions->first->data, inst_t *));
    cr_assert_eq(test_inst->separator, SP_BREAK);
}

Test(parsing_separator, end_of_input)
{
    parsing_utils_t *utils = parsing_utils_new("ls");
    inst_block_t *test_inst_block = inst_block_new();
    inst_t *test_inst = inst_new();

    inst_append(test_inst_block, test_inst);
    utils->index_parsing = 2;
    parsing_break_separator(NODE_DATA_TO_PTR(test_inst_block->instructions->first->data, inst_t *));
    cr_assert_eq(test_inst->separator, SP_BREAK);
}

Test(parsing_separator, test_with_parsing_analyse_data)
{
    parsing_utils_t *utils = parsing_utils_new("ls && ls");
    inst_block_t *test_inst_block = inst_block_new();
    inst_t *test_inst = inst_new();

    inst_append(test_inst_block, test_inst);
    utils->index_parsing = 3;
    parsing_analyse_data(utils, test_inst_block, NODE_DATA_TO_PTR(test_inst_block->instructions->first->data, inst_t *));
    cr_assert_eq(test_inst->separator, SP_AND);
}

Test(parsing_separator, test_with_parsing_analyse_data_end_semicolon, .init=redirect_all_stdout)
{
    parsing_utils_t *utils = parsing_utils_new("ls &&;");
    inst_block_t *test_inst_block = inst_block_new();
    inst_t *test_inst = inst_new();
    bool test_return = false;

    inst_append(test_inst_block, test_inst);
    utils->index_parsing = 3;
    test_return = parsing_analyse_data(utils, test_inst_block, test_inst);
    cr_assert_eq(test_return, false);
}

Test(parsing_separator, test_with_parsing_analyse_data_invalid_null_cmd, .init=redirect_all_stdout)
{
    parsing_utils_t *utils = parsing_utils_new("ls && &&");
    inst_block_t *test_inst_block = inst_block_new();
    inst_t *test_inst = inst_new();
    bool test_return = false;

    inst_append(test_inst_block, test_inst);
    utils->index_parsing = 3;
    test_return = parsing_analyse_data(utils, test_inst_block, test_inst);
    cr_assert_eq(test_return, true);
    test_return = parsing_analyse_data(utils, test_inst_block, test_inst);
    cr_assert_eq(test_return, false);
}
