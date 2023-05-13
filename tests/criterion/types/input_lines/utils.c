/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** utils
*/

#include <stdio.h>
#include <string.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "builtins/defs.h"
#include "utils/malloc2.h"
#include "types/input_line/handlers.h"
#include "types/input_line/input_line.h"

Test(append_char, append_char_in_word)
{
    input_line_t *user_input = input_line_new();
    bool test_return = false;

    user_input->buffer->cursor = 2;
    user_input->buffer->content = malloc(6);
    user_input->buffer->content[0] = 'c';
    user_input->buffer->content[1] = 'o';
    user_input->buffer->content[2] = 'u';
    user_input->buffer->content[3] = 'c';
    user_input->buffer->content[4] = 'o';
    user_input->buffer->content[5] = '\0';
    test_return = append_char(user_input, 66);
    cr_assert_eq(test_return, true);
    cr_assert_str_eq(user_input->buffer->content, "coBuco");
    input_line_free(user_input);
}

Test(delete_char, delete_char_in_word, .init=cr_redirect_stdout)
{
    input_line_t *user_input = input_line_new();

    user_input->buffer->cursor = 2;
    user_input->buffer->content = malloc(6);
    user_input->buffer->content[0] = 'c';
    user_input->buffer->content[1] = 'o';
    user_input->buffer->content[2] = 'u';
    user_input->buffer->content[3] = 'c';
    user_input->buffer->content[4] = 'o';
    user_input->buffer->content[5] = '\0';
    delete_char(NULL, user_input);
    cr_assert_str_eq(user_input->buffer->content, "cuco");
    input_line_free(user_input);
}

Test(new_struct, bad_new_struct)
{
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_FAIL);
    cr_assert_null(input_line_new());
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_NORMAL);
}

Test(test_thermios, enable_disable, .init=cr_redirect_stdout)
{
    input_line_t *user_input = input_line_new();
    struct termios default_settings;
    bool test_enable = false;
    bool test_disable = false;

    test_enable = input_line_enable_raw_mode(user_input, &default_settings);
    cr_assert_eq(test_enable, false);
    test_disable = input_line_disable_raw_mode(&default_settings, true);
    cr_assert_eq(test_disable, false);
}
