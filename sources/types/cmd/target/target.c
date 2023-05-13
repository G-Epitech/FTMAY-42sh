/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** target
*/

#include "types/cmd/cmd.h"
#include "types/shell/shell.h"

bool cmd_determine_target(cmd_t *cmd, shell_t *shell)
{
    if (cmd_determine_target_is_empty(cmd))
        return true;
    if (cmd_determine_target_is_builtin(cmd, shell))
        return true;
    if (strchr(cmd->name, "/") != NULL)
        return cmd_determine_target_is_absolute(cmd);
    return cmd_determine_target_is_system(cmd, shell);
}
