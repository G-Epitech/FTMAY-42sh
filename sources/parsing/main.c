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

inst_t *parsing_get_main_block(char *input)
{
    parsing_utils_t *utils = parsing_utils_new(input);
    inst_t *main = NULL;

    if (!utils || !input)
        return NULL;
    main = parsing_recursivity(utils);
    parsing_utils_free(utils);
    if (main == NULL)
        return NULL;
    return main;
}
