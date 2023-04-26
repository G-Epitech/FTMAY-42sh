/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** new
*/

#include <stddef.h>
#include "types/utils/utils.h"

utils_t *utils_new(char *input_user)
{
    utils_t *utils = NULL;

    if (!input_user)
        return NULL;
    utils = malloc(sizeof(utils_t));
    if (!utils)
        return NULL;
    utils->index_parsing = 0;
    utils->input = input_user;
    return utils;
}
