/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** cwd
*/

#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include "types/var/var.h"
#include "utils/malloc2.h"
#include "types/shell/defs.h"

bool shell_special_vars_cwd_init(char *name, shell_t *shell,
char *dependency)
{
    char *cwd = malloc2(PATH_MAX);

    (void) dependency;
    if (!cwd)
        return false;
    if (!getcwd(cwd, PATH_MAX) || !cwd)
        return false;
    return var_list_set(shell->vars, name, cwd);
}
