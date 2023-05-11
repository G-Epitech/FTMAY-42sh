/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** target
*/

#include <string.h>
#include <criterion/criterion.h>
#include "utils/malloc2.h"
#include "builtins/defs.h"
#include "types/cmd/cmd.h"
#include "types/shell/shell.h"

Test(types_cmd_target, determine_target_of_builtin_cmd)
{
    shell_t *shell = shell_new(builtins_cmds);
    cmd_t *cmd = cmd_new();
    char *argv[] = {
        "cd",
        ".."
    };

    cmd->args.argc = 2;
    cmd->args.argv = argv;
    cmd->name = "cd";
    cr_assert(cmd_determine_target(cmd, shell));
    cr_assert(cmd->type == CMD_BUILTIN);
    cr_assert_not_null(cmd->target.builtin);
    shell_free(shell);
}

Test(types_cmd_target, determine_target_of_unknown_cmd)
{
    shell_t *shell = shell_new(builtins_cmds);
    cmd_t *cmd = cmd_new();
    char *argv[] = {
        "lsde"
    };

    cmd->args.argc = 1;
    cmd->args.argv = argv;
    cmd->name = "lsde";
    cr_assert_not(cmd_determine_target(cmd, shell));
    cr_assert(cmd->type == CMD_NULL);
    shell_free(shell);
}

Test(types_cmd_target, determine_target_of_system_cmd)
{
    shell_t *shell = shell_new(builtins_cmds);
    cmd_t *cmd = cmd_new();
    char *argv[] = {
        "ls"
    };

    cmd->args.argc = 1;
    cmd->args.argv = argv;
    cmd->name = "ls";
    cr_assert(cmd_determine_target(cmd, shell));
    cr_assert(cmd->type == CMD_SYSTEM);
    cr_assert_not_null(cmd->target.path);
    shell_free(shell);
}

Test(types_cmd_target, determine_target_of_absolute_cmd)
{
    shell_t *shell = shell_new(builtins_cmds);
    cmd_t *cmd = cmd_new();
    char *argv[] = {
        "/bin/ls"
    };

    cmd->args.argc = 1;
    cmd->args.argv = argv;
    cmd->name = "/bin/ls";
    cr_assert(cmd_determine_target(cmd, shell));
    cr_assert(cmd->type == CMD_ABSOLUTE);
    shell_free(shell);
}

Test(types_cmd_target, determine_target_of_empty_cmd)
{
    shell_t *shell = shell_new(builtins_cmds);
    cmd_t *cmd = cmd_new();
    char *argv[] = {
        "ls"
    };

    cmd->args.argc = 1;
    cmd->args.argv = argv;
    cmd->name = "";
    cr_assert(cmd_determine_target(cmd, shell));
    cr_assert(cmd->type == CMD_EMPTY);
    shell_free(shell);
}

Test(types_cmd_target, determine_target_of_null_cmd)
{
    shell_t *shell = shell_new(builtins_cmds);
    cmd_t *cmd = cmd_new();
    char *argv[] = {
        "ls"
    };

    cmd->args.argc = 1;
    cmd->args.argv = argv;
    cmd->name = "";
    cr_assert(cmd_determine_target(cmd, shell));
    cr_assert(cmd->type == CMD_EMPTY);
    shell_free(shell);
}

Test(types_cmd_target, determine_target_builtin_basic)
{
    shell_t *shell = shell_new(builtins_cmds);
    cmd_t *cmd = cmd_new();
    char *argv[] = {
        "cd",
        ".."
    };

    cmd->args.argc = 2;
    cmd->args.argv = argv;
    cmd->name = "cd";
    cr_assert(cmd_determine_target_is_builtin(cmd, shell));
    cr_assert_not_null(cmd->target.builtin);
    shell_free(shell);
}

Test(types_cmd_target, determine_target_builtin_basic_with_null_shell)
{
    cmd_t *cmd = cmd_new();
    char *argv[] = {
        "cd",
        ".."
    };

    cmd->args.argc = 2;
    cmd->args.argv = argv;
    cmd->name = "cd";
    cr_assert_not(cmd_determine_target_is_builtin(cmd, NULL));
    cr_assert_not(cmd->type == CMD_BUILTIN);
    cr_assert_null(cmd->target.path);
}

Test(types_cmd_target, determine_target_builtin_with_null_builtins)
{
    shell_t *shell = shell_new(NULL);
    cmd_t *cmd = cmd_new();
    char *argv[] = {
        "cd",
        ".."
    };

    cmd->args.argc = 2;
    cmd->args.argv = argv;
    cmd->name = "cd";
    cr_assert_not(cmd_determine_target_is_builtin(cmd, shell));
    cr_assert_null(cmd->target.builtin);
    shell_free(shell);
}

Test(types_cmd_target, determine_target_builtin_with_null_cmd)
{
    shell_t *shell = shell_new(builtins_cmds);

    cr_assert_not(cmd_determine_target_is_builtin(NULL, shell));
    shell_free(shell);
}

Test(types_cmd_target, determine_target_builtin_not)
{
    shell_t *shell = shell_new(builtins_cmds);
    cmd_t *cmd = cmd_new();
    char *argv[] = {
        "printf",
        "message: %s",
        "Salut"
    };

    cmd->args.argc = 2;
    cmd->args.argv = argv;
    cmd->name = "printf";
    cr_assert_not(cmd_determine_target_is_builtin(cmd, shell));
    cr_assert_null(cmd->target.builtin);
    shell_free(shell);
}

Test(types_cmd, determine_target_builtin_not_cmd_name)
{
    shell_t *shell = shell_new(builtins_cmds);
    cmd_t *cmd = cmd_new();
    char *argv[] = {
        "printf",
        "message: %s",
        "Salut"
    };

    cmd->args.argc = 2;
    cmd->args.argv = argv;
    cmd->name = NULL;
    cr_assert_not(cmd_determine_target_is_builtin(cmd, shell));
    cr_assert_null(cmd->target.builtin);
    shell_free(shell);
}

Test(types_cmd_target, determine_target_absolute_basic)
{
    cmd_t *cmd = cmd_new();
    char *argv[] = {
        "/bin/ls"
    };

    cmd->args.argc = 1;
    cmd->args.argv = argv;
    cmd->name = "/bin/ls";
    cr_assert(cmd_determine_target_is_absolute(cmd));
    cr_assert(cmd->type == CMD_ABSOLUTE);
    cr_assert_not_null(cmd->target.path);
}

Test(types_cmd_target, determine_target_absolute_not)
{
    cmd_t *cmd = cmd_new();
    char *argv[] = {
        "ls"
    };

    cmd->args.argc = 1;
    cmd->args.argv = argv;
    cmd->name = "ls";
    cr_assert_not(cmd_determine_target_is_absolute(cmd));
    cr_assert_not(cmd->type == CMD_ABSOLUTE);
    cr_assert_null(cmd->target.path);
}

Test(types_cmd_target, determine_target_absolute_with_null_cmd_name)
{
    cmd_t *cmd = cmd_new();
    char *argv[] = {
        "ls"
    };

    cmd->args.argc = 1;
    cmd->args.argv = argv;
    cmd->name = NULL;
    cr_assert_not(cmd_determine_target_is_absolute(cmd));
    cr_assert_not(cmd->type == CMD_ABSOLUTE);
    cr_assert_null(cmd->target.path);
}

Test(types_cmd_target, determine_target_empty_basic)
{
    cmd_t *cmd = cmd_new();
    char *argv[] = {
        ""
    };

    cmd->args.argc = 1;
    cmd->args.argv = argv;
    cmd->name = "";
    cr_assert(cmd_determine_target_is_empty(cmd));
    cr_assert(cmd->type == CMD_EMPTY);
    cr_assert_null(cmd->target.path);
}

Test(types_cmd_target, determine_target_empty_with_null_cmd_name)
{
    cmd_t *cmd = cmd_new();
    char *argv[] = {
        NULL
    };

    cmd->args.argc = 1;
    cmd->args.argv = argv;
    cmd->name = NULL;
    cr_assert_not(cmd_determine_target_is_empty(cmd));
    cr_assert_not(cmd->type == CMD_EMPTY);
    cr_assert_null(cmd->target.path);
}

Test(types_cmd_target, determine_target_empty_with_null_cmd)
{
    cr_assert_not(cmd_determine_target_is_empty(NULL));
}

Test(types_cmd_target, determine_target_system_basic)
{
    shell_t *shell = shell_new(builtins_cmds);
    cmd_t *cmd = cmd_new();
    char *argv[] = {
        "ls"
    };

    cmd->args.argc = 1;
    cmd->args.argv = argv;
    cmd->name = "ls";
    cr_assert(cmd_determine_target_is_system(cmd, shell));
    cr_assert(cmd->type == CMD_SYSTEM);
    cr_assert_not_null(cmd->target.path);
}

Test(types_cmd_target, determine_target_system_with_null_cmd_name)
{
    shell_t *shell = shell_new(builtins_cmds);
    cmd_t *cmd = cmd_new();
    char *argv[] = {
        NULL
    };

    cmd->args.argc = 1;
    cmd->args.argv = argv;
    cmd->name = NULL;
    cr_assert_not(cmd_determine_target_is_system(cmd, shell));
    cr_assert_not(cmd->type == CMD_SYSTEM);
    cr_assert_null(cmd->target.path);
    shell_free(shell);
}

Test(types_cmd_target, determine_target_system_with_default_path)
{
    shell_t *shell = shell_new(builtins_cmds);
    cmd_t *cmd = cmd_new();
    char *argv[] = {
        NULL
    };
    char *old_path = getenv("PATH");

    if (old_path)
        old_path = strdup(old_path);
    cmd->args.argc = 1;
    cmd->args.argv = argv;
    cmd->name = NULL;
    unsetenv("PATH");
    cr_assert_not(cmd_determine_target_is_system(cmd, shell));
    cr_assert_not(cmd->type == CMD_SYSTEM);
    cr_assert_null(cmd->target.path);
    if (old_path)
        setenv("PATH", old_path, true);
    shell_free(shell);
}

Test(types_cmd_target, determine_target_system_with_empty_path)
{
    shell_t *shell = shell_new(builtins_cmds);
    cmd_t *cmd = cmd_new();
    char *argv[] = {
        "ls"
    };
    char *old_path = getenv("PATH");

    if (old_path)
        old_path = strdup(old_path);
    cmd->args.argc = 1;
    cmd->args.argv = argv;
    cmd->name = "ls";
    shell_set_var(shell, "path", "");
    cr_assert_not(cmd_determine_target_is_system(cmd, shell));
    cr_assert_not(cmd->type == CMD_SYSTEM);
    cr_assert_null(cmd->target.path);
    if (old_path)
        shell_set_var(shell, "path", old_path);
    shell_free(shell);
}


Test(types_cmd_target, determine_target_system_with_unknwon_cmd)
{
    shell_t *shell = shell_new(builtins_cmds);
    cmd_t *cmd = cmd_new();
    char *argv[] = {
        "supercommand"
    };

    cmd->args.argc = 1;
    cmd->args.argv = argv;
    cmd->name = "supercommand";
    cr_assert_not(cmd_determine_target_is_system(cmd, shell));
    cr_assert_not(cmd->type == CMD_SYSTEM);
    cr_assert_null(cmd->target.path);
    shell_free(shell);
}

Test(types_cmd_target, determine_target_system_cmd_on_malloc_fail)
{
    shell_t *shell = shell_new(builtins_cmds);
    cmd_t *cmd = cmd_new();
    char *argv[] = {
        "ls",
        "/"
    };

    cmd->args.argc = 2;
    cmd->args.argv = argv;
    cmd->name = "ls";
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_FAIL);
    cr_assert_not(cmd_determine_target_is_system(cmd, shell));
    cr_assert_not(cmd->type == CMD_SYSTEM);
    cr_assert_null(cmd->target.path);
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_NORMAL);
    shell_free(shell);
}

Test(types_cmd_target, determine_target_system_without_shell)
{
    cmd_t *cmd = cmd_new();
    char *argv[] = {
        "ls",
        "/"
    };

    cmd->args.argc = 2;
    cmd->args.argv = argv;
    cmd->name = "ls";
    cr_assert_not(cmd_determine_target_is_system(cmd, NULL));
    cr_assert_not(cmd->type == CMD_SYSTEM);
    cr_assert_null(cmd->target.path);
}

Test(types_cmd_target, determine_target_system_without_path_var)
{
    shell_t *shell = shell_new(builtins_cmds);
    cmd_t *cmd = cmd_new();
    char *argv[] = {
        "ls",
        "/"
    };

    cmd->args.argc = 2;
    cmd->args.argv = argv;
    cmd->name = "ls";
    shell_unset_var(shell, "path");
    cr_assert_not(cmd_determine_target_is_system(cmd, shell));
    cr_assert_not(cmd->type == CMD_SYSTEM);
    cr_assert_null(cmd->target.path);
    shell_free(shell);
}


Test(types_cmd_target, determine_target_system_without_default_path)
{
    char *original_path = strdup(getenv("PATH"));
    unsetenv("PATH");
    shell_t *shell = shell_new(builtins_cmds);
    char *path = shell_get_var(shell, "path", false);
    cmd_t *cmd = cmd_new();
    char *argv[] = {
        "ls",
        "/"
    };

    cmd->args.argc = 2;
    cmd->args.argv = argv;
    cmd->name = "ls";
    cr_assert_str_eq(path, SHELL_DEFAULT_PATH);
    cr_assert(cmd_determine_target_is_system(cmd, shell));
    cr_assert(cmd->type == CMD_SYSTEM);
    cr_assert_not_null(cmd->target.path);
    shell_free(shell);
    setenv("PATH", original_path, true);
}
