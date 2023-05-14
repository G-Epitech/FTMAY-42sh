/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** execution
*/

#include <stdio.h>
#include <string.h>
#include "mysh/mysh.h"
#include "parsing/parsing.h"
#include "types/inst/inst.h"
#include "types/shell/defs.h"
#include "types/shell/shell.h"
#include "types/history/history.h"

inst_t *mysh_parse(shell_t *shell, char *input)
{
    size_t len = input ? strlen(input) : 0;

    if (!input || !len) {
        shell->exit_code = SHELL_EXIT_SUCCESS;
        return NULL;
    }
    if (!shell_format_check(shell, input))
        return NULL;
    history_append_entry(shell->history, input);
    return parsing_get_main_block(input);
}
