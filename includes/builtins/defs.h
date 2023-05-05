/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** defs
*/

#ifndef BUILTINS_DEFS_H_
    #define BUILTINS_DEFS_H_

    #include <stdlib.h>
    #include "builtins.h"
    #include "types/builtin/defs.h"

    #define BUILTIN_CD_TILDE "~"
    #define BUILTIN_CD_DASH "-"

static const builtin_t builtins_cmds[] = {
    {"cd", &builtin_cd},
    {"exit", &builtin_exit},
    {"env", &builtin_env},
    {"setenv", &builtin_setenv},
    {"unsetenv", &builtin_unsetenv},
    {NULL, NULL}
};

#endif /* !BUILTINS_DEFS_H_ */
