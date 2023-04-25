/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** cmd
*/

#ifndef INST_H_
    #define INST_H_

    #include "defs.h"

/**
 * @brief Create a new instruction.
 * @return New instruction
 */
inst_t *inst_new(void);

/**
 * @brief Free an instruction.
 * @param inst Instruction to free
 */
void inst_free(inst_t *inst);

/**
 * @brief Free a instruction data.
 * @param data Instruction data to free
 */
void inst_node_freer(node_data_t data);

/**
 * @brief Create a new block of instruction.
 * @return New block of instruction
 */
inst_block_t *inst_block_new(void);

/**
 * @brief Free a block of instruction.
 * @param inst_block Block of instruction to free
 */
void inst_block_free(inst_block_t *inst_block);

/**
 * @brief Append a command in a block.
 * @param inst_block Block to append the command
 * @param instruction Command to append
 */
void inst_block_append(inst_block_t *inst_block, inst_t *instruction);

#endif /* !INST_H_ */
