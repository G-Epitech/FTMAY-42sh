/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** absolute
*/

#include <errno.h>
#include <unistd.h>
#include "types/cmd/defs.h"
#include "types/shell/defs.h"
#include "execution/execution.h"

void execution_cmd_launch_absolute(cmd_t *cmd)
{
    args_t *args = &cmd->args;

    if (execve(cmd->target.path, args->argv, environ) != 0) {
        execution_cmd_display_error(cmd, errno);
        exit(SHELL_EXIT_ERROR);
    }
}
