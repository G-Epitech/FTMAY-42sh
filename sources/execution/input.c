/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** fd
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "types/inst/inst.h"

void execution_double_left(char *word, int fd[2]);

static void open_file(io_t input)
{
    int file = open(input.path, O_WRONLY, 0777);

    if (file == -1) {
        fprintf(stderr, "%s: No such file or directory.\n", input.path);
        return;
    }
    dup2(file, STDIN_FILENO);
    close(file);
}

void execusion_input(io_t input, int fd[2])
{
    switch (input.type) {
        case IOT_PIPED:
            dup2(fd[0], STDIN_FILENO);
            break;
        case IOT_SIMPLE:
            open_file(input);
            break;
        case IOT_DOUBLE:
            dup2(fd[0], STDIN_FILENO);
            execution_double_left(input.path, fd);
            break;
        default:
            break;
    }
}
