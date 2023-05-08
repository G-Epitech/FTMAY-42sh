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

inst_t *mysh_parse(char *input)
{
    if (!input)
        return NULL;
    return parsing_get_main_block(input);
}
