/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** ignoreeof
*/

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include "utils/utils.h"
#include "types/var/var.h"
#include "utils/malloc2.h"
#include "utils/asprintf2.h"
#include "types/shell/shell.h"

bool shell_special_vars_ignoreeof_set(char *name, char *value, char *dependency,
shell_t *shell)
{
    int exit_in = 0;

    (void) dependency;
    if (!is_number(value))
        exit_in = 26;
    else
        exit_in = atoi(value);
    shell->exit_in = exit_in;
    return var_list_set(shell->vars, name, value);
}
