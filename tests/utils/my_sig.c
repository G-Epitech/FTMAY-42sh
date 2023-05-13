/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** my_sig
*/

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/resource.h>

int main(int ac, char **av)
{
    struct rlimit limit;

    if (ac == 3) {
        getrlimit(RLIMIT_CORE, &limit);
        limit.rlim_cur = limit.rlim_max;
        setrlimit(RLIMIT_CORE, &limit);
    }
    return kill(getpid(), atoi(av[1]));
}
