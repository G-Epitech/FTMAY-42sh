/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** double_left
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "utils/malloc2.h"

#define BUFFER_SIZE 10

void execution_double_left(char *word, int fd[2]);

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(double_redirection_left, test_pipe_input, .init=redirect_all_stdout) {
    char* test_input = "0123456789\nend\n";
    char reader[100];
    int p[2] = {0, 0};
    int fd[2] = {0, 0};

    memset(reader, '\0', 100);
    cr_assert(pipe(p) != -1, "Failed to create pipe.");

    cr_assert(dup2(p[0], STDIN_FILENO) != -1, "Failed to redirect stdin to pipe.");

    write(p[1], test_input, strlen(test_input));
    close(p[1]);

    pipe(fd);
    execution_double_left("end", fd);

    read(fd[0], reader, 100);
    cr_assert(strcmp(reader, "0123456789\n") == 0, "Wrong Output");

    close(fd[1]);
    close(fd[0]);
    close(p[0]);
}

Test(double_redirection_left, test_word_without_breakline, .init=redirect_all_stdout) {
    char* test_input = "0123456789\nend";
    char reader[100];
    int p[2] = {0, 0};
    int fd[2] = {0, 0};

    memset(reader, '\0', 100);
    cr_assert(pipe(p) != -1, "Failed to create pipe.");

    cr_assert(dup2(p[0], STDIN_FILENO) != -1, "Failed to redirect stdin to pipe.");

    write(p[1], test_input, strlen(test_input));
    close(p[1]);

    pipe(fd);
    execution_double_left("end", fd);

    read(fd[0], reader, 100);
    cr_assert(strcmp(reader, "0123456789\n") == 0, "Wrong Output");

    close(fd[1]);
    close(fd[0]);
    close(p[0]);
}

Test(double_redirection_left, test_hard_exit, .init=redirect_all_stdout) {
    char* test_input = "0123456789\n\0";
    char reader[100];
    int p[2] = {0, 0};
    int fd[2] = {0, 0};

    memset(reader, '\0', 100);
    cr_assert(pipe(p) != -1, "Failed to create pipe.");

    cr_assert(dup2(p[0], STDIN_FILENO) != -1, "Failed to redirect stdin to pipe.");

    write(p[1], test_input, strlen(test_input));
    close(p[1]);

    pipe(fd);
    execution_double_left("end", fd);

    read(fd[0], reader, 100);
    cr_assert(strcmp(reader, "0123456789\n") == 0, "Wrong Output");

    close(fd[1]);
    close(fd[0]);
    close(p[0]);
}

Test(double_redirection_left, malloc_failed) {
    int fd[2] = {0, 0};

    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_FAIL);
    execution_double_left("end", fd);
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_NORMAL);
}
