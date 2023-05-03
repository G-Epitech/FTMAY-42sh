/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** pipe
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

Test(parsing_pipe, ambigous_redirect_with_redirection_before, .init=redirect_all_stdout)
{
    parsing_utils_t *utils = parsing_utils_new("grep l >test |");
    inst_block_t *test_inst_block = inst_block_new();
    inst_t *test_inst = inst_new();
    bool test_return = false;

    inst_append(test_inst_block, test_inst);
    utils->index_parsing = 7;
    parsing_redirection_handler(utils, NODE_DATA_TO_PTR(test_inst_block->instructions->first->data, inst_t *));
    test_return = parsing_pipes_handler(utils, test_inst_block);
    cr_assert_eq(test_return, false);
    cr_assert_stdout_eq_str("Ambiguous input redirect.\n");

}

Test(parsing_pipe, simple_pipe)
{
    parsing_utils_t *utils = parsing_utils_new("ls | grep l");
    inst_block_t *test_inst_block = inst_block_new();
    inst_t *test_inst = inst_new();
    bool test_return = false;

    inst_append(test_inst_block, test_inst);
    utils->index_parsing = 7;
    parsing_redirection_handler(utils, NODE_DATA_TO_PTR(test_inst_block->instructions->first->data, inst_t *));
    test_return = parsing_pipes_handler(utils, test_inst_block);
    cr_assert_eq(test_return, true);
}