/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** status
*/

#include <unistd.h>
#include "types/var/var.h"
#include "types/shell/shell.h"

bool shell_special_vars_status_init(char *name, shell_t *shell,
char *dependency)
{
    (void) dependency;
    if (!name || !shell)
        return false;
    return var_list_set(shell->vars, name, "0");
}

char *shell_special_vars_status_get(shell_t *shell, char *name, bool copy)
{
    (void) name;
    if (!shell)
        return NULL;
    return var_list_get_value(shell->vars, "status", copy);
}
