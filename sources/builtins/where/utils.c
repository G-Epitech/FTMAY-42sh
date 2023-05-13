/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** utils built'in where
*/

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "utils/utils.h"
#include "types/cmd/cmd.h"
#include "types/cmd/defs.h"
#include "utils/asprintf2.h"
#include "types/args/defs.h"
#include "types/shell/defs.h"
#include "types/shell/shell.h"

static char *clear_dir(char *dir)
{
    size_t len = strlen(dir);

    if (len == 0)
        return dir;
    else if (dir[len - 1] == '/')
        dir[len - 1] = '\0';
    return dir;
}

char *builtin_where_get_path(char *dir, char *name)
{
    char *path = NULL;

    if (!name)
        return NULL;
    dir = clear_dir(dir);
    if (asprintf2(&path, "%s/%s", dir, name) == -1)
        return NULL;
    return path;
}

bool builtin_where_is_system(char *path)
{
    struct stat target;

    if (!path)
        return false;
    return (stat(path, &target) == 0);
}
