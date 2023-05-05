/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** execution
*/

#ifndef EXECUTION_H_
    #define EXECUTION_H_

    #include "types/node/defs.h"

/**
 * @brief Execute instruction from user input.
 * @param node Node from an instruction block
 * @param fd File descriptor pipe
 * @param level Level of block and priority
 */
void execution_inst(node_t *node, int fd[2], int level);

/**
 * @brief Execute block instruction.
 * @param node Node from instruction with type block
 * @param level Level of block and priority
 */
void execution_block(node_t *node, int level);

#endif /* !EXECUTION_H_ */
