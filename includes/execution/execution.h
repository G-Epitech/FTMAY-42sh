/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** executions
*/

#ifndef EXECUTION_H_
    #define EXECUTION_H_

    #include <stdio.h>
    #include "defs.h"
    #include "types/cmd/cmd.h"
    #include "types/node/defs.h"
    #include "types/shell/defs.h"

/**
 * @brief Execute main block.
 * @param block Block to execute
 * @param shell Shell object
 * @return Success status of execution
 */
bool execution_main_block(inst_t *block, shell_t *shell);

/**
 * @brief Initialize given utils based on parent if given.
 * @param utils Utils data to initialize
 * @param herited Herited utils execution data from parent or sibling
 * @param caller Type of instruction caller
 */
void execution_utils_init(exec_utils_t *utils, exec_utils_t *herited,
exec_caller_t caller);

/**
 * @brief Execute given node instruction of type command.
 * @param node_inst Node instruction
 * @param shell Shell object
 * @param utils Utils data of execution
 * @return Status of launching success
 */
bool execution_cmd_launch(node_t *node_inst, shell_t *shell,
exec_utils_t *utils);

/**
 * @brief Launch execution of an absolute command.
 * @param cmd Command to execute
 */
void execution_cmd_launch_absolute(cmd_t *cmd);

/**
 * @brief Launch execution of a builtin command.
 * @param cmd Command to execute
 * @param shell Shell object
 */
int execution_cmd_launch_builtin(cmd_t *cmd, shell_t *shell);

/**
 * @brief Display error on absolute command execution failure.
 * @param cmd Current command executed
 * @param error Error number
 */
void execution_cmd_display_error(cmd_t *cmd, int error);

/**
 * @brief Prepare execution of given command.
 * @param node_inst Node instruction
 * @param shell Shell object
 * @return Success status of preparing
 */
bool execution_cmd_prepare(node_t *node_inst, shell_t *shell);

/**
 * @brief Check if given command can be executed correctly.
 * @param cmd Command to execute
 * @return Status of feasibility
 */
bool execution_cmd_can_be_done(cmd_t *cmd);

/**
 * @brief Execute instruction from user input.
 * @param node_inst Node from an instruction block
 * @param shell Shell object
 * @param herited Herited utils execution data from parent or sibling
 * @param caller Type of instruction caller
 */
void execution_inst(node_t *node_inst, shell_t *shell, exec_utils_t *herited,
exec_caller_t caller);

/**
 * @brief Launch instruction execution.
 * @param node_inst Node from an instruction block
 * @param shell Shell object
 * @param utils Utils data of execution
 */
void execution_inst_launch(node_t *node_inst, shell_t *shell,
exec_utils_t *utils);

/**
 * @brief Launch execution of previous piped instruction.
 * @param node_inst Node instruction
 * @param shell Shell object
 * @param utils Utils data of execution
 */
void execution_inst_previous_piped(node_t *node_inst,
shell_t *shell, exec_utils_t *utils);

/**
 * @brief Check if fork is needed for currenr instruction.
 * @param node_inst Node instruction
 * @param utils Utils data of execution
 * @return Status of requirement
 */
bool execution_inst_fork_needed(node_t *node_inst, exec_utils_t *utils);

/**
 * @brief Launch instruction execution in a forked processus.
 * @param node_inst Node instruction
 * @param shell Shell object
 * @param utils Utils data of execution
 */
void execution_inst_launch_fork(node_t *node_inst, shell_t *shell,
exec_utils_t *utils);

/**
 * @brief Launch instruction execution without forked processus.
 * @param node_inst Node instruction
 * @param shell Shell object
 * @param utils Utils data of execution
 */
void execution_inst_launch_non_fork(node_t *node_inst, shell_t *shell,
exec_utils_t *utils);

/**
 * @brief Execute block instruction.
 * @param node Node from instruction with type block
 * @param shell Shell object
 * @param utils Utils data of execution
 * @return Status of execution success
 */
bool execution_block(node_t *node_inst, shell_t *shell, exec_utils_t *utils);

/**
 * @brief Set file descriptors of parent processus.
 * @param inst Current instruction
 * @param utils Utils data of execution
 */
void execution_inst_set_parent_fd(inst_t *inst, exec_utils_t *utils);

/**
 * @brief Set file descriptors of forked processus.
 * @param inst Current instruction
 * @param utils Utils data of execution
 */
void execution_inst_set_fd(inst_t *inst, exec_utils_t *utils);

/**
 * @brief Close file descriptors after execution.
 * @param utils Utils data of execution
 */
void execution_inst_close_fd(exec_utils_t *utils);

#endif /* !EXECUTION_H_ */