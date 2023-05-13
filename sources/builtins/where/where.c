/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** where
*/

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "utils/utils.h"
#include "types/cmd/cmd.h"
#include "types/cmd/defs.h"
#include "utils/asprintf2.h"
#include "types/args/defs.h"
#include "types/shell/defs.h"
#include "types/shell/shell.h"
#include "builtins/builtins.h"

static bool find_paths_command(char *command, shell_t *shell)
{
    cmd_t *cmd = cmd_new();

    if (!cmd)
        return false;
    cmd->input = strdup(command);
    if (!cmd_set_args(cmd, shell))
        return false;
    if (!builtin_where_determine_targets(cmd, shell) || cmd->type == CMD_NULL ||
    cmd->type == CMD_EMPTY) {
        return false;
    }
    return true;
}

static bool contain_slash(char *cmd)
{
    for (size_t index = 0; index < strlen(cmd); index++) {
        if (cmd[index] == '/') {
            fprintf(stderr, "where: / in command makes no sense\n");
            return true;
        }
    }
    return false;
}

int builtin_where(args_t *args, shell_t *shell)
{
    int status = SHELL_EXIT_SUCCESS;

    if (!shell || !args)
        return SHELL_EXIT_ERROR;
    if (args->argc == 1) {
        fprintf(stderr, "where: Too few arguments.\n");
        return SHELL_EXIT_ERROR;
    }
    for (size_t i = 1; i < (size_t) args->argc; i++) {
        if (contain_slash(args->argv[i])) {
            status = SHELL_EXIT_ERROR;
            continue;
        }
        if (!find_paths_command(args->argv[i], shell) &&
        status == SHELL_EXIT_SUCCESS) {
            status = SHELL_EXIT_ERROR;
        }
    }
    return status;
}
