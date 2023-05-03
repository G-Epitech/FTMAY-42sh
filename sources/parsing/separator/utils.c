/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** separator
*/

#include <unistd.h>
#include <string.h>
#include "types/inst/inst.h"
#include "types/parsing_utils/parsing_utils.h"

bool parsing_maybe_separator(parsing_utils_t *utils)
{
    char *redirection[2] = {"||", "&&"};
    char *data = utils->input + utils->index_parsing;

    for (int i = 0; i < 2; i++) {
        if (strncmp(redirection[i], data, strlen(redirection[i])) == 0)
            return true;
    }
    return false;
}
