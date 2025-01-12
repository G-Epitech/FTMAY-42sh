/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** env
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "utils/utils.h"
#include "types/args/defs.h"
#include "types/shell/shell.h"
#include "builtins/builtins.h"

static bool builtin_setenv_check_name(char *name)
{
    size_t len = strlen(name);

    if (!CHAR_IS_ALPHA_EXT(name[0])) {
        write(2, "setenv: Variable name must begin with a letter.\n", 48);
        return false;
    }
    for (size_t i = 1; i < len; i++) {
        if (!CHAR_IS_ALPHANUM_EXT(name[i])) {
            write(2, "setenv: Variable name must contain "
            "alphanumeric characters.\n", 60);
            return false;
        }
    }
    return true;
}

static bool builtin_setenv_prevent_errors(args_t *args)
{
    if (args->argc != 2 && args->argc != 3) {
        write(2, "setenv: Too many arguments.\n", 28);
        return true;
    }
    if (!builtin_setenv_check_name(args->argv[1]))
        return true;
    return false;
}

int builtin_setenv(args_t *args, shell_t *shell)
{
    if (!args)
        return SHELL_EXIT_ERROR;
    if (args->argc == 1)
        return builtin_env(args, shell);
    if (builtin_setenv_prevent_errors(args))
        return SHELL_EXIT_ERROR;
    if (args->argc == 2)
        setenv(args->argv[1], "", true);
    else
        setenv(args->argv[1], args->argv[2], true);
    shell_special_vars_dispatch_env_update(shell, args->argv[1]);
    return SHELL_EXIT_SUCCESS;
}
