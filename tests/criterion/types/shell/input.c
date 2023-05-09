/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** get_input
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

Test(shell_get_input_tests, basic)
{
    shell_t *shell = shell_new(builtins_cmds);
    int saved_stdin = dup(STDIN_FILENO);
    char *input = NULL;
    int piped[2];
    
    pipe(piped);
    dup2(piped[0], STDIN_FILENO);
    write(piped[1], "echo salut\n", 11);
    close(piped[1]);
    input = shell_get_input(shell);
    cr_assert_str_eq(input, "echo salut");
    close(piped[0]);
    dup2(saved_stdin, STDIN_FILENO);
    close(saved_stdin);
    shell_free(shell);
    free(input);
}

Test(shell_get_input_tests, exit_shell, .init=cr_redirect_stdout) {
    char* test_input = "\0";
    shell_t *shell = shell_new(builtins_cmds);
    char reader[100];
    int p[2] = {0, 0};
    char *output = NULL;

    shell->is_tty = true;
    memset(reader, '\0', 100);
    cr_assert(pipe(p) != -1, "Failed to create pipe.");
    cr_assert(dup2(p[0], STDIN_FILENO) != -1, "Failed to redirect stdin to pipe.");
    write(p[1], test_input, strlen(test_input));
    close(p[1]);
    output = shell_get_input(shell);
    cr_assert_str_eq(output, test_input);
    fflush(stdout);
    cr_assert_stdout_eq_str("exit\n");
    close(p[0]);
    free(output);
    shell_free(shell);
}
