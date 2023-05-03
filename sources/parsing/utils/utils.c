/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** utils
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "parsing/utils.h"

bool parsing_maybe_redirection(parsing_utils_t *utils)
{
    char *redirection[4] = {"<", "<<", ">>", ">"};
    char *data = utils->input + utils->index_parsing;

    for (int i = 0; i < 4; i++) {
        if (strncmp(redirection[i], data, strlen(redirection[i])) == 0)
            return true;
    }
    return false;
}
