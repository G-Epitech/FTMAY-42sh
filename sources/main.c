/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** Main file of project
*/

#include <stdio.h>
#include <stddef.h>
#include "parsing/parsing.h"
#include "types/parsing_utils/parsing_utils.h"

int main(void)
{
    parsing_utils_t *test = parsing_utils_new("ls -l -a");
    
    parsing_get_cmd(test, NULL);
    // parsing_redirection_handler(test, NULL);
}
