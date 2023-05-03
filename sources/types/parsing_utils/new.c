/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** new
*/

#include <stddef.h>
#include <stdlib.h>
#include "utils/malloc2.h"
#include "types/parsing_utils/parsing_utils.h"

parsing_utils_t *parsing_utils_new(char *input_user)
{
    parsing_utils_t *utils = NULL;

    if (!input_user)
        return NULL;
    utils = malloc2(sizeof(parsing_utils_t));
    if (!utils)
        return NULL;
    utils->index_parsing = 0;
    utils->input = input_user;
    return utils;
}
