/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** free
*/

#include <stddef.h>
#include <stdlib.h>
#include "types/parsing_utils/parsing_utils.h"

void parsing_utils_free(parsing_utils_t *utils)
{
    free(utils);
}
