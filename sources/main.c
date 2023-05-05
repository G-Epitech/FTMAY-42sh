/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** Main file of project
*/

#include <stdio.h>
#include "mysh/mysh.h"
#include "parsing/parsing.h"
#include "types/shell/shell.h"

int main(void)
{
    setvbuf(stdout, NULL, _IONBF, 0);
    return mysh();
}
