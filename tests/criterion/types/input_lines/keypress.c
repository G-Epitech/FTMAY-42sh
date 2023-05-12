/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** keypress
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

Test(test_key_press_enter, test_input_line_keypressed_enter)
{
    input_line_t *line = input_line_new();

    input_line_keypressed_enter(NULL, line);
    cr_assert_eq(line->status, IL_EXITED);
}

Test(test_key_pres_d, test_input_line_keypressed_d)
{
    input_line_t *line = input_line_new();
    shell_t *shell = shell_new(NULL);

    input_line_keypressed_d(shell, line);
    cr_assert_eq(line->status, IL_EXITED);
    cr_assert_eq(shell->status, SH_EXITED);
}
