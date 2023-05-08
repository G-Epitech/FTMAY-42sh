/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** redirection
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

Test(parsing_redirection, redirection_output_simple)
{
    parsing_utils_t *test = parsing_utils_new("> tmp_fic (ls -l -a | cat -e)");
    inst_block_t *test_inst_block = inst_block_new();
    inst_t *test_inst = inst_new();

    inst_append(test_inst_block, test_inst);
    parsing_redirection_handler(test, NODE_DATA_TO_PTR(test_inst_block->instructions->first->data, inst_t *));
    cr_assert_eq(test_inst->ios.output.type, IOT_SIMPLE);
    cr_assert_str_eq(test_inst->ios.output.path, "tmp_fic");
}

Test(parsing_redirection, redirection_input_simple)
{
    parsing_utils_t *test = parsing_utils_new("<        tmp_fic_flavien (ls -l -a | cat -e)");
    inst_block_t *test_inst_block = inst_block_new();
    inst_t *test_inst = inst_new();

    inst_append(test_inst_block, test_inst);
    parsing_redirection_handler(test, NODE_DATA_TO_PTR(test_inst_block->instructions->first->data, inst_t *));
    cr_assert_eq(test_inst->ios.input.type, IOT_SIMPLE);
    cr_assert_str_eq(test_inst->ios.input.path, "tmp_fic_flavien");
}

Test(parsing_redirection, redirection_output_double)
{
    parsing_utils_t *test = parsing_utils_new(">>        tmp_fic_Alavien    (ls -l -a | cat -e)");
    inst_block_t *test_inst_block = inst_block_new();
    inst_t *test_inst = inst_new();

    inst_append(test_inst_block, test_inst);
    parsing_redirection_handler(test, NODE_DATA_TO_PTR(test_inst_block->instructions->first->data, inst_t *));
    cr_assert_eq(test_inst->ios.output.type, IOT_DOUBLE);
    cr_assert_str_eq(test_inst->ios.output.path, "tmp_fic_Alavien");
}

Test(parsing_redirection, redirection_input_double)
{
    parsing_utils_t *test = parsing_utils_new("cat << test (ls -l -a | cat -e)");
    inst_block_t *test_inst_block = inst_block_new();
    inst_t *test_inst = inst_new();

    inst_append(test_inst_block, test_inst);
    test->index_parsing = 4;
    parsing_redirection_handler(test, NODE_DATA_TO_PTR(test_inst_block->instructions->first->data, inst_t *));
    cr_assert_eq(test_inst->ios.input.type, IOT_DOUBLE);
    cr_assert_str_eq(test_inst->ios.input.path, "test");
}

Test(parsing_redirection, bad_redirection_input_double, .init=redirect_all_stdout)
{
    parsing_utils_t *test = parsing_utils_new("cat <<< test (ls -l -a | cat -e)");
    inst_block_t *test_inst_block = inst_block_new();
    inst_t *test_inst = inst_new();
    bool good_redirection = false;

    inst_append(test_inst_block, test_inst);
    test->index_parsing = 4;
    good_redirection = parsing_redirection_handler(test, NODE_DATA_TO_PTR(test_inst_block->instructions->first->data, inst_t *));
    cr_assert_eq(good_redirection, false);
    cr_assert_stderr_eq_str("Missing name for redirect.\n");
}

Test(parsing_redirection, semicolon_separator)
{
    parsing_utils_t *test = parsing_utils_new("(ls -l -a | cat -e) > test; ls");
    inst_block_t *test_inst_block = inst_block_new();
    inst_t *test_inst = inst_new();

    inst_append(test_inst_block, test_inst);
    test->index_parsing = 20;
    parsing_redirection_handler(test, NODE_DATA_TO_PTR(test_inst_block->instructions->first->data, inst_t *));
    cr_assert_eq(test_inst->ios.output.type, IOT_SIMPLE);
    cr_assert_str_eq(test_inst->ios.output.path, "test");
}

Test(parsing_redirection, test_path_stoped_with_redirect)
{
    parsing_utils_t *test = parsing_utils_new("(ls -l -a | cat -e) > test> ls");
    inst_block_t *test_inst_block = inst_block_new();
    inst_t *test_inst = inst_new();

    inst_append(test_inst_block, test_inst);
    test->index_parsing = 20;
    parsing_redirection_handler(test, NODE_DATA_TO_PTR(test_inst_block->instructions->first->data, inst_t *));
    cr_assert_eq(test_inst->ios.output.type, IOT_SIMPLE);
    cr_assert_str_eq(test_inst->ios.output.path, "test");
}

Test(parsing_redirection, test_path_stoped_with_parenthese_open)
{
    parsing_utils_t *test = parsing_utils_new("(ls -l -a | cat -e) > test(;)");
    inst_block_t *test_inst_block = inst_block_new();
    inst_t *test_inst = inst_new();

    inst_append(test_inst_block, test_inst);
    test->index_parsing = 20;
    parsing_redirection_handler(test, NODE_DATA_TO_PTR(test_inst_block->instructions->first->data, inst_t *));
    cr_assert_eq(test_inst->ios.output.type, IOT_SIMPLE);
    cr_assert_str_eq(test_inst->ios.output.path, "test");
}

Test(parsing_redirection, test_path_stoped_with_parenthese_close)
{
    parsing_utils_t *test = parsing_utils_new("(ls > test)");
    inst_block_t *test_inst_block = inst_block_new();
    inst_t *test_inst = inst_new();

    inst_append(test_inst_block, test_inst);
    test->index_parsing = 4;
    parsing_redirection_handler(test, NODE_DATA_TO_PTR(test_inst_block->instructions->first->data, inst_t *));
    cr_assert_eq(test_inst->ios.output.type, IOT_SIMPLE);
    cr_assert_str_eq(test_inst->ios.output.path, "test");
}

Test(parsing_redirection, test_path_stoped_with_end)
{
    parsing_utils_t *test = parsing_utils_new("ls > test");
    inst_block_t *test_inst_block = inst_block_new();
    inst_t *test_inst = inst_new();

    inst_append(test_inst_block, test_inst);
    test->index_parsing = 3;
    parsing_redirection_handler(test, NODE_DATA_TO_PTR(test_inst_block->instructions->first->data, inst_t *));
    cr_assert_eq(test_inst->ios.output.type, IOT_SIMPLE);
    cr_assert_str_eq(test_inst->ios.output.path, "test");
}

Test(parsing_redirection, test_path_stoped_with_pipe)
{
    parsing_utils_t *test = parsing_utils_new("ls > test|");
    inst_block_t *test_inst_block = inst_block_new();
    inst_t *test_inst = inst_new();

    inst_append(test_inst_block, test_inst);
    test->index_parsing = 3;
    parsing_redirection_handler(test, NODE_DATA_TO_PTR(test_inst_block->instructions->first->data, inst_t *));
    cr_assert_eq(test_inst->ios.output.type, IOT_SIMPLE);
    cr_assert_str_eq(test_inst->ios.output.path, "test");
}

Test(parsing_redirection, test_get_path_with_tab)
{
    parsing_utils_t *test = parsing_utils_new("ls >\ttest");
    inst_block_t *test_inst_block = inst_block_new();
    inst_t *test_inst = inst_new();

    inst_append(test_inst_block, test_inst);
    test->index_parsing = 3;
    parsing_redirection_handler(test, NODE_DATA_TO_PTR(test_inst_block->instructions->first->data, inst_t *));
    cr_assert_eq(test_inst->ios.output.type, IOT_SIMPLE);
    cr_assert_str_eq(test_inst->ios.output.path, "test");
}

Test(parsing_redirection, test_ambigous_simple_right, .init=redirect_all_stdout)
{
    parsing_utils_t *test = parsing_utils_new("ls >> test>test");
    inst_block_t *test_inst_block = inst_block_new();
    inst_t *test_inst = inst_new();
    bool test_return = false;

    inst_append(test_inst_block, test_inst);
    test->index_parsing = 3;
    parsing_redirection_handler(test, NODE_DATA_TO_PTR(test_inst_block->instructions->first->data, inst_t *));
    test_return = parsing_redirection_handler(test, NODE_DATA_TO_PTR(test_inst_block->instructions->first->data, inst_t *));
    cr_assert_eq(test_return, false);
    cr_assert_stderr_eq_str("Ambiguous input redirect.\n");
}

Test(parsing_redirection, test_ambigous_simple_left, .init=redirect_all_stdout)
{
    parsing_utils_t *test = parsing_utils_new("ls << test<test");
    inst_block_t *test_inst_block = inst_block_new();
    inst_t *test_inst = inst_new();
    bool test_return = false;

    inst_append(test_inst_block, test_inst);
    test->index_parsing = 3;
    parsing_redirection_handler(test, NODE_DATA_TO_PTR(test_inst_block->instructions->first->data, inst_t *));
    test_return = parsing_redirection_handler(test, NODE_DATA_TO_PTR(test_inst_block->instructions->first->data, inst_t *));
    cr_assert_eq(test_return, false);
    cr_assert_stderr_eq_str("Ambiguous input redirect.\n");
}

Test(parsing_redirection, test_ambigous_double_right, .init=redirect_all_stdout)
{
    parsing_utils_t *test = parsing_utils_new("ls > test>>test");
    inst_block_t *test_inst_block = inst_block_new();
    inst_t *test_inst = inst_new();
    bool test_return = false;

    inst_append(test_inst_block, test_inst);
    test->index_parsing = 3;
    parsing_redirection_handler(test, NODE_DATA_TO_PTR(test_inst_block->instructions->first->data, inst_t *));
    test_return = parsing_redirection_handler(test, NODE_DATA_TO_PTR(test_inst_block->instructions->first->data, inst_t *));
    cr_assert_eq(test_return, false);
    cr_assert_stderr_eq_str("Ambiguous input redirect.\n");

}

Test(parsing_redirection, test_ambigous_double_left, .init=redirect_all_stdout)
{
    parsing_utils_t *test = parsing_utils_new("ls < test<<test");
    inst_block_t *test_inst_block = inst_block_new();
    inst_t *test_inst = inst_new();
    bool test_return = false;

    inst_append(test_inst_block, test_inst);
    test->index_parsing = 3;
    parsing_redirection_handler(test, NODE_DATA_TO_PTR(test_inst_block->instructions->first->data, inst_t *));
    test_return = parsing_redirection_handler(test, NODE_DATA_TO_PTR(test_inst_block->instructions->first->data, inst_t *));
    cr_assert_eq(test_return, false);
    cr_assert_stderr_eq_str("Ambiguous input redirect.\n");
}
