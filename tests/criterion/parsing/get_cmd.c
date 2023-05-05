/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** get_cmd
*/

#include <string.h>
#include <criterion/criterion.h>
#include "types/parsing_utils/parsing_utils.h"
#include "parsing/utils.h"
#include "parsing/parsing.h"
#include "types/inst/inst.h"
#include "utils/malloc2.h"

Test(parsing_getcmd, basic)
{
    parsing_utils_t *utils = parsing_utils_new("ls -la");
    inst_t *cmd = parsing_get_cmd(utils);

    cr_assert_eq(strcmp(cmd->value.cmd->input, "ls -la"), 0);
    parsing_utils_free(utils);
    inst_free(cmd);
}

Test(parsing_getcmd, basic_2)
{
    parsing_utils_t *utils = parsing_utils_new("ls -l -a");
    inst_t *cmd = parsing_get_cmd(utils);

    cr_assert_eq(strcmp(cmd->value.cmd->input, "ls -l -a"), 0);
    parsing_utils_free(utils);
    inst_free(cmd);
}

Test(parsing_getcmd, basic_with_redirection)
{
    parsing_utils_t *utils = parsing_utils_new("ls -la > tmp");
    inst_t *cmd = parsing_get_cmd(utils);

    cr_assert_eq(strcmp(cmd->value.cmd->input, "ls -la  "), 0);
    parsing_utils_free(utils);
    inst_free(cmd);
}

Test(parsing_getcmd, empty)
{
    parsing_utils_t *utils = parsing_utils_new("");
    inst_t *cmd = parsing_get_cmd(utils);

    cr_assert_null(cmd);
    parsing_utils_free(utils);
    inst_free(cmd);
}

Test(parsing_getcmd, malloc_failed)
{
    parsing_utils_t *utils = parsing_utils_new("ls -la > tmp");
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_FAIL);
    inst_t *cmd = parsing_get_cmd(utils);

    cr_assert_null(cmd);
    parsing_utils_free(utils);
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_NORMAL);
}

Test(parsing_getcmd, malloc_failed_word)
{
    parsing_utils_t *utils = parsing_utils_new("ls -la > tmp");
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_FAIL);
    inst_t *cmd = parsing_get_cmd(utils);

    cr_assert_null(cmd);
    parsing_utils_free(utils);
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_NORMAL);
}
