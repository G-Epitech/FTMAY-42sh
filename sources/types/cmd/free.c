/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** free
*/

#include <stdlib.h>
#include "types/cmd/defs.h"

void cmd_free(cmd_t *command)
{
    if (!command)
        return;
    free(command->input);
    free(command->name);
    free(command);
}
