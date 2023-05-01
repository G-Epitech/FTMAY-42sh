/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** utils
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "parsing/utils.h"
#include "parsing/parsing.h"
#include "types/node/defs.h"

static void display_cmd(cmd_t *cmd)
{
    if (!cmd)
        return;
    printf("===== COMMAND =====\n");
    if (cmd->input)
        printf("Input: %s\n", cmd->input);
    if (cmd->name)
        printf("Name: %s\n", cmd->name);
    printf("Type: %d\n", cmd->type);
}

static void display_redirection(inst_t *instruction)
{
    printf("=== REDIRECTIONS ===\n");
    printf("Input Type: %d\n", instruction->ios.input.type);
    if (instruction->ios.input.path) {
        printf("Input Path: %s\n", instruction->ios.input.path);
    }
    printf("Output Type: %d\n", instruction->ios.output.type);
    if (instruction->ios.output.path) {
        printf("Output Path: %s\n", instruction->ios.output.path);
    }
}

static void display_block(inst_block_t *block)
{
    node_t *tmp = block->instructions->first;
    inst_t *data = NULL;

    while (tmp) {
        data = NODE_DATA_TO_PTR(tmp->data, inst_t *);
        if (data->type == INS_CMD) {
            display_cmd(data->value.cmd);
        }
        display_redirection(data);
        if (data->type == INS_BLOCK) {
            parsing_display(data);
        }
        tmp = tmp->next;
    }
}

void parsing_display(inst_t *instruction)
{
    if (!instruction)
        return;
    if (instruction->type == INS_BLOCK) {
        printf("======== BLOCK ========\n");
        if (instruction->ios.input.path)
            printf("Redirection: %s\n", instruction->ios.input.path);
        display_block(instruction->value.block);
    }
}

bool parsing_maybe_redirection(parsing_utils_t *utils)
{
    char *redirection[4] = {"<", "<<", ">>", ">"};
    char *data = utils->input + utils->index_parsing;

    for (int i = 0; i < 4; i++) {
        if (strncmp(redirection[i], data, strlen(redirection[i])) == 0)
            return true;
    }
    return false;
}
