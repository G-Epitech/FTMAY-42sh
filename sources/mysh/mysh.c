/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** running shell
*/

#include <stdio.h>
#include "mysh/mysh.h"
#include "builtins/defs.h"
#include "parsing/parsing.h"
#include "types/shell/shell.h"
#include "execution/execution.h"
#include "types/history/history.h"

int mysh(void)
{
    int exit_code = 0;
    char *input = NULL;
    inst_t *block = NULL;
    shell_t *shell = shell_new(builtins_cmds);

    if (!shell)
        return SHELL_EXIT_ERROR;
    while (shell->status == SH_RUNNING) {
        shell_display_prompt(shell);
        input = mysh_get_input(shell);
        if (shell->status == SH_RUNNING) {
            block = mysh_parse(shell, input);
            mysh_execute(input, block, shell);
        }
    }
    exit_code = shell->exit_code;
    shell_free(shell);
    return exit_code;
}
