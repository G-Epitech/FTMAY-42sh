/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** target
*/

#include "types/cmd/cmd.h"

bool cmd_find_type(cmd_t *cmd)
{
    char *input = cmd->input;
    cmd_type_t type = CMD_SYSTEM;

    while (*input && type == CMD_SYSTEM) {
        if (*input == '/')
            type = CMD_ABSOLUTE;
        input++;
    }
    return type;
}
