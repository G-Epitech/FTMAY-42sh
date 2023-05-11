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
 * @return Exit code of instruction
 */
int execution_inst(node_t *node_inst, shell_t *shell, exec_utils_t *herited,
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
 * @param inst Instruction on which check if fork is needed
 * @param utils Utils data of execution
 * @return Status of requirement
 */
bool execution_inst_fork_needed(inst_t *inst, exec_utils_t *utils);

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

/**
 * @brief Handle status at end of execution.
 * @param inst Current executed instruction
 * @param utils Utils data of execution
 * @return Success status of status handling
 */
bool execution_inst_handle_status(inst_t *inst, exec_utils_t *utils);

/**
 * @brief Get next block instruction to execute.
 * @param current Current node instruction
 * @param code Eexit code of previous instruction
 * @return Next node instruction or NULL if end reached
 */
node_t *execution_block_get_next(node_t *current, int code);

/**
 * @brief Check if immediate next instruction needs to be executed.
 * @param inst Current instruction
 * @param code Code produced by instruction evaluation
 * @return Needed status
 */
bool execution_block_need_next(inst_t *inst, int code);

/**
 * @brief Skip all not needed instructions until next required.
 * @param current Current node instruction
 * @return Next node to execute.
 */
node_t *execution_block_skip_not_needed(node_t *current);

#endif /* !EXECUTION_H_ */
