/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** which
*/

#include <stdio.h>
#include <string.h>
#include "utils/utils.h"
#include "types/cmd/cmd.h"
#include "types/cmd/defs.h"
#include "types/args/defs.h"
#include "types/shell/defs.h"

static bool find_command(char *command, shell_t *shell)
{
    cmd_t *cmd = cmd_new();

    if (!cmd)
        return false;
    cmd->input = strdup(command);
    if (!cmd_set_args(cmd, shell))
        return false;
    if (!cmd_determine_target(cmd, shell) || cmd->type == CMD_NULL ||
    cmd->type == CMD_EMPTY) {
        fprintf(stderr, "%s: Command not found.\n", command);
        return false;
    }
    if (cmd->type == CMD_BUILTIN) {
        printf("%s: shell built-in command.\n", command);
        return true;
    }
    printf("%s\n", cmd->target.path);
    return true;
}

int builtin_which(args_t *args, shell_t *shell)
{
    if (!shell || !args)
        return SHELL_EXIT_ERROR;
    if (args->argc == 1) {
        fprintf(stderr, "which: Too few arguments.\n");
        return SHELL_EXIT_ERROR;
    }
    for (size_t i = 1; i < (size_t) args->argc; i++) {
        if (!find_command(args->argv[i], shell))
            return SHELL_EXIT_ERROR;
    }
    return SHELL_EXIT_SUCCESS;
}
