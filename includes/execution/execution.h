/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** executions
*/

#ifndef EXECUTION_H_
    #define EXECUTION_H_

    #include "types/node/defs.h"
    #include "types/shell/defs.h"

/**
 * @brief Execute given node instruction of type command.
 * @param node_inst Node instruction
 * @return Exit code of command
 */
int execution_cmd(node_t *node_inst, shell_t *shell);

/**
 * @brief Check if given command can be executed correctly.
 * @param cmd Command to execute
 * @param status Exit status pointer
 * @return Status of feasibility
 */
bool execution_cmd_can_be_done(cmd_t *cmd, int *status);

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
