/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** target
*/

#include <string.h>
#include "types/cmd/cmd.h"
#include "types/shell/shell.h"

static bool is_builtin(cmd_t *cmd, const builtin_t *builtin)
{
    if (cmd->name)
        return strcmp(builtin->name, cmd->name) == 0;
    return false;
}

bool cmd_determine_target_is_builtin(cmd_t *cmd, shell_t *shell)
{
    size_t i = 0;
    const builtin_t *builtins = shell ? shell->builtins : NULL;

    if (!cmd || !shell || !builtins)
        return false;
    while (builtins[i].name) {
        if (is_builtin(cmd, &builtins[i])) {
            cmd->target.builtin = builtins[i].target;
            cmd->type = CMD_BUILTIN;
            return true;
        }
        i += 1;
    }
    return false;
}
