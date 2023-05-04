/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** Main file of project
*/

#include <stdio.h>
#include "parsing/parsing.h"
#include "types/shell/shell.h"

int main(void)
{
    shell_t *shell = shell_new();
    shell_set_var(shell, "test1", "axel");
    shell_set_var(shell, "test2", "flav");
    shell_set_var(shell, "test3", "yannou");

    char *replace = parsing_var_replace("first var : $test1\t", shell);

    if (replace == NULL)
        return 84;
    printf("Résultat : [%s]\n", replace);
}
