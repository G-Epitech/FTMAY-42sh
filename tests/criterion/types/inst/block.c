/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** block
*/

#include <criterion/criterion.h>
#include "types/inst/inst.h"

Test(types_block_instruction, new_block_instruction)
{
    inst_block_t *instruction = inst_block_new();

    cr_assert(instruction != NULL);
}

Test(types_block_instruction, new_field_block_instruction)
{
    inst_block_t *instruction = inst_block_new();

    cr_assert(instruction->instructions == NULL);
    cr_assert(instruction != NULL);
}

Test(types_block_instruction, free_block_instruction)
{
    inst_block_t *instruction = inst_block_new();

    inst_block_free(instruction);
}

Test(types_block_instruction, free_null_block_instruction)
{
    inst_block_free(NULL);
}
