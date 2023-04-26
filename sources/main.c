/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** Main file of project
*/

#include <stddef.h>
#include "parsing/parsing.h"
#include "types/parsing_utils/parsing_utils.h"

int main(void)
{
    parsing_utils_t *test = parsing_utils_new("> tmp_fic (ls -l -a | cat -e)");
    parsing_redirection_handler(test, NULL);
}
