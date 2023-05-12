/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** user
*/

#include <stdio.h>
#include <stdlib.h>
#include "types/var/var.h"
#include "types/shell/shell.h"

bool shell_special_vars_path_init(char *name, shell_t *shell,
char *dependency)
{
    char *path = dependency ? getenv(dependency) : NULL;

    if (!path)
        path = SHELL_DEFAULT_PATH;
    return var_list_set(shell->vars, name, path);
}
