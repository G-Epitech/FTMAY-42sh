/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** execution
*/

#include "mysh/mysh.h"
#include "parsing/parsing.h"
#include "types/inst/inst.h"
#include "types/shell/defs.h"
#include "types/history/history.h"

inst_t *mysh_parse(char *input, shell_t *shell)
{
    inst_t *block = NULL;

    if (!input)
        return NULL;
    block = parsing_get_main_block(input);
    if (block)
        history_append_entry(shell->history, input);
    return block;
}
