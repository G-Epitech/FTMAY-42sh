/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** output
*/

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "utils/os.h"
#include "utils/malloc2.h"
#include "builtins/defs.h"
#include "types/inst/inst.h"
#include "types/shell/shell.h"
#include "execution/redirections.h"

Test(execution_get_redirection_output_tests, simple_file)
{
    int fd = -1;
    inst_t *inst = inst_new();
    char buff[100];
    size_t readed = 0;

    remove("file-6.tmp");
    fd = open("file-6.tmp", O_WRONLY | O_CREAT, 0644);
    write(fd, "old content", 11);
    close(fd);
    fd = -1;
    inst->ios.output.path = strdup("file-6.tmp");
    inst->ios.output.type = IOT_SIMPLE;
    cr_assert(execution_redirection_get_output(inst, &fd));
    cr_assert(fcntl(fd, F_GETFD) != -1);
    cr_assert(fd != -1);
    write(fd, "hello\nworld\n", 12);
    close(fd);
    fd = open("file-6.tmp", O_RDONLY);
    readed = read(fd, buff, 100);
    buff[readed] = '\0';
    close(fd);
    cr_assert_str_eq("hello\nworld\n", buff);
    inst_free(inst);
    remove("file-6.tmp");
}

Test(execution_get_redirection_output_tests, double_file)
{
    int fd = -1;
    inst_t *inst = inst_new();
    char buff[100];
    size_t readed = 0;

    remove("file-7.tmp");
    fd = open("file-7.tmp", O_WRONLY | O_CREAT, 0644);
    write(fd, "old content\n", 12);
    close(fd);
    fd = -1;
    inst->ios.output.path = strdup("file-7.tmp");
    inst->ios.output.type = IOT_DOUBLE;
    cr_assert(execution_redirection_get_output(inst, &fd));
    cr_assert(fcntl(fd, F_GETFD) != -1);
    cr_assert(fd != -1);
    write(fd, "hello\nworld\n", 12);
    close(fd);
    fd = open("file-7.tmp", O_RDONLY);
    readed = read(fd, buff, 100);
    buff[readed] = '\0';
    close(fd);
    cr_assert_str_eq(buff, "old content\nhello\nworld\n");
    inst_free(inst);
    remove("file-7.tmp");
}

Test(execution_get_redirection_output_tests, no_permission)
{
    int fd = -1;
    inst_t *inst = inst_new();

    inst->ios.output.path = strdup("tests/utils/forbidden-wx.txt");
    inst->ios.output.type = IOT_SIMPLE;
    bool e = execution_redirection_get_output(inst, &fd);
    fprintf(stderr, "STATUS[%d]\n", e);
    cr_assert(fcntl(fd, F_GETFD) == -1);
    cr_assert(fd == -1);
    inst_free(inst);
}

Test(execution_get_redirection_output_tests, already_opened_file,
.init=cr_redirect_stderr)
{
    int fd = -1;
    int saved_fd = 0;
    inst_t *inst = inst_new();
    char buff[100];
    size_t readed = 0;

    fd = open("file-9.tmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    saved_fd = fd;
    inst->ios.output.path = strdup("file-10.tmp");
    inst->ios.output.type = IOT_SIMPLE;
    cr_assert(execution_redirection_get_output(inst, &fd));
    cr_assert(fcntl(fd, F_GETFD) != -1);
    cr_assert(fcntl(saved_fd, F_GETFD) == -1);
    write(fd, "hello\nworld\n", 12);
    close(fd);
    fd = open("file-10.tmp", O_RDONLY);
    readed = read(fd, buff, 100);
    buff[readed] = '\0';
    close(fd);
    cr_assert_str_eq(buff, "hello\nworld\n");
    inst_free(inst);
    remove("file-9.tmp");
    remove("file-10.tmp");
}
