/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** redirections
*/

#include <unistd.h>
#include "execution/defs.h"
#include "types/inst/defs.h"
#include "execution/redirections.h"

bool execution_inst_get_redirections(inst_t *inst, exec_utils_t *utils)
{
    io_type_t input = inst->ios.input.type;
    io_type_t output = inst->ios.output.type;
    bool success = true;

    if (input == IOT_SIMPLE || input == IOT_DOUBLE)
        success |= execution_redirection_get_input(inst, &(utils->fd_my[0]));
    else if (input == IOT_PIPED)
        pipe(utils->pipe);
    if ((output == IOT_SIMPLE || output == IOT_DOUBLE) && success)
        success |= execution_redirection_get_output(inst, &(utils->fd_my[1]));
    utils->fd_saved[0] = dup(STDIN_FILENO);
    utils->fd_saved[1] = dup(STDOUT_FILENO);
    return success;
}
