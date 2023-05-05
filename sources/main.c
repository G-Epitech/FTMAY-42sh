/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** Main file of project
*/

#include <string.h>
#include <stdio.h>
#include "mysh/mysh.h"
#include "parsing/parsing.h"
#include "types/shell/shell.h"
#include "types/inst/inst.h"
#include "types/parsing_utils/parsing_utils.h"
#include "parsing/utils.h"

int main(void)
{
    inst_t *main = parsing_get_main_block("ls && ; cat -e");

    parsing_display(main);
    inst_free(main);
    return 0;
}
