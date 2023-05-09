/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** absolute
*/

#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "errors/errors.h"
#include "types/cmd/cmd.h"
#include "types/cmd/defs.h"
#include "types/shell/defs.h"

int execution_cmd_launch_builtin(cmd_t *cmd, shell_t *shell)
{
    builtin_target_t target = cmd->target.builtin;
    int code = SHELL_EXIT_SUCCESS;
    args_t *args = &cmd->args;

    if (target)
        code = target(args, shell);
    if (cmd->forked)
        exit(code);
    return W_EXITCODE(code, 0);
}
