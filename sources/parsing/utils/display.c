/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** display
*/

#include <stdio.h>
#include "parsing/utils.h"

static void printf_space(int index)
{
    for (int i = 0; i < index; i++)
        printf("   ");
}

static void display_cmd(cmd_t *cmd, int index)
{
    printf_space(index);
    printf("===== COMMAND =====\n");
    if (cmd->input) {
        printf_space(index);
        printf("Input: %s\n", cmd->input);
    }
    printf_space(index);
    printf("Type: %d\n", cmd->type);
}

static void display_redirection(inst_t *instruction, int index)
{
    printf_space(index);
    printf("=== REDIRECTIONS ===\n");
    printf_space(index);
    printf("Input Type: %d\n", instruction->ios.input.type);
    if (instruction->ios.input.path) {
        printf_space(index);
        printf("Input Path: %s\n", instruction->ios.input.path);
    }
    printf_space(index);
    printf("Output Type: %d\n", instruction->ios.output.type);
    if (instruction->ios.output.path) {
        printf_space(index);
        printf("Output Path: %s\n", instruction->ios.output.path);
    }
    printf("\n");
}

static void display_block(inst_block_t *block, int index)
{
    node_t *tmp = block->instructions->first;
    inst_t *data = NULL;

    while (tmp) {
        data = NODE_DATA_TO_PTR(tmp->data, inst_t *);
        if (data->type == INS_CMD) {
            display_cmd(data->value.cmd, index);
        }
        if (data->type == INS_BLOCK) {
            printf_space(index);
            printf("===== BLOCK =====\n");
            display_block(data->value.block, index + 1);
        }
            display_redirection(data, index);
        tmp = tmp->next;
    }
}

void parsing_display(inst_t *instruction)
{
    if (!instruction)
        return;
    if (instruction->type == INS_BLOCK)
        display_block(instruction->value.block, 0);
    if (instruction->type == INS_CMD) {
        display_cmd(instruction->value.cmd, 0);
        display_redirection(instruction, 0);
    }

}
