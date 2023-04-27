/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** cd
*/

#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>
#include "builtins/defs.h"
#include "types/args/defs.h"
#include "types/shell/defs.h"

static bool set_new_path(args_t *args, shell_t *shell)
{
    char *path = NULL;

    if (args->argc == 2)
        path = args->argv[1];
    if (args->argc == 1 || !strcmp(args->argv[1], BUILTIN_CD_TILDE))
        path = shell->home;
    if (args->argc == 2 && !strcmp(args->argv[1], BUILTIN_CD_DASH))
        path = shell->owd;
    if (chdir(path) == -1) {
        fprintf(stderr, "cd: %s\n", strerror(errno));
        return false;
    }
    getcwd(shell->pwd, PATH_MAX);
    return true;
}

unsigned char builtin_cd(args_t *args, shell_t *shell)
{
    char *owd = NULL;

    if (!args)
        return SHELL_EXIT_ERROR;
    if (args->argc > 2) {
        fprintf(stderr, "cd: Too many arguments.\n");
        return SHELL_EXIT_ERROR;
    }
    owd = malloc(PATH_MAX);
    if (!owd)
        return SHELL_EXIT_ERROR;
    getcwd(owd, PATH_MAX);
    if (!set_new_path(args, shell)) {
        free(owd);
        return SHELL_EXIT_ERROR;
    }
    free(shell->owd);
    shell->owd = owd;
    return SHELL_EXIT_SUCCESS;
}
