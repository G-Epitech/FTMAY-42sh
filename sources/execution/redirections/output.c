/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** input
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

bool execution_redirection_get_output(inst_t *inst, int *fd)
{
    int flags = O_CREAT | O_WRONLY;
    int mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
    int output = -1;

    if (inst->ios.output.type == IOT_DOUBLE)
        flags = flags | O_APPEND;
    else
        flags = flags | O_TRUNC;
    output = open(inst->ios.output.path, flags, mode);
    if (output == -1) {
        execution_redirections_error(inst->ios.output.path, errno);
        return false;
    }
    if (*fd != STDOUT_FILENO && *fd > -1)
        close(*fd);
    *fd = output;
    return true;
}
