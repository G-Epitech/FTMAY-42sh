/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** Main file of project
*/

#include "types/shell/shell.h"
#include "builtins/builtins.h"
#include "types/var/var.h"

int main(void)
{
    shell_t *shell = shell_new();
    char *argv[] = {"var"};
    args_t args = {.argc = 1, .argv = argv};

    builtin_var(&args, shell);
    shell_free(shell);
    return 0;
}
