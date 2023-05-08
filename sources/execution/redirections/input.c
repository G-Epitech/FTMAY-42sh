/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** double_left
*/

#include <stdio.h>
#include <errno.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "types/inst/defs.h"
#include "execution/redirections.h"

bool execution_redirection_get_input_simple(inst_t *inst, int *fd)
{
    int flags = O_NOCTTY | O_RDONLY;
    int input = -1;

    input = open(inst->ios.input.path, flags);
    if (input == -1) {
        execution_redirections_error(inst->ios.input.path, errno);
        return false;
    }
    if (*fd != STDIN_FILENO && *fd > -1)
        close(*fd);
    *fd = input;
    return true;
}

bool execution_redirection_get_input(inst_t *inst, int *fd)
{
    int piped[2];

    if (inst->ios.input.type == IOT_SIMPLE)
        return execution_redirection_get_input_simple(inst, fd);
    pipe(piped);
    execution_redirection_get_input_double(inst->ios.input.path, piped[1]);
    close(piped[1]);
    *fd = piped[0];
    return true;
}
