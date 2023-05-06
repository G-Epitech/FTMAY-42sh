/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** uid
*/

#include <stdio.h>
#include <unistd.h>
#include "types/var/var.h"
#include "utils/asprintf2.h"
#include "types/shell/shell.h"

bool shell_special_vars_uid_init(char *name, shell_t *shell, char *dependency)
{
    uid_t uid = 0;
    char *uid_string = NULL;

    (void) dependency;
    (void) name;
    uid = getuid();
    asprintf2(&uid_string, "%d", uid);
    if (!uid_string)
        return false;
    return var_list_set(shell->vars, name, uid_string);
}
