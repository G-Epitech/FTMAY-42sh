/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** group
*/

#include <grp.h>
#include <stdio.h>
#include <unistd.h>
#include "types/var/var.h"
#include "types/shell/shell.h"

bool shell_special_vars_group_init(char *name, shell_t *shell,
char *dependency)
{
    gid_t gid = 0;
    struct group *group = NULL;

    (void) dependency;
    gid = getgid();
    group = getgrgid(gid);
    if (!group)
        return false;
    return var_list_set(shell->vars, name, group->gr_name);
}
