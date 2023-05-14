/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** fd
*/

#include <unistd.h>
#include "types/inst/defs.h"
#include "execution/execution.h"

static void execution_set_output_fd(inst_t *inst, exec_utils_t *utils)
{
    io_type_t output = inst->ios.output.type;

    if (output == IOT_PIPED) {
        close(STDOUT_FILENO);
        close(utils->fd_herited[0]);
        dup2(utils->fd_herited[1], STDOUT_FILENO);
    }
    if (output == IOT_SIMPLE || output == IOT_DOUBLE) {
        close(utils->fd_herited[0]);
        close(utils->fd_herited[1]);
        close(STDOUT_FILENO);
        dup2(utils->fd_my[1], STDOUT_FILENO);
    }
}

static void execution_set_input_fd(inst_t *inst, exec_utils_t *utils)
{
    io_type_t input = inst->ios.input.type;

    close(utils->pipe[1]);
    if (input == IOT_PIPED) {
        close(STDIN_FILENO);
        close(utils->fd_my[0]);
        dup2(utils->pipe[0], STDIN_FILENO);
    }
    if (input == IOT_SIMPLE || input == IOT_DOUBLE) {
        close(STDIN_FILENO);
        close(utils->pipe[0]);
        dup2(utils->fd_my[0], STDIN_FILENO);
    }
}

void execution_inst_set_fd(inst_t *inst, exec_utils_t *utils)
{
    execution_set_output_fd(inst, utils);
    execution_set_input_fd(inst, utils);
}

void execution_inst_close_fd(exec_utils_t *utils)
{
    if (utils->fd_my[1] != STDOUT_FILENO)
        close(utils->fd_my[1]);
    if (utils->fd_my[0] != STDIN_FILENO)
        close(utils->fd_my[0]);
    if (utils->fd_saved[0] != STDIN_FILENO) {
        dup2(utils->fd_saved[0], STDIN_FILENO);
        close(utils->fd_saved[1]);
    }
    if (utils->fd_saved[1] != STDOUT_FILENO) {
        dup2(utils->fd_saved[1], STDOUT_FILENO);
        close(utils->fd_saved[0]);
    }
}
