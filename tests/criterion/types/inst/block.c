/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** block
*/

#include <criterion/criterion.h>
#include "utils/malloc2.h"
#include "types/cmd/cmd.h"
#include "types/inst/inst.h"
#include "types/list/list.h"

Test(types_block_instruction, new_block_instruction)
{
    inst_block_t *instruction = inst_block_new();

    cr_assert(instruction != NULL);
    inst_block_free(instruction);
}

Test(types_block_instruction, new_field_block_instruction)
{
    inst_block_t *instruction = inst_block_new();

    cr_assert(instruction->instructions != NULL);
    cr_assert(instruction != NULL);
    inst_block_free(instruction);
}

Test(types_block_instruction, new_block_with_malloc_fail)
{
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_FAIL);
    cr_assert_null(inst_block_new());
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_NORMAL);
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

Test(types_block_instruction, append_instruction)
{
    inst_block_t *instruction1 = inst_block_new();
    inst_t *instruction2 = inst_new();
    inst_t *instruction3 = NULL;
    node_data_t data = {NULL};

    inst_block_append(instruction1, instruction2);
    cr_assert(instruction1->instructions->len == 1);
    data = instruction1->instructions->first->data;
    instruction3 = NODE_DATA_TO_PTR(data, inst_t *);
    cr_assert(instruction3 == instruction2);
    inst_block_free(instruction1);
}

Test(types_block_instruction, append_instruction_with_malloc_fail)
{
    inst_block_t *instruction1 = inst_block_new();
    inst_t *instruction2 = inst_new();

    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_FAIL);
    inst_block_append(instruction1, instruction2);
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_NORMAL);
    cr_assert(instruction1->instructions->len == 0);
    inst_block_free(instruction1);
    inst_free(instruction2);
}

Test(types_block_instruction, append_instruction_null)
{
    inst_block_t *instruction1 = inst_block_new();
    inst_t *instruction2 = NULL;

    inst_block_append(instruction1, instruction2);
    cr_assert(instruction1->instructions->len == 0);
    inst_block_free(instruction1);
}

Test(types_block_instruction, append_instruction_in_null_block)
{
    inst_block_t *block = inst_block_new();
    inst_t *instruction = inst_new();

    instruction->value.block = block;
    instruction->type = INS_BLOCK;
    inst_block_append(NULL, instruction);
    inst_free(instruction);
}

Test(types_block_instruction, append_corrupted_instruction)
{
    inst_block_t *instruction1 = inst_block_new();
    inst_t *instruction2 = inst_new();

    instruction1->instructions = NULL;
    inst_block_append(instruction1, instruction2);
    inst_free(instruction2);
}
