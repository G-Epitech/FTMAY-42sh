/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** output
*/

#include <fcntl.h>
#include <unistd.h>
#include "types/inst/inst.h"

static void simple_write_file(io_t output)
{
    int file = open(output.path, O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (file == -1)
        return;
    dup2(file, STDOUT_FILENO);
    close(file);
}

static void double_write_file(io_t output)
{
    int file = open(output.path, O_WRONLY | O_CREAT | O_APPEND, 0644);

    if (file == -1)
        return;
    dup2(file, STDOUT_FILENO);
    close(file);
}

void execusion_output(io_t output, int fd[2])
{
    switch (output.type) {
        case IOT_PIPED:
            dup2(fd[0], STDOUT_FILENO);
            break;
        case IOT_SIMPLE:
            simple_write_file(output);
            break;
        case IOT_DOUBLE:
            double_write_file(output);
            break;
        default:
            break;
    }
}
