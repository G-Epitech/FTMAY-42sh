/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** prepare
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "builtins/defs.h"
#include "execution/defs.h"
#include "types/shell/shell.h"
#include "execution/execution.h"

Test(execution_cmd_can_be_done_tests, null_cmd)
{
    cr_assert_not(execution_cmd_can_be_done(NULL));
}

Test(execution_cmd_can_be_done_tests, empty_cmd)
{
    cmd_t *cmd = cmd_new();

    cmd->type = CMD_EMPTY;
    cr_assert(execution_cmd_can_be_done(cmd));
    cmd_free(cmd);
}

Test(execution_cmd_can_be_done_tests, builtin_cmd)
{
    cmd_t *cmd = cmd_new();

    cmd->type = CMD_BUILTIN;
    cr_assert(execution_cmd_can_be_done(cmd));
    cmd_free(cmd);
}

Test(execution_cmd_can_be_done_tests, null_cmd_type)
{
    cmd_t *cmd = cmd_new();

    cmd->type = CMD_NULL;
    cr_assert_not(execution_cmd_can_be_done(cmd));
    cmd_free(cmd);
}

Test(execution_cmd_can_be_done_tests, cmd_system)
{
    shell_t *shell = shell_new(builtins_cmds);
    cmd_t *cmd = cmd_new();

    cmd->type = CMD_NULL;
    cmd->input = strdup("ls");
    cr_assert(cmd_set_args(cmd));
    cr_assert(cmd_determine_target(cmd, shell));
    cr_assert(cmd->type == CMD_SYSTEM);
    cr_assert(execution_cmd_can_be_done(cmd));
    cmd_free(cmd);
    shell_free(shell);
}

Test(execution_cmd_can_be_done_tests, cmd_absolute)
{
    shell_t *shell = shell_new(builtins_cmds);
    cmd_t *cmd = cmd_new();

    cmd->type = CMD_NULL;
    cmd->input = strdup("/bin/ls");
    cr_assert(cmd_set_args(cmd));
    cr_assert(cmd_determine_target(cmd, shell));
    cr_assert(cmd->type == CMD_ABSOLUTE);
    cr_assert(execution_cmd_can_be_done(cmd));
    cmd_free(cmd);
    shell_free(shell);
}

Test(execution_cmd_can_be_done_tests, cmd_absolute_null_target_path,
.init=cr_redirect_stderr)
{
    shell_t *shell = shell_new(builtins_cmds);
    cmd_t *cmd = cmd_new();

    cmd->type = CMD_ABSOLUTE;
    cmd->input = strdup("/bin/ls");
    cmd->target.path = NULL;
    cr_assert(cmd_set_args(cmd));
    cr_assert_not(execution_cmd_can_be_done(cmd));
    fflush(stderr);
    cr_assert_stderr_eq_str("/bin/ls: Command not found.\n");
    cmd_free(cmd);
    shell_free(shell);
}

Test(execution_cmd_can_be_done_tests, cmd_absolute_acces_denied_target,
.init=cr_redirect_stderr)
{
    shell_t *shell = shell_new(builtins_cmds);
    cmd_t *cmd = cmd_new();

    cmd->type = CMD_ABSOLUTE;
    cmd->input = strdup("./tests/utils/sh/forbidden.sh");
    cr_assert(cmd_set_args(cmd));
    cr_assert(cmd_determine_target(cmd, shell));
    cr_assert_not(execution_cmd_can_be_done(cmd));
    fflush(stderr);
    cr_assert_stderr_eq_str("./tests/utils/sh/forbidden.sh: Permission denied.\n");
    cmd_free(cmd);
    shell_free(shell);
}

Test(execution_cmd_can_be_done_tests, cmd_absolute_acces_allowed_target_xusr,
.init=cr_redirect_stderr)
{
    shell_t *shell = shell_new(builtins_cmds);
    cmd_t *cmd = cmd_new();

    cmd->type = CMD_ABSOLUTE;
    cmd->input = strdup("./tests/utils/sh/allowed-usr.sh");
    cr_assert(cmd_set_args(cmd));
    cr_assert(cmd_determine_target(cmd, shell));
    cr_assert(execution_cmd_can_be_done(cmd));
    cmd_free(cmd);
    shell_free(shell);
}

Test(execution_cmd_can_be_done_tests, cmd_absolute_acces_allowed_target_xgrp,
.init=cr_redirect_stderr)
{
    shell_t *shell = shell_new(builtins_cmds);
    cmd_t *cmd = cmd_new();

    cmd->type = CMD_ABSOLUTE;
    cmd->input = strdup("./tests/utils/sh/allowed-grp.sh");
    cr_assert(cmd_set_args(cmd));
    cr_assert(cmd_determine_target(cmd, shell));
    cr_assert(execution_cmd_can_be_done(cmd));
    cmd_free(cmd);
    shell_free(shell);
}

Test(execution_cmd_can_be_done_tests, cmd_absolute_acces_allowed_target_xoth,
.init=cr_redirect_stderr)
{
    shell_t *shell = shell_new(builtins_cmds);
    cmd_t *cmd = cmd_new();

    cmd->type = CMD_ABSOLUTE;
    cmd->input = strdup("./tests/utils/sh/allowed-oth.sh");
    cr_assert(cmd_set_args(cmd));
    cr_assert(cmd_determine_target(cmd, shell));
    cr_assert(execution_cmd_can_be_done(cmd));
    cmd_free(cmd);
    shell_free(shell);
}

Test(execution_cmd_can_be_done_tests, cmd_absolute_inexists_target,
.init=cr_redirect_stderr)
{
    shell_t *shell = shell_new(builtins_cmds);
    cmd_t *cmd = cmd_new();

    cmd->type = CMD_ABSOLUTE;
    cmd->input = strdup("./tests/utils/super2.sh");
    cr_assert(cmd_set_args(cmd));
    cmd->target.path = strdup("./tests/utils/super2.sh");
    cr_assert_not(execution_cmd_can_be_done(cmd));
    fflush(stderr);
    cr_assert_stderr_eq_str("./tests/utils/super2.sh: Command not found.\n");
    cmd_free(cmd);
    shell_free(shell);
}
