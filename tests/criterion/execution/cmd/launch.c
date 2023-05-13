/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** prepare
*/

#include <stdlib.h>
#include <limits.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "builtins/defs.h"
#include "utils/malloc2.h"
#include "execution/defs.h"
#include "parsing/parsing.h"
#include "types/node/node.h"
#include "utils/asprintf2.h"
#include "types/inst/inst.h"
#include "types/shell/shell.h"
#include "execution/execution.h"

Test(execution_cmd_launch_tests, basic_system, .init=cr_redirect_stdout)
{
    char path[PATH_MAX];
    char *pwd = NULL;
    shell_t *shell = shell_new(builtins_cmds);
    cmd_t *command = cmd_new();
    inst_t *inst = inst_new();
    node_t *node = NULL;
    exec_utils_t utils;

    getcwd(path, PATH_MAX);
    asprintf2(&pwd, "%s\n", path);
    inst->type = INS_CMD;
    inst->value.cmd = command;
    command->input = strdup("pwd");
    node = node_new(NODE_DATA_FROM_PTR(inst));
    execution_utils_init(&utils, NULL, EXEC_MAIN);
    execution_cmd_prepare(node, shell);
    execution_cmd_launch(node, shell, &utils);
    cr_assert_stdout_eq_str(pwd);
    inst_free(inst);
    node_free(node, NULL);
    shell_free(shell);
    free(pwd);
}

Test(execution_cmd_launch_tests, basic_builtin)
{
    shell_t *shell = shell_new(builtins_cmds);
    char *pwd = malloc(PATH_MAX);
    char *test = malloc(PATH_MAX);
    cmd_t *command = cmd_new();
    inst_t *inst = inst_new();
    node_t *node = NULL;
    exec_utils_t utils;

    getcwd(pwd, PATH_MAX);
    inst->type = INS_CMD;
    inst->value.cmd = command;
    command->input = strdup("cd /");
    node = node_new(NODE_DATA_FROM_PTR(inst));
    execution_utils_init(&utils, NULL, EXEC_MAIN);
    execution_cmd_prepare(node, shell);
    execution_cmd_launch(node, shell, &utils);
    getcwd(test, PATH_MAX);
    cr_assert_str_eq(test, "/");
    inst_free(inst);
    node_free(node, NULL);
    shell_free(shell);
    chdir(pwd);
    free(pwd);
    free(test);
}

Test(execution_cmd_launch_tests, basic_absolute, .init=cr_redirect_stdout)
{
    shell_t *shell = shell_new(builtins_cmds);
    cmd_t *command = cmd_new();
    inst_t *inst = inst_new();
    node_t *node = NULL;
    exec_utils_t utils;

    inst->type = INS_CMD;
    inst->value.cmd = command;
    command->input = strdup("/bin/echo 12");
    node = node_new(NODE_DATA_FROM_PTR(inst));
    execution_utils_init(&utils, NULL, EXEC_MAIN);
    execution_cmd_prepare(node, shell);
    execution_cmd_launch(node, shell, &utils);
    cr_assert_stdout_eq_str("12\n");
    inst_free(inst);
    node_free(node, NULL);
    shell_free(shell);
}
