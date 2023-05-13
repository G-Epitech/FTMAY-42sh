/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** utils built'in
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include "utils/utils.h"
#include "types/cmd/cmd.h"
#include "types/args/defs.h"
#include "builtins/builtins.h"
#include "types/shell/shell.h"


static char *path_is_found(cmd_t *cmd, bool *is_found,
char *path)
{
    (void) is_found;
    *is_found = true;
    cmd->target.path = path;
    cmd->type = CMD_SYSTEM;
    printf("%s\n", cmd->target.path);
    return strtok(NULL, ":");
}

static bool cmd_determine_targets_is_system(cmd_t *cmd, shell_t *shell)
{
    char *dirs = shell_get_var(shell, "path", true);
    char *dir = NULL;
    char *path = NULL;
    bool is_found = false;

    if (!dirs)
        return false;
    dir = strtok(dirs, ":");
    while (dir) {
        path = builtin_where_get_path(dir, cmd->name);
        if (builtin_where_is_system(path))
            dir = path_is_found(cmd, &is_found, path);
        else
            dir = strtok(NULL, ":");
    }
    if (is_found) {
        cmd->target.path = path;
        cmd->type = CMD_SYSTEM;
    }
    return is_found;
}

bool builtin_where_determine_targets(cmd_t *cmd, shell_t *shell)
{
    int find = false;

    if (cmd_determine_target_is_empty(cmd))
        find = true;
    if (cmd_determine_target_is_builtin(cmd, shell)) {
        fprintf(stdout, "%s is a shell built-in\n", cmd->input);
        find = true;
    }
    if (cmd_determine_targets_is_system(cmd, shell))
        find = true;
    if (cmd_determine_target_is_absolute(cmd))
        find = true;
    return find;
}
