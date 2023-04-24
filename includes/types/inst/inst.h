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
 * @brief Create a new instruction
 * @return inst_t* New instruction
 */
inst_t *inst_new(void);

/**
 * @brief Free an instruction
 * @param inst Instruction to free
 */
void inst_free(inst_t *inst);

/**
 * @brief Create a new block of instruction
 * @return inst_block_t* New block of instruction
 */
inst_block_t *inst_block_new(void);

/**
 * @brief Free a block of instruction
 * @param inst_block Block of instruction to free
 */
void inst_block_free(inst_block_t *inst_block);

#endif /* !INST_H_ */
