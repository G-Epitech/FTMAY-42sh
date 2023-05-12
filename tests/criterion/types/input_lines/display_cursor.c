/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** display_cursor
*/

#include <stdio.h>
#include <string.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "utils/utils.h"
#include "builtins/defs.h"
#include "utils/malloc2.h"
#include "types/shell/shell.h"
#include "types/input_line/handlers.h"
#include "types/input_line/input_line.h"

Test(display_cursor, test_display_cursor, .init=cr_redirect_stdout)
{
    input_line_t *line = input_line_new();

    display_cursor(line);
}

Test(test_input_line_history_next, try_to_down_grade, .init=cr_redirect_stdout)
{
    input_line_t *line = input_line_new();
    shell_t *shell = shell_new(NULL);

    line->buffer->history_cursor = 4;
    input_line_history_next(shell, line);
    cr_assert_eq(line->buffer->history_cursor, 3);
}

Test(testing_history, test_input_line_history_next, .init=cr_redirect_stdout)
{
    input_line_t *line = input_line_new();
    shell_t *shell = shell_new(NULL);

    line->buffer->history_cursor = 0;
    input_line_history_next(shell, line);
    cr_assert_eq(line->buffer->cursor, 0);
    cr_assert_eq(line->buffer->len, 0);
}

Test(test_input_line_history_prev, try_to_down_grade, .init=cr_redirect_stdout)
{
    input_line_t *line = input_line_new();
    shell_t *shell = shell_new(NULL);

    line->buffer->history_cursor = 4;
    input_line_history_prev(shell, line);
}

Test(testing_history, test_input_line_history_prev, .init=cr_redirect_stdout)
{
    input_line_t *line = input_line_new();
    shell_t *shell = shell_new(NULL);

    line->buffer->history_cursor = 0;
    input_line_history_prev(shell, line);
    cr_assert_eq(line->buffer->cursor, 0);
    cr_assert_eq(line->buffer->len, 0);
}
