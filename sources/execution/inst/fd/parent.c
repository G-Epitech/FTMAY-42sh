/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** parent
*/

#include <unistd.h>
#include "types/inst/defs.h"
#include "execution/execution.h"

void execution_inst_set_parent_fd(inst_t *inst, exec_utils_t *utils)
{
    if (inst->ios.input.type == IOT_PIPED) {
        close(utils->pipe[0]);
        close(utils->pipe[1]);
    }
    if (inst->ios.output.type == IOT_PIPED)
        close(utils->fd_herited[1]);
}
