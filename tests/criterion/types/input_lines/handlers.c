/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** handlers
*/

#include <stdio.h>
#include <string.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "builtins/defs.h"
#include "utils/malloc2.h"
#include "types/input_line/handlers.h"
#include "types/input_line/input_line.h"

Test(move_cursor, move_to_back, .init=cr_redirect_stdout)
{
    input_line_t *user_input = input_line_new();

    user_input->buffer->cursor = 4;

    input_line_cursor_backward(NULL, user_input);
    cr_assert_eq(user_input->buffer->cursor, 3);
}

Test(move_cursor, move_to_back_fail, .init=cr_redirect_stdout)
{
    input_line_t *user_input = input_line_new();

    user_input->buffer->cursor = 0;

    input_line_cursor_backward(NULL, user_input);
    cr_assert_eq(user_input->buffer->cursor, 0);
}

Test(move_cursor, move_to_front, .init=cr_redirect_stdout)
{
    input_line_t *user_input = input_line_new();

    user_input->buffer->cursor = 4;
    user_input->buffer->len = 5;

    input_line_cursor_forward(NULL, user_input);
    cr_assert_eq(user_input->buffer->cursor, 5);
}

Test(move_cursor, move_to_front_fail, .init=cr_redirect_stdout)
{
    input_line_t *user_input = input_line_new();

    user_input->buffer->cursor = 0;

    input_line_cursor_forward(NULL, user_input);
    cr_assert_eq(user_input->buffer->cursor, 0);
}
