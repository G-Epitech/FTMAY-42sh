/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** display
*/

#include <stdio.h>
#include "types/cmd/cmd.h"

static void display_args(args_t *args)
{
    printf("args: {\n\t\targc: %d\n\t\targv: [", args->argc);
    for (int i = 0; i < args->argc; i++) {
        if (i + 1 == args->argc)
            printf("%s", args->argv[i]);
        else
            printf("%s, ", args->argv[i]);
    }
    printf("]\n\t}\n\t");
}

static void display_type(cmd_type_t type)
{
    switch (type) {
        case CMD_ABSOLUTE:
            printf("absolute");
            break;
        case CMD_BUILTIN:
            printf("builtin");
            break;
        case CMD_EMPTY:
            printf("empty");
            break;
        case CMD_NULL:
            printf("null");
            break;
        case CMD_SYSTEM:
            printf("system");
            break;
        default:
            printf("unknown");
            break;
    }
}

void cmd_display(cmd_t *cmd)
{
    printf("\n-----\n{\n\tinput: [%s]\n\tname: [%s]\n\ttype: ",
    cmd->input, cmd->name);
    display_type(cmd->type);
    printf("\n\t");
    display_args(&cmd->args);
    if (cmd->type == CMD_SYSTEM || cmd->type == CMD_ABSOLUTE)
        printf("target: [%s]\n\t", cmd->target.path);
    printf("forked: %s\n}\n-----\n", cmd->forked ? "true" : "false");
}
