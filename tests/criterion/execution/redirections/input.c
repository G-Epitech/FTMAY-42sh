/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** input
*/

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "utils/malloc2.h"
#include "builtins/defs.h"
#include "types/inst/inst.h"
#include "types/shell/shell.h"
#include "execution/redirections.h"

Test(execution_get_redirection_simple_tests, simple_file)
{
    int fd = 0;
    inst_t *inst = inst_new();

    remove("file-4.tmp");
    fd = open("file-4.tmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    write(fd, "MY\nINPUT\n", 9);
    close(fd);
    fd = -1;
    inst->ios.input.path = strdup("file-4.tmp");
    inst->ios.input.type = IOT_SIMPLE;
    cr_assert(execution_redirection_get_input_simple(inst, &fd));
    cr_assert(fcntl(fd, F_GETFD) != -1);
    cr_assert(fd != -1);
    close(fd);
    remove("file-4.tmp");
    inst_free(inst);
}

Test(execution_get_redirection_simple_tests, non_existant_file, .init=cr_redirect_stderr)
{
    int fd = -1;
    inst_t *inst = inst_new();

    inst->ios.input.path = strdup("file-8.tmp");
    inst->ios.input.type = IOT_SIMPLE;
    cr_assert_not(execution_redirection_get_input_simple(inst, &fd));
    cr_assert(fcntl(fd, F_GETFD) == -1);
    cr_assert(fd == -1);
    fflush(stderr);
    cr_assert_stderr_eq_str("file-8.tmp: No such file or directory.\n");
    inst_free(inst);
}

Test(execution_get_redirection_simple_tests, already_opened_file)
{
    int fd = -1;
    int saved_fd = 0;
    inst_t *inst = inst_new();

    remove("file-11.tmp");
    fd = open("file-11.tmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    write(fd, "MY\nINPUT\n", 9);
    close(fd);
    fd = open("file-12.tmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    saved_fd = fd;
    inst->ios.input.path = strdup("file-11.tmp");
    inst->ios.input.type = IOT_SIMPLE;
    cr_assert(execution_redirection_get_input_simple(inst, &fd));
    cr_assert(fcntl(fd, F_GETFD) != -1);
    cr_assert(fcntl(saved_fd, F_GETFD) == -1);
    cr_assert(fd != -1);
    close(fd);
    remove("file-11.tmp");
    remove("file-12.tmp");
}

Test(execution_get_redirection_tests, double_redirection_left,
.init=cr_redirect_stdout)
{
    int in = dup(STDIN_FILENO);
    int piped[2];
    int fd = -1;
    inst_t *inst = inst_new();

    pipe(piped);
    dup2(piped[0], STDIN_FILENO);
    write(piped[1], "hello\nworld\npipe\nEOF\n", 21);
    close(piped[1]);
    inst->ios.input.path = "EOF";
    inst->ios.input.type = IOT_DOUBLE;
    cr_assert(execution_redirection_get_input(inst, &fd));
    cr_assert_stdout_eq_str("? ? ? ? ");
    cr_assert(fcntl(fd, F_GETFD) != -1);
    close(piped[0]);
    dup2(in, STDIN_FILENO);
    close(in);
}

Test(execution_get_redirection_tests, simple_file)
{
    int fd = 0;
    inst_t *inst = inst_new();

    remove("file-4.tmp");
    fd = open("file-4.tmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    write(fd, "MY\nINPUT\n", 9);
    close(fd);
    fd = -1;
    inst->ios.input.path = strdup("file-4.tmp");
    inst->ios.input.type = IOT_SIMPLE;
    cr_assert(execution_redirection_get_input(inst, &fd));
    cr_assert(fcntl(fd, F_GETFD) != -1);
    cr_assert(fd != -1);
    close(fd);
    remove("file-4.tmp");
    inst_free(inst);
}
