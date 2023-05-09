/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** redirections
*/

#ifndef EXECUTION_REDIRECTIONS_H_
    #define EXECUTION_REDIRECTIONS_H_

    #include "defs.h"

/**
 * @brief Get content to use in double redirection left.
 * @param word End word delimiter
 * @param fd File descriptor in which write
 */
void execution_redirection_get_input_double(char *word, int fd);

/**
 * @brief Get input redirection simple for current instruction.
 * @param inst Instruction of which get input redirection
 * @param fd File descriptor corresponding to reading head for instruction
 * @return Status of success
 */
bool execution_redirection_get_input_simple(inst_t *inst, int *fd);

/**
 * @brief Display error during redirection.
 * @param input Input file given
 * @param error Error number
 */
void execution_redirections_error(char *input, int error);

/**
 * @brief Get input redirection for current instruction.
 * @param inst Instruction of which get input redirection
 * @param fd File descriptor corresponding to reading head for instruction
 * @return Status of success
 */
bool execution_redirection_get_input(inst_t *inst, int *fd);

/**
 * @brief Get output redirection for current instruction.
 * @param inst Instruction of which get output redirection
 * @param fd File descriptor corresponding to writing head for instruction
 * @return Status of success
 */
bool execution_redirection_get_output(inst_t *inst, int *fd);

/**
 * @brief Get redirections for current instruction.
 * @param inst Instruction of which get output redirections
 * @param utils Utils data of execution
 * @return Status of success
 */
bool execution_inst_get_redirections(inst_t *inst, exec_utils_t *utils);

#endif /* !EXECUTION_REDIRECTIONS_H_ */
