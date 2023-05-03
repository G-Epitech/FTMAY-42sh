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
    shell_set_var(shell, "test_1", "axel");
    shell_set_var(shell, "test_2", "flav");
    shell_set_var(shell, "test_3", "yannou");

    printf("Résultat : [%s]\n", parsing_var_replace("first var : $HOME", shell));
}
