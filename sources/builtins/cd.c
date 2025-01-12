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
#include "utils/malloc2.h"
#include "errors/errors.h"
#include "types/var/var.h"
#include "types/args/defs.h"
#include "types/shell/shell.h"
#include "builtins/builtins.h"

static bool handle_specials(char **path, args_t *args, shell_t *shell,
bool *error)
{
    char *home = NULL;

    if (args->argc == 1 || !strcmp(args->argv[1], BUILTIN_CD_TILDE)) {
        home = shell_get_var(shell, "home", false);
        if (!home) {
            fprintf(stderr, BUILTIN_CD_NO_HOME_MSG);
            *error = true;
        }
        *path = home;
        return true;
    }
    if (args->argc == 2 && !strcmp(args->argv[1], BUILTIN_CD_DASH)) {
        *path = var_list_get_value(shell->vars, "owd", true);
        return true;
    }
    return false;
}

static bool set_new_path(args_t *args, shell_t *shell)
{
    char *path = NULL;
    bool error = false;
    char *cwd = NULL;

    if (args->argc == 2)
        path = args->argv[1];
    if (handle_specials(&path, args, shell, &error) && error)
        return false;
    if (chdir(path) == -1) {
        fprintf(stderr, "%s: %s\n", path, errors_strerror(errno));
        return false;
    }
    cwd = malloc2(PATH_MAX);
    if (!cwd)
        return false;
    getcwd(cwd, PATH_MAX);
    var_list_set(shell->vars, "cwd", cwd);
    return true;
}

int builtin_cd(args_t *args, shell_t *shell)
{
    char *owd = NULL;

    if (!args)
        return SHELL_EXIT_ERROR;
    if (args->argc > 2) {
        fprintf(stderr, "cd: Too many arguments.\n");
        return SHELL_EXIT_ERROR;
    }
    owd = malloc2(PATH_MAX);
    if (!owd)
        return SHELL_EXIT_ERROR;
    getcwd(owd, PATH_MAX);
    if (!set_new_path(args, shell)) {
        free(owd);
        return SHELL_EXIT_ERROR;
    }
    var_list_set(shell->vars, "owd", owd);
    return SHELL_EXIT_SUCCESS;
}
