/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** utils
*/

#include <unistd.h>
#include "execution/defs.h"
#include "types/inst/defs.h"

void execution_utils_init(exec_utils_t *utils, exec_utils_t *herited,
exec_caller_t caller)
{
    utils->fd_my[0] = STDIN_FILENO;
    utils->fd_my[1] = STDOUT_FILENO;
    utils->fd_herited[0] = herited ? herited->pipe[0] : STDIN_FILENO;
    utils->fd_herited[1] = herited ? herited->pipe[1] : STDOUT_FILENO;
    utils->pipe[0] = -1;
    utils->pipe[1] = -1;
    utils->fd_saved[0] = STDIN_FILENO;
    utils->fd_saved[1] = STDOUT_FILENO;
    utils->status = 0;
    utils->sub_status = 0;
    if (caller == EXEC_SIBLING)
        utils->level = herited->level + 1;
    else if (caller == EXEC_SUPERIOR)
        utils->level = 0;
    else
        utils->level = -1;
}
