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
#include "utils/os.h"
#include "builtins/defs.h"
#include "utils/malloc2.h"
#include "execution/defs.h"
#include "parsing/parsing.h"
#include "types/node/node.h"
#include "types/inst/inst.h"
#include "types/shell/shell.h"
#include "execution/execution.h"

Test(execution_cmd_absolute_tests, basic_system, .init = cr_redirect_stdout)
{
    shell_t *shell = shell_new(builtins_cmds);
    cmd_t *cmd = cmd_new();
    int status = 0;
    pid_t pid = 0;

    cmd->input = strdup("echo hello world");
    cmd_set_args(cmd, shell);
    cmd_determine_target(cmd, shell);
    cmd->type = CMD_ABSOLUTE;
    pid = fork();
    if (pid == 0)
        execution_cmd_launch_absolute(cmd);
    else
        waitpid(pid, &status, 0);
    cr_assert_stdout_eq_str("hello world\n");
    cr_assert(WIFEXITED(status));
    cr_assert(WEXITSTATUS(status) == SHELL_EXIT_SUCCESS);
    cmd_free(cmd);
    shell_free(shell);
}

Test(execution_cmd_absolute_tests, basic_absolute, .init = cr_redirect_stdout)
{
    shell_t *shell = shell_new(builtins_cmds);
    cmd_t *cmd = cmd_new();
    int status = 0;
    pid_t pid = 0;

    cmd->input = strdup("/bin/echo hello world");
    cmd_set_args(cmd, shell);
    cmd_determine_target(cmd, shell);
    cmd->type = CMD_ABSOLUTE;
    pid = fork();
    if (pid == 0)
        execution_cmd_launch_absolute(cmd);
    else
        waitpid(pid, &status, 0);
    cr_assert_stdout_eq_str("hello world\n");
    cr_assert(WIFEXITED(status));
    cr_assert(WEXITSTATUS(status) == SHELL_EXIT_SUCCESS);
    cmd_free(cmd);
    shell_free(shell);
}

Test(execution_cmd_absolute_tests, basic_absolute_access_denied,
.init = cr_redirect_stderr)
{
    shell_t *shell = shell_new(builtins_cmds);
    cmd_t *cmd = cmd_new();
    int status = 0;
    pid_t pid = 0;

    cmd->input = strdup("./tests/utils/sh/forbidden.sh");
    cmd_set_args(cmd, shell);
    cmd->target.path = strdup("./tests/utils/sh/forbidden.sh");
    cmd->type = CMD_ABSOLUTE;
    pid = fork();
    if (pid == 0)
        execution_cmd_launch_absolute(cmd);
    else
        waitpid(pid, &status, 0);
    cr_assert(WIFEXITED(status));
    cr_assert(WEXITSTATUS(status) == SHELL_EXIT_ERROR);
    cr_assert_stderr_eq_str("./tests/utils/sh/forbidden.sh: Permission denied.\n");
    cmd_free(cmd);
    shell_free(shell);
}

Test(execution_cmd_absolute_tests, basic_absolute_signaled,
.init = cr_redirect_stderr)
{
    shell_t *shell = shell_new(builtins_cmds);
    cmd_t *cmd = cmd_new();
    int status = 0;
    pid_t pid = 0;

    cmd->input = strdup("./tests/utils/my_sig.out 11");
    cmd_set_args(cmd, shell);
    cmd_determine_target(cmd, shell);
    pid = fork();
    if (pid == 0)
        execution_cmd_launch_absolute(cmd);
    else
        waitpid(pid, &status, 0);
    cr_assert(WIFSIGNALED(status));
    cr_assert(WTERMSIG(status) == SIGSEGV);
    fflush(stderr);
    //TODO:cr_assert_stderr_eq_str("Segmentation fault\n");
    cmd_free(cmd);
    shell_free(shell);
}

Test(execution_cmd_absolute_tests, basic_absolute_wrong_architecture,
.init = cr_redirect_stderr)
{
    shell_t *shell = shell_new(builtins_cmds);
    cmd_t *cmd = cmd_new();
    int status = 0;
    pid_t pid = 0;

    #if defined(OS_IS_MACOS)
        cmd->input = strdup("./tests/utils/bin/bin-linux.bin");
    #else
        cmd->input = strdup("./tests/utils/bin/bin-macos.bin");
    #endif
    cmd_set_args(cmd, shell);
    cmd_determine_target(cmd, shell);
    pid = fork();
    if (pid == 0)
        execution_cmd_launch_absolute(cmd);
    else
        waitpid(pid, &status, 0);
    cr_assert(WIFEXITED(status));
    cr_assert(WEXITSTATUS(status) == SHELL_EXIT_ERROR);
    #if defined(OS_IS_MACOS)
        cr_assert_stderr_eq_str("./tests/utils/bin/bin-linux.bin: Exec format error. Wrong Architecture.\n");
    #else
        cr_assert_stderr_eq_str("./tests/utils/bin/bin-macos.bin: Exec format error. Wrong Architecture.\n");
    #endif
    cmd_free(cmd);
    shell_free(shell);
}
