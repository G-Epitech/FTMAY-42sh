/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** error
*/

#include <stdio.h>
#include "errors/errors.h"

void execution_redirections_error(char *input, int error)
{
    char *msg = errors_strerror(error);

    fprintf(stderr, "%s: %s\n", input, msg);
}
