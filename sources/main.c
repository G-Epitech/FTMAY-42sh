/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** main
*/

#include <stdio.h>
#include "mysh/mysh.h"

int main()
{
    setvbuf(stdout, NULL, _IONBF, 0);
    return mysh();
}



