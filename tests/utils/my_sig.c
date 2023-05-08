/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** my_sig
*/

#include <signal.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    return kill(0, atoi(av[1]));
}
