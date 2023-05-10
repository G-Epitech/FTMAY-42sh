/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** error
*/

#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include "errors/errors.h"
#include "types/cmd/cmd.h"

void execution_cmd_display_error(cmd_t *cmd, int error)
{
    char *msg = errors_strerror(error);

    if (error == ENOENT)
        msg = "Command not found.";
    fprintf(stderr, "%s: %s\n", cmd->name, msg);
}
