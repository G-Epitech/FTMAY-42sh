/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** killer
*/

#include <unistd.h>
#include <signal.h>

int main(void)
{
    kill(getpid(), SIGBUS);
    return (0);
}
