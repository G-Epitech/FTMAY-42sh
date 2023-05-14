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
    cr_assert(shell_get_input(shell, &input));
    cr_assert_str_eq(input, "echo salut");
    close(piped[0]);
    dup2(saved_stdin, STDIN_FILENO);
    close(saved_stdin);
    shell_free(shell);
    free(input);
}
