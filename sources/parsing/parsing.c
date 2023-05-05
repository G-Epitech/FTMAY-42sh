/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** main
*/

#include <stdio.h>
#include "parsing/utils.h"
#include "types/list/list.h"
#include "types/inst/inst.h"
#include "parsing/parsing.h"
#include "types/parsing_utils/parsing_utils.h"

static bool check_parentheses(char *input)
{
    int result = 0;
    int index = 0;

    while (input[index] != '\0') {
        if (input[index] == '(')
            result++;
        if (input[index] == ')')
            result--;
        index++;
    }
    if (result > 0)
        write(2, "Too many ('s.\n", 14);
    if (result < 0)
        write(2, "Too many )'s.\n", 14);
    return !(result > 0 || result < 0);
}

inst_t *parsing_get_main_block(char *input)
{
    parsing_utils_t *utils = parsing_utils_new(input);
    inst_t *main = NULL;

    if (!utils || !input || !check_parentheses(input))
        return NULL;
    main = parsing_recursivity(utils);
    parsing_utils_free(utils);
    return main;
}
