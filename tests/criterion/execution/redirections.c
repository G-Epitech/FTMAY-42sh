/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** redirections
*/

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "builtins/defs.h"
#include "types/inst/inst.h"
#include "types/shell/shell.h"
#include "execution/execution.h"
#include "execution/redirections.h"

Test(execution_redirections_tests, default_output_and_double_input,
.init=cr_redirect_stdout)
{
    int in = dup(STDIN_FILENO);
    int piped[2];
    inst_t *inst = inst_new();
    exec_utils_t utils;

    pipe(piped);
    dup2(piped[0], STDIN_FILENO);
    write(piped[1], "hello\nworld\npipe\nEOF\n", 21);
    close(piped[1]);
    inst->ios.input.path = strdup("EOF");
    inst->ios.input.type = IOT_DOUBLE;
    inst->ios.output.type = IOT_DEFAULT;
    execution_utils_init(&utils, NULL, EXEC_SUPERIOR);
    cr_assert(execution_inst_get_redirections(inst, &utils));
    fflush(stdout);
    cr_assert_stdout_eq_str("? ? ? ? ");
    cr_assert(fcntl(utils.fd_my[0], F_GETFD) != -1);
    cr_assert(utils.fd_my[1] == STDOUT_FILENO);
    close(piped[0]);
    dup2(in, STDIN_FILENO);
    close(in);
    inst_free(inst);
}

Test(execution_redirections_tests, default_output_and_simple_input,
.init=cr_redirect_stdout)
{
    inst_t *inst = inst_new();
    exec_utils_t utils;
    int fd = 0;
    char buff[100];
    size_t readed = 0;

    remove("file-10.tmp");
    fd = open("file-10.tmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    write(fd, "MY\nINPUT\n", 9);
    close(fd);
    fd = -1;
    inst->ios.input.path = strdup("file-10.tmp");
    inst->ios.input.type = IOT_SIMPLE;
    inst->ios.output.type = IOT_DEFAULT;
    execution_utils_init(&utils, NULL, EXEC_SUPERIOR);
    cr_assert(execution_inst_get_redirections(inst, &utils));
    cr_assert(fcntl(utils.fd_my[0], F_GETFD) != -1);
    cr_assert(utils.fd_my[1] == STDOUT_FILENO);
    readed = read(utils.fd_my[0], buff, 100);
    buff[readed] = '\0';
    close(utils.fd_my[0]);
    cr_assert_str_eq(buff, "MY\nINPUT\n");
    inst_free(inst);
    remove("file-10.tmp");
}

Test(execution_redirections_tests, simple_output_and_simple_input,
.init=cr_redirect_stdout)
{
    inst_t *inst = inst_new();
    exec_utils_t utils;
    int fd = 0;
    char buff[100];
    size_t readed = 0;

    remove("file-13.tmp");
    remove("file-14.tmp");
    fd = open("file-13.tmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    write(fd, "MY\nINPUT\n", 9);
    close(fd);
    fd = -1;
    inst->ios.input.path = strdup("file-13.tmp");
    inst->ios.input.type = IOT_SIMPLE;
    inst->ios.output.type = IOT_SIMPLE;
    inst->ios.output.path = strdup("file-14.tmp");
    execution_utils_init(&utils, NULL, EXEC_SUPERIOR);
    cr_assert(execution_inst_get_redirections(inst, &utils));
    cr_assert(fcntl(utils.fd_my[0], F_GETFD) != -1);
    cr_assert(fcntl(utils.fd_my[1], F_GETFD) != -1);
    readed = read(utils.fd_my[0], buff, 100);
    close(utils.fd_my[0]);
    write(utils.fd_my[1], buff, readed);
    close(utils.fd_my[1]);
    memset(buff, '\0', 100);
    fd = open("file-14.tmp", O_RDONLY);
    readed = read(fd, buff, 100);
    cr_assert_str_eq(buff, "MY\nINPUT\n");
    inst_free(inst);
    remove("file-13.tmp");
    remove("file-14.tmp");
}
