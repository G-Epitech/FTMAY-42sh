/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** fd
*/

#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "builtins/defs.h"
#include "execution/defs.h"
#include "types/node/node.h"
#include "parsing/parsing.h"
#include "types/shell/shell.h"
#include "execution/execution.h"
#include "execution/redirections.h"

Test(execution_inst_fd_tests, close_fd)
{
    exec_utils_t utils;

    utils.fd_my[0] = STDIN_FILENO;
    utils.fd_my[1] = STDOUT_FILENO;
    execution_inst_close_fd(&utils);
    cr_assert(fcntl(utils.fd_my[0], F_GETFD) != -1);
    cr_assert(fcntl(utils.fd_my[1], F_GETFD) != -1);
}

Test(execution_inst_fd_tests, close_fd_piped)
{
    exec_utils_t utils;

    pipe(utils.fd_my);
    execution_inst_close_fd(&utils);
    cr_assert(fcntl(utils.fd_my[0], F_GETFD) == -1);
    cr_assert(fcntl(utils.fd_my[1], F_GETFD) == -1);
}

Test(execution_inst_set_fd_tests, set_simple_file)
{
    shell_t *shell = shell_new(builtins_cmds);
    inst_t *block = parsing_get_main_block("echo salut > file-1.tmp");
    inst_t *inst = NODE_DATA_TO_PTR(block->value.block->instructions->first->data, inst_t *);
    node_t *node = node_new(NODE_DATA_FROM_PTR(inst));
    int fd = 0;
    char buff[7];
    exec_utils_t utils;

    remove("file-1.tmp");
    execution_cmd_prepare(node, shell);
    execution_utils_init(&utils, NULL, EXEC_SUPERIOR);
    execution_inst_get_redirections(inst, &utils);
    cr_assert(fcntl(utils.fd_my[0], F_GETFD) != -1);
    cr_assert(fcntl(utils.fd_my[1], F_GETFD) != -1);
    execution_inst_launch_fork(node, shell, &utils);
    shell_restore_io(shell);
    fd = open("file-1.tmp", O_RDONLY);
    cr_assert(fd != -1);
    read(fd, buff, 7);
    close(fd);
    buff[6] = '\0';
    cr_assert_str_eq(buff, "salut\n");
    remove("file-1.tmp");
}

Test(execution_inst_set_fd_tests, set_simple_pipe)
{
    shell_t *shell = shell_new(builtins_cmds);
    inst_t *block = parsing_get_main_block("echo salut");
    inst_t *inst = NODE_DATA_TO_PTR(block->value.block->instructions->first->data, inst_t *);
    node_t *node = node_new(NODE_DATA_FROM_PTR(inst));
    char buff[7];
    exec_utils_t utils;

    inst->ios.output.type = IOT_PIPED;
    execution_cmd_prepare(node, shell);
    execution_utils_init(&utils, NULL, EXEC_MAIN);
    pipe(utils.fd_herited);
    execution_inst_get_redirections(inst, &utils);
    cr_assert(fcntl(utils.fd_herited[0], F_GETFD) != -1);
    cr_assert(fcntl(utils.fd_herited[1], F_GETFD) != -1);
    execution_inst_launch_fork(node, shell, &utils);
    shell_restore_io(shell);
    close(utils.fd_herited[1]);
    read(utils.fd_herited[0], buff, 7);
    buff[6] = '\0';
    cr_assert_str_eq(buff, "salut\n"); 
    close(utils.fd_herited[0]);
}

Test(execution_inst_set_fd_tests, set_simple_input, .init=cr_redirect_stdout)
{
    remove("file-2.tmp");
    int fd = open("file-2.tmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    write(fd, "hello world\n", 12);
    close(fd);
    shell_t *shell = shell_new(builtins_cmds);
    inst_t *block = parsing_get_main_block("cat -e < file-2.tmp");
    inst_t *inst = NODE_DATA_TO_PTR(block->value.block->instructions->first->data, inst_t *);
    node_t *node = node_new(NODE_DATA_FROM_PTR(inst));
    exec_utils_t utils;

    execution_cmd_prepare(node, shell);
    execution_utils_init(&utils, NULL, EXEC_SUPERIOR);
    execution_inst_get_redirections(inst, &utils);
    cr_assert(fcntl(utils.fd_my[0], F_GETFD) != -1);
    execution_inst_launch_fork(node, shell, &utils);
    cr_assert_stdout_eq_str("hello world$\n");
    remove("file-2.tmp");
}

Test(execution_inst_set_fd_tests, set_double_output_file)
{
    remove("file-3.tmp");
    int fd = open("file-3.tmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    write(fd, "LINE1\n", 6);
    close(fd);
    shell_t *shell = shell_new(builtins_cmds);
    inst_t *block = parsing_get_main_block("echo LINE2 >> file-3.tmp");
    inst_t *inst = NODE_DATA_TO_PTR(block->value.block->instructions->first->data, inst_t *);
    node_t *node = node_new(NODE_DATA_FROM_PTR(inst));
    char buff[50];
    exec_utils_t utils;

    execution_cmd_prepare(node, shell);
    execution_utils_init(&utils, NULL, EXEC_SUPERIOR);
    execution_inst_get_redirections(inst, &utils);
    cr_assert(fcntl(utils.fd_my[1], F_GETFD) != -1);
    execution_inst_launch_fork(node, shell, &utils);
    shell_restore_io(shell);
    fd = open("file-3.tmp", O_RDONLY);
    cr_assert(fd != -1);
    cr_assert(read(fd, buff, 50) == 12);
    close(fd);
    buff[13] = '\0';
    cr_assert_str_eq(buff, "LINE1\nLINE2\n");
    remove("file-3.tmp");
}

Test(execution_inst_set_fd_tests, set_double_input, .init=cr_redirect_stdout)
{
    int fd[2];
    shell_t *shell = shell_new(builtins_cmds);
    inst_t *block = parsing_get_main_block("cat -e << EOF");
    inst_t *inst = NODE_DATA_TO_PTR(block->value.block->instructions->first->data, inst_t *);
    node_t *node = node_new(NODE_DATA_FROM_PTR(inst));
    exec_utils_t utils;

    pipe(fd);
    execution_cmd_prepare(node, shell);
    execution_utils_init(&utils, NULL, EXEC_SUPERIOR);
    write(fd[1], "hello\nworld\n", 12);
    close(fd[1]);
    utils.fd_my[0] = fd[0];
    cr_assert(fcntl(utils.fd_my[0], F_GETFD) != -1);
    execution_inst_launch_fork(node, shell, &utils);
    cr_assert_stdout_eq_str("hello$\nworld$\n");
    close(fd[1]);
}
