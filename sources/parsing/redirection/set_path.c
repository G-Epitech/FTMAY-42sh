/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** parsing
*/

#include <stdio.h>
#include <string.h>
#include "types/inst/inst.h"
#include "types/parsing_utils/parsing_utils.h"

static void avoid_space(parsing_utils_t *utils)
{
    while (USER_INPUT(utils)[INDEX_PARSING(utils)] == ' ')
        INDEX_PARSING(utils)++;
}

void set_path(parsing_utils_t *utils, inst_t *instruction)
{
    avoid_space(utils)
    while (USER_INPUT(utils)[INDEX_PARSING(utils)] != ' ') {
        
    }
}