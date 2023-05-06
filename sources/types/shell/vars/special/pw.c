/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** user
*/

#include <pwd.h>
#include <stdio.h>
#include <unistd.h>
#include "types/var/var.h"
#include "utils/asprintf2.h"
#include "types/shell/shell.h"

bool shell_special_vars_pw_uid_init(char *name, shell_t *shell, char *dependency)
{
    uid_t uid = 0;
    char *uid_string = NULL;

    (void) dependency;
    uid = getuid();
    asprintf2(&uid_string, "%d", uid);
    if (!uid_string)
        return false;
    return var_list_set(shell->vars, name, uid_string);
}

bool shell_special_vars_pw_gid_init(char *name, shell_t *shell,
char *dependency)
{
    gid_t gid = 0;
    char *gid_string = NULL;

    (void) dependency;
    gid = getgid();
    asprintf2(&gid_string, "%d", gid);
    if (!gid_string)
        return false;
    return var_list_set(shell->vars, name, gid_string);
}
