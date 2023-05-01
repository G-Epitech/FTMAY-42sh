/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** inst
*/

#include <criterion/criterion.h>
#include "types/inst/inst.h"

Test(types_instruction, new_instruction)
{
    inst_t *instruction = inst_new();

    cr_assert(instruction != NULL);
    inst_free(instruction);
}

Test(types_instruction, new_field_instruction)
{
    inst_t *instruction = inst_new();

    cr_assert(instruction->value.block == NULL);
    cr_assert(instruction->value.cmd == NULL);
    cr_assert(instruction->type == INS_NONE);
    cr_assert(instruction->separator == SP_BREAK);
    cr_assert(instruction->exit_code == 0);
    cr_assert(instruction->ios.input.path == NULL);
    cr_assert(instruction->ios.input.type == IOT_DEFAULT);
    cr_assert(instruction->ios.output.path == NULL);
    cr_assert(instruction->ios.output.type == IOT_DEFAULT);
    cr_assert(instruction != NULL);
    inst_free(instruction);
}

Test(types_instruction, free_block_instruction)
{
    inst_t *instruction = inst_new();

    inst_free(instruction);
}

Test(types_instruction, free_cmd_instruction)
{
    inst_t *instruction = inst_new();

    instruction->type = INS_CMD;
    inst_free(instruction);
}

Test(types_instruction, free_null_instruction)
{
    inst_free(NULL);
}

