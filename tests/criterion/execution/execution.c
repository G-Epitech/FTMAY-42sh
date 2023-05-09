/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** execution
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "builtins/defs.h"
#include "utils/malloc2.h"
#include "parsing/parsing.h"
#include "types/inst/inst.h"
#include "types/shell/shell.h"
#include "execution/execution.h"

Test(execution_tests, basic, .init=cr_redirect_stdout)
{
    shell_t *shell = shell_new(builtins_cmds);
    inst_t *block = parsing_get_main_block("echo salut");

    cr_assert(execution_main_block(block, shell));
    cr_assert_stdout_eq_str("salut\n");
    inst_free(block);
    shell_free(shell);
}

Test(execution_tests, malloc_fail)
{
    shell_t *shell = shell_new(builtins_cmds);
    inst_t *block = parsing_get_main_block("echo salut");

    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_FAIL);
    cr_assert_not(execution_main_block(NULL, shell));
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_NORMAL);
    inst_free(block);
    shell_free(shell);
}
