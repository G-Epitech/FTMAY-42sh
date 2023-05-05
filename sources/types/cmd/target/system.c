/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** target
*/

#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "types/cmd/cmd.h"
#include "utils/asprintf2.h"
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

static char *get_path(char *dir, char *name)
{
    char *path = NULL;

    if (!name)
        return NULL;
    dir = clear_dir(dir);
    if (asprintf2(&path, "%s/%s", dir, name) == -1)
        return NULL;
    return path;
}

static bool is_system(char *path)
{
    struct stat target;

    if (!path)
        return false;
    return (stat(path, &target) == 0);
}

bool cmd_determine_target_is_system(cmd_t *cmd)
{
    char *dirs = getenv("PATH");
    char *dir = NULL;
    char *path = NULL;
    bool found = false;

    dirs = dirs ? dirs : SHELL_DEFAULT_PATH;
    dirs = strdup(dirs);
    dir = strtok(dirs, ":");
    while (dir && !found) {
        path = get_path(dir, cmd->name);
        found = is_system(path);
        if (!found)
            dir = strtok(NULL, ":");
    }
    if (found) {
        cmd->target.path = path;
        cmd->type = CMD_SYSTEM;
    }
    return found;
}
