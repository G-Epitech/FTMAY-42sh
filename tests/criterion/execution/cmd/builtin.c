/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** absolute
*/

#include <stdlib.h>
#include <limits.h>
#include <sys/wait.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "builtins/defs.h"
#include "types/cmd/cmd.h"
#include "types/shell/shell.h"
#include "execution/execution.h"

Test(execution_cmd_builtin_tests, basic_cd, .init = cr_redirect_stdout)
{
    shell_t *shell = shell_new(builtins_cmds);
    char *pwd = malloc(PATH_MAX);
    char *test = malloc(PATH_MAX);
    cmd_t *cmd = cmd_new();

    getcwd(pwd, PATH_MAX);
    cmd->input = strdup("cd /");
    cmd_set_args(cmd);
    cmd_determine_target(cmd, shell);
    cr_assert(cmd->type == CMD_BUILTIN);
    cr_assert(execution_cmd_launch_builtin(cmd, shell) == SHELL_EXIT_SUCCESS);
    getcwd(test, PATH_MAX);
    cr_assert_str_eq(test, "/");
    chdir(pwd);
    shell_free(shell);
    cmd_free(cmd);
    free(test);
    free(pwd);
}

Test(execution_cmd_builtin_tests, no_target, .init = cr_redirect_stdout)
{
    shell_t *shell = shell_new(builtins_cmds);
    cmd_t *cmd = cmd_new();

    cmd->input = strdup("cd /");
    cmd_set_args(cmd);
    cmd_determine_target(cmd, shell);
    cmd->target.builtin = NULL;
    cr_assert(cmd->type == CMD_BUILTIN);
    cr_assert(execution_cmd_launch_builtin(cmd, shell) == SHELL_EXIT_SUCCESS);
    shell_free(shell);
    cmd_free(cmd);
}

Test(execution_cmd_absolute_tests, forked_builtin, .init = cr_redirect_stdout)
{
    shell_t *shell = shell_new(builtins_cmds);
    cmd_t *cmd = cmd_new();
    int status = 0;
    pid_t pid = 0;

    shell->is_tty = true;
    cmd->input = strdup("exit 2");
    cmd_set_args(cmd);
    cmd_determine_target(cmd, shell);
    cmd->type = CMD_BUILTIN;
    cmd->forked = true;
    pid = fork();
    if (pid == 0)
        execution_cmd_launch_builtin(cmd, shell);
    else
        waitpid(pid, &status, 0);
    cr_assert_stdout_eq_str("exit\n");
    cr_assert(WIFEXITED(status));
    cr_assert(WEXITSTATUS(status) == 2);
    cmd_free(cmd);
    shell_free(shell);
}
