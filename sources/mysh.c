/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** running shell
*/

#include <stdio.h>
#include "builtins/defs.h"
#include "types/shell/shell.h"


#include "parsing/utils.h"
#include "parsing/parsing.h"
#include "types/inst/inst.h"

int mysh(void)
{
    int exit_code = 0;
    shell_t *shell = shell_new(builtins_cmds);
    char *input = NULL;

    while (shell->status == SH_RUNNING) {
        shell_display_prompt(shell);
        input = shell_get_input(shell);
        inst_t *inst = parsing_get_main_block(input);
        parsing_display(inst);
        free(input);
    }
    exit_code = shell->exit_code;
    shell_free(shell);
    return exit_code;
}
